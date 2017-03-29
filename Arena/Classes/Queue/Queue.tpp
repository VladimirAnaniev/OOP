#include <iostream>
#include "Queue.h"

template<typename T>
Queue<T>::Queue(): first(nullptr), last(nullptr), size(0) {}

template<typename T>
T Queue<T>::push(T el) {
    element<T> *newEl = new element<T>;
    newEl->data = el;
    newEl->next = nullptr;

    if (this->isEmpty()) {
        this->first = this->last = newEl;
    } else {
        this->last->next = newEl;
        this->last = newEl;
    }

    this->size++;
    return el;
}

template<typename T>
T Queue<T>::pop() {
    if (this->isEmpty()) {
        T el;
        std::cerr<<"Pop on an empty queue!!";
        return el;
    } else {
        element<T>* first = this->first;

        this->first = first->next;
        T data = first->data;
        delete first;
        return data;
    }
}

template<typename T>
bool Queue<T>::isEmpty() {
    return this->first == nullptr;
}

template<typename T>
T Queue<T>::peek(){
    if (this->isEmpty()) {
        T el;
        std::cerr<<"Peek on an empty queue!!";
        return el;
    } else {
        return this->first->data;
    }
}

template<typename T>
Queue<T>::~Queue(){
    element<T>* el = this->first;
    while(el != nullptr) {
        element<T>* next = el->next;
        delete el;
        el = next;
    }
}