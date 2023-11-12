#include "readCsv.h"
#include <iostream>

std::vector<std::string> tokenizer(std::string str,char ch) {
  std::istringstream var(str); 
  std::vector<std::string> v; 
  std::string t; while(getline((var), t, (ch))) v.push_back(t); 
  return v;
}

std::pair<bool, std::vector<std::string>> readCsv(std::string name){
	char ch;
  std::ifstream file;
	file.open(name, std::ios::in);
	if(!file){
    std::cout<<"Error in opening friends.txt"<<std::endl;
		return {0, {}};
	}
  std::string out=""; while (!file.eof()) file >> std::noskipws >> ch, out+=ch;
  out = out.substr(0, out.length() - 2);
	file.close();
  std::vector<std::string> v = tokenizer(out, ',');
  return {1, v};
}
