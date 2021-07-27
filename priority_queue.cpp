#include "./priority_queue.h"

template <typename T>
Priority_queue<T>::~Priority_queue() {
    delete[] data;
}

template <typename T>
bool Priority_queue<T>::empty(void) {
    return (_size == 0);
}