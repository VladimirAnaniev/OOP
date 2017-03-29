#ifndef ARENA_QUEUE_H
#define ARENA_QUEUE_H

template<typename T>
struct element {
    T data;
    element* next;
};

template<typename T>
class Queue {
    element<T>* first;
    element<T>* last;
    int size;

    bool isEmpty();

public:
    Queue();

    T push(T element);

    T pop();

    T peek();

    ~Queue();
};

#include "Queue.tpp"

#endif //ARENA_QUEUE_H
