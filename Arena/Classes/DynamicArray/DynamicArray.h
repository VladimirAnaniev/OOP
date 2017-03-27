#ifndef ARENA_DYNAMICARRAY_H
#define ARENA_DYNAMICARRAY_H

template <typename T>
class DynamicArray {
    T* elements;
    int length;

public:
    DynamicArray(int startLength = 0) : length(startLength) {
        this->elements = new T[length];
    }

    void add(T element);

};

#endif //ARENA_DYNAMICARRAY_H
