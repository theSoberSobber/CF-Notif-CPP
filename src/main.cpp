#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <iostream>
#include <vector>
#include <map>
#include "popup.h"
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
    if(i["creationTimeSeconds"].template get<int>() >= lastTime[user] && startTime - i["creationTimeSeconds"].template get<int>() <= threshold){
      popup(user, i["problem"]["name"].template get<std::string>(), 1);
      lastTime[user] = i["creationTimeSeconds"].template get<int>();
    }
  }
};

int main(){
  while(1){
    for(std::string i: handles) monitor(i);
    #ifdef DEBUG
    break;
    #endif
    Sleep(2000);
  }
  return 0;
}
