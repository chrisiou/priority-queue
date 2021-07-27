#include "./priority_queue.h"

template <typename T>
Priority_queue<T>::~Priority_queue() {
    delete[] data;
}

template <typename T>
size_t Priority_queue<T>::size(void) {
    return _size;
}

template <typename T>
bool Priority_queue<T>::empty(void) {
    return (_size == 0);
}

/* 
The method doesn't delete any item, let them overwritten by push
*/
template <typename T>
void Priority_queue<T>::clear(void) {
    _size = 0;
}

template <typename T>
T Priority_queue<T>::top(void) {
    return data[0];
}
