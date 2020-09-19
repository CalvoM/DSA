#ifndef UTILS_H_
#define UTILS_H_
#include <iostream>
#include <string>

bool charInString(char c, std::string s){
    if(s.length()!=0){
        if(s[0]!=c) 
            return charInString(c,s.substr(1));
        else 
            return true;
    }else{
        return false;
    }
}

int countCharInString(char c, std::string s){
  if (s.length() != 0) {
      return int(s[0]==c) + countCharInString(c, s.substr(1));
  } else {
    return 0;
  }
}
std::string removeCharFromString(char c, std::string s){
  if (s.length() != 0) {
    if(s[0]==c){
        return removeCharFromString(c,s.substr(1));
    }else{
        return s.substr(0,1)+removeCharFromString(c,s.substr(1));
    }
  } else {
    return "";
  }
}
#endif