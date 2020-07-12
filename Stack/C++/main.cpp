#include "includes/Stack.h"
#include <string>
#include <typeinfo>
#ifdef S_VECTOR
using namespace StackVector;
#else
using namespace StackList;
#endif
void calculator(char one, char two, int& carry, Stack<char>& res){
    int sum =0;
    int one_i = one - '0';
    int two_i = two - '0';
    sum = one_i + two_i +carry;
    std::string str_sum = std::to_string(sum);;
    if(str_sum.size()==1){
        res.push(str_sum[0]);        
        carry=0;
    }
    else{
        res.push(str_sum[1]);
        carry = str_sum[0] - '0';
    }
}
int main(int argc, char** argv){     
    Stack<char> stack_one;
    Stack<char> stack_two;
    Stack<char> stack_sum;
    int carry{0};
    std::string str_one = std::string(argv[1]);
    std::string str_two = std::string(argv[2]);
    std::cout<<"  "<<str_one<<std::endl;
    std::cout <<"+ "<<str_two << std::endl;
    auto iter_one{str_one.begin()};
    auto iter_two{str_two.begin()};
    while(*iter_one){
        stack_one.push(*iter_one);
        iter_one++;
    }
    while(*iter_two){
        stack_two.push(*iter_two);
        iter_two++;
    }
    while(!stack_two.is_empty() or !stack_one.is_empty()){
        char one = stack_one.is_empty()?'0':stack_one.pop();
        char two = stack_two.is_empty() ? '0' : stack_two.pop();
        calculator(one,two,carry,stack_sum);
    }
    if(carry>0){
        stack_sum.push(carry+'0');
    }
    int dash_length = str_one.size()>=str_two.size()?str_one.size():str_two.size();
    dash_length+=2;
    std::string dash(dash_length,'-');
    std::cout <<dash<<std::endl;
    std::cout<<" ";
    while(!stack_sum.is_empty()){
        std::cout<<stack_sum.pop();
    }
    std::cout << std::endl;
    std::cout << dash << std::endl;
}
