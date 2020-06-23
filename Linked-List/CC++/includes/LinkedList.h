#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <memory>
template <typename _T> class Node;
template <typename _T> class NodeList;
template <typename _T> std::ostream& operator<<(std::ostream& out,const NodeList<_T> &n_list);

template<typename _T>
class Node{
    public:
    _T data{};
    Node<_T>* next;
    Node();
    ~Node(){
        delete next;
    }
    Node(_T data, Node<_T>* next = nullptr):data(data),next(next){}
};

template <typename _T>
class NodeList{
    private:
        Node<_T> *m_head;
        Node<_T> *m_tail;
        int m_count{};
    public:
        NodeList();
        bool is_empty();
        void addToFront(_T el);
        void append(_T el);
        void insert(int index,_T el);
        int length() const;
        ~NodeList(){
            delete m_head,m_tail;
        }
        friend std::ostream& operator<< <>(std::ostream& out, const NodeList<_T>&n_list);
};

template <typename _T>
std::ostream& operator<<(std::ostream &out, const NodeList<_T>&n_list){
    Node<_T>* tmp;
    tmp = std::move(n_list.m_head);
    while(tmp!=nullptr){
        out <<"|" <<tmp->data;
        tmp = tmp->next;
        if(tmp !=nullptr){
            out << "->";
        }
    }
    return out;
}
#endif