#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <list>
template <typename _Q> class Queue;
template <typename _Q>
class Queue{
public:
    Queue();
    void enqueue(_Q el);
    _Q dequeue();
    bool isEmpty();
    void clear();
private:
    std::list<_Q> m_data;
};
#endif