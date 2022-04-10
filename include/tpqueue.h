// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template<typename T, int size>
class TPQueue {
 private:
    T arr[5];
    int first, last;

 public:
    TPQueue() : first(0), last(0) {}

    void push(T value) {
        int i = last;
        while (--i >= first && value.prior > (*(arr + i % size)).prior)
            *(arr + (i + 1) % size) = *(arr + i % size);
        *(arr + (i + 1) % size) = value;
        last++;
    }

    T pop() {
        return *(arr + (first++) % size);
    }
};

#endif  // INCLUDE_TPQUEUE_H_
