#pragma once
#include <vector>
#include <iostream>

template<class T>
class TForwardList {
private:
    struct TNode {
        T value;
        TNode *next;
    };
    TNode *first;
    TNode *last;
    int sz;
public:
    TForwardList() {
        first = nullptr;
        last = nullptr;
        sz = 0;
    }
    //логичнее копировать вектор в том же порядке, поэтому проходимся с конца
    TForwardList(const std::vector<T>& vec) { 
        if (vec.size() > 0) {
            sz = vec.size();
            auto it = vec.rbegin();
            last = new TNode{*it, nullptr};
            first = last;
            it++;
            for(;it != vec.rend(); it++) {
                TNode *NewElem = new TNode{*it, nullptr};
                TNode *tmp = first;
                first = NewElem;
                NewElem->next = tmp->next;
            } 
        }
    }
    TForwardList(const TForwardList<T>& list) {
        sz = list.sz;
        TNode *tmp = list.first;
        TNode *NewElem = new TNode{tmp->value, nullptr};
        first = NewElem;
        last = first;
        tmp = tmp->next;
        for(; tmp != nullptr; tmp = tmp->next) {
            NewElem = new TNode{tmp->value, nullptr};
            last->next = NewElem;
            last = NewElem;
        }
    }
    void print() {
        TNode *tmp = first;
        for(;tmp != nullptr; tmp = tmp->next) {
            std::cout << tmp->value << "\t";
        }
        std::cout << std::endl;
    }
    void insert(const T& value) {
        TNode *NewElem = new TNode{value, nullptr};
        if (first == nullptr) {
            first = NewElem;
            last = NewElem;
        }
        else {
            last->next = NewElem;
            last = NewElem;
        }
        sz++;
    }
    void pop() {
        if (first != nullptr) {
            if (first->next == nullptr) {
                delete first;
                first = nullptr;
                last = nullptr;
                sz--;
                return;
            }
            TNode *tmp = first->next;
            delete first;
            first = tmp;
        }
    }
    TForwardList<T> operator=(const TForwardList<T>& list) {
        if (this == &list) return *this;        
        this->~TForwardList(); 
        sz = list.sz;
        TNode *tmp = list.first;
        TNode *NewElem = new TNode{tmp->value, nullptr};
        first = NewElem;
        last = first;
        tmp = tmp->next;
        for(; tmp != nullptr; tmp = tmp->next) {
            NewElem = new TNode{tmp->value, nullptr};
            last->next = NewElem;
            last = NewElem;
        }
        return *this;
    }
    T operator[](const int i) {
        if (i < 0 || i > sz) 
            throw i;
        TNode *tmp = first;
        T val = tmp->value;
        for(int j = 1; j <= i; j++) {
            tmp = tmp->next;
            val = tmp->value;
        }
        return val;
        
    }
    ~TForwardList() {
        if (first != nullptr) {
            TNode *tmp = first;
            TNode *nextmp = first->next;
            while (tmp != nullptr) {
                delete tmp;
                tmp = nextmp;
                if (nextmp != nullptr)
                    nextmp = nextmp->next;
            }
        }
    }
};
