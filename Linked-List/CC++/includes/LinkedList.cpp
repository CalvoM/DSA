#include "LinkedList.h"
template <typename _T>
Node<_T>::Node(){
    this->next = nullptr;
}

template <typename _T>
NodeList<_T>::NodeList(){
    this->m_head = nullptr;
    this->m_tail = nullptr;
    this->m_count = 0;
}

template <typename _T>
bool NodeList<_T>::is_empty(){
    return m_head == nullptr;
}
template <typename _T>
void NodeList<_T>::addToFront(_T el){
    Node<_T>* tmp = new Node<_T>(el,this->m_head);
    this->m_head = tmp;
    if(this->m_tail == nullptr){//If first node in List
        this->m_tail = this->m_head;
    }
    this->m_count++;
}
template <typename _T>
void NodeList<_T>::append(_T el){
    if(!this->is_empty()){//if list of nodes exists
    Node<_T> *tmp = new Node<_T>(el);
     this->m_tail->next = tmp;
     this->m_tail = this->m_tail->next;
    }else{
        this->m_tail = this->m_head = new Node<_T>(el); 
    }
    this->m_count++;
}
template <typename _T>
int NodeList<_T>::length() const{
    return this->m_count;
}
template <typename _T>
void NodeList<_T>::insert(int index,_T el){
    if(index >= this->m_count or index < 0){
        std::cout<<"Check your index!"<<std::endl;
        return;
    }
    if(index == 0){//if add to first position
        this->addToFront(el);
        return;
    }
    else if(index == (this->m_count - 1)){//if add to last position
        this->append(el);
        return;
    }
    else{
    int _index = 0;
    Node<_T> *tmp = this->m_head;
    while(_index++!=(index-1)){ //Get the one just before
        tmp = tmp->next;
    }
    Node<_T> *_tmp = new Node<_T>(el,tmp->next);
    tmp->next = _tmp;
    }
    this->m_count++;
}
template class NodeList<const char*>;
template class Node<const char*>;
template class NodeList<int>;
template class Node<int>;
template class NodeList<std::string>;
template class Node<std::string>;