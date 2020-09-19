#include "utils.hpp"

int main(int argc,char** argv){
    char letter = argv[1][0];
    std::string s = std::string(argv[2]);
    bool check = charInString(letter,s);
    if(check){
        std::cout<<"Present\n\r";
        std::cout<<"Occurence :"<<countCharInString(letter,s)<<"\r\n";
        std::cout<<"Removed from string: "<<removeCharFromString(letter,s)<<"\r\n";
    }else{
        std::cout<<"Absent\r\n";
    }
}