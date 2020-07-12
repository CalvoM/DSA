#include "Queue.h"

template <typename _Q>
Queue<_Q>::Queue(){

}

template <typename _Q>
void Queue<_Q>::clear(){
    this->m_data.clear();
}

template <typename _Q>
void Queue<_Q>::enqueue(_Q el){
    this->m_data.push_back(el);
}

template <typename _Q>
_Q Queue<_Q>::dequeue(){
    _Q el = this->m_data.front();
    this->m_data.pop_front();
    return el;
}

template <typename _Q>
bool Queue<_Q>::isEmpty(){
    return this->m_data.empty();
}