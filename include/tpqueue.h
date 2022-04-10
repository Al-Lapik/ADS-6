// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[size];
    int first, last;

 public:
    TPQueue() : first(0), last(0) {}

    bool isFull() const {
        return last - first >= size;
    }

    bool isEmpty() const {
        return first == last;
    }

    void shift(int position) {
        for (int i = (last - 1) % size; i > position; i--) {
            if (arr[i - 1].ch != NULL) {
                arr[i ] = arr[i - 1];
            }
        }
    }

    void push(T value) {
        if (!isFull()) {
            if (isEmpty()) {
                arr[first % size] = value;
            } else if (value.prior > arr[first % size].prior) {
                shift(first % size);
                arr[first % size] = value;
            } else {
                int i = first;
                while (value.prior <= arr[i].prior)
                    i++;
                shift(i % size);
                arr[i % size] = value;
            }
            last++;
        } else {
            throw std::string("Queue is full");
        }
    }

    T pop() {
        if (!isEmpty()) {
            return arr[(first++) % size];
        } else {
            throw std::string("Queue is empty");
        }
    }
};
