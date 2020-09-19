#include "includes/Stack.h"
#include <string.h>
#include <map>
#ifdef S_VECTOR
using namespace StackVector;
#else
using namespace StackList;
#endif
int main(int argc, char** argv){
    Stack<int> Remainders;
    std::map<int,char> digit_converter;
    std::map<int,char>::iterator conv_iter;
    char a = 'A';
    int num = 10;
    // For bases till 36
    while(a<='Z'){
        digit_converter[num] = a;
        a++;
        num++;
    }
    a='a';
    // For bases greater than 36 till base 62
    while (a <= 'z') {
      digit_converter[num] = a;
      a++;
      num++;
    }

    int number = std::stoi(std::string(argv[1]));
    int base = std::stoi(std::string(argv[2]));
    std::cout<<"Decimal: "<<number<<" Base: "<<base<<std::endl;
    int remainder=0;
    do{
        remainder = number%base;
        Remainders.push(remainder);
        number = number/base;
    }while (number != 0);
      while (!Remainders.is_empty()) {
          int rem = Remainders.pop();
          if (rem>=10){
              conv_iter = digit_converter.find(rem);
              std::cout<<conv_iter->second;
          }else std::cout<<rem;
    }
    std::cout<<std::endl;
    return 0;
}