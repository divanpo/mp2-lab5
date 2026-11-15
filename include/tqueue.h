//#include <iostream>
#pragma once
#include "forwardlist.h"

template<typename T>
class TQueue {
private:
    TForwardList<T> list;
    size_t size;
    size_t max_size;
public:
    TQueue(int n) {
        size = 0;
        max_size = n;
    }
    void push(const T& value) {
        if (!isFull()){
            list.insert(value); 
            ++size;
        }
    }
    void pop() {
        if (!isEmpty()) {
            list.pop(); 
        }
    }
    bool isEmpty() { return this->size == 0; }
    bool isFull() { return this->size == max_size; }
    T top() {
        if (!isEmpty())
            return list[0];
        throw 0;
    }
};
