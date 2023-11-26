#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <iostream>
#include <vector>
#include <map>
#include "popup.h"
#include "readCsv.h"

using json = nlohmann::json;

#include "config.h"

auto fetch = [](std::string user){
  while(1){
    cpr::Response r = cpr::Get(cpr::Url{"https://codeforces.com/api/user.status?handle="+user+"&from=1&count=10"});
    if(r.status_code==200) return r.text;
    Sleep(1000);
  }
};

std::map<std::string, int> lastTime;

auto monitor = [](std::string user){
  auto r = fetch(user);
  int startTime = time(NULL);
  json res = json::parse(r);
  assert(res["status"]=="OK");
  reverse(res["result"].begin(), res["result"].end());
  for(auto i: res["result"]){
    if(i["creationTimeSeconds"].template get<int>() > lastTime[user] && startTime - i["creationTimeSeconds"].template get<int>() <= threshold){
      if(i["verdict"].template get<std::string> () == "TESTING") continue;
      std::string url = "https://codeforces.com/contest/" + std::to_string(i["problem"]["contestId"].template get<int>()) + "/problem/" + i["problem"]["index"].template get<std::string>();
      std::string dialogText = i["problem"]["name"].template get<std::string>() + " : " + i["verdict"].template get<std::string>()+ ", " + std::to_string(i["problem"]["points"].template get<int>());
      #ifdef DEBUG
      std::cout<<user<<std::endl;
      std::cout<<i["creationTimeSeconds"] << " " << lastTime[user] << " " << startTime << std::endl;
      std::cout<<url<<std::endl;
      #endif
      popup(user, dialogText.data(), url.data(), 1);
      lastTime[user] = i["creationTimeSeconds"].template get<int>();
    }
  }
};

int main(){
  std::pair<bool, std::vector<std::string>> res; 
  #ifdef DEBUG
  res = readCsv("friends-debug.txt");
  #else
  res = readCsv("friends.txt");
  #endif
  if(!res.first) return -1;
  std::vector<std::string> handles = res.second;
  #ifdef DEBUG
  for(std::string i: handles) std::cout<<i<<std::endl;
  #endif
  while(1){
    for(std::string i: handles) monitor(i);
    // #ifdef DEBUG
    // break;
    // #endif
    Sleep(2000);
  }
  return 0;
}
