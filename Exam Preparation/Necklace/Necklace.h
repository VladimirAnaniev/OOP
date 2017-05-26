#ifndef EXAM_PREPARATION_NECKLACE_H
#define EXAM_PREPARATION_NECKLACE_H

#include <iosfwd>
#include <iostream>

static int CAPACITY = 20;

template<typename T>
class Necklace {
    T *arr;
    int size;

public:
    ////Constructor
    Necklace() : size(0) {
        this->arr = new T[CAPACITY];
    }

    /** Methods **/
    void insert(T element) {
        if (size >= CAPACITY) {
            std::cerr << "GRESHKA PICH!!!!" << std::endl;
            return;
        }

        int index = this->size / 2;
        this->operator>>=(index);
        this->arr[size++] = element;
        this->operator<<=(index);
    }

    int getSize() const {
        return this->size;
    }

    /** Operators **/
    const T &operator[](int index) const {
        return arr[index];
    }

    void operator>>=(int n) {
        T *newArr = new T[CAPACITY];

        for (int i = 0; i < n; i++) {
            newArr[i] = this->arr[this->size - n + i];
        }
        for (int i = n; i < this->size; i++) {
            newArr[i] = this->arr[i - n];
        }

        delete[] this->arr;
        this->arr = newArr;
    }

    void operator<<=(int n) {
        T *newArr = new T[CAPACITY];

        for (int i = n; i < this->size; i++) {
            newArr[i - n] = this->arr[i];
        }
        for (int i = 0; i < n; i++) {
            newArr[this->size - n + i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = newArr;
    }

    //// Destructor
    ~Necklace() {
        delete[] this->arr;
    }
};

template<typename T>
std::ostream &operator<<(std::ostream &os, Necklace<T> necklace) {
    for (int i = 0; i < necklace.getSize(); i++) {
        os << necklace[i] << ' ';
    }

    return os;
}


#endif //EXAM_PREPARATION_NECKLACE_H
