#include <iostream>
#include <list>
#include <vector>
namespace StackVector{
    template <typename _T> class Stack;

    template <typename _T>
    class Stack{
        public:
            Stack(){

            }
            bool is_empty() const{
                return this->m_data.empty();
            }
            void clear(){
                this->m_data.clear();
            }
            void push(const _T& el){
                this->m_data.push_back(el);
            }
            _T pop(){
                _T el = this->m_data.back();
                this->m_data.pop_back();
                return el;
            }
            const _T& top() const{
                return this->m_data.back();
            }
        private:
        std::list<_T> m_data;
    };
}

namespace StackList{
    template <typename _T> class Stack;
    template <typename _T>
    class Stack{
        public:
            void clear(){
                this->m_data.clear();
            }
            void push(const _T& el){
                this->m_data.push_back(el);
            }
            const _T& top() const{
                return this->m_data.back();
            }
            _T pop(){
                _T el = this->m_data.back();
                this->m_data.pop_back();
                return el;
            }
            bool is_empty() const{
                return this->m_data.empty();
            }
        private:
            std::vector<_T> m_data;
    };
}