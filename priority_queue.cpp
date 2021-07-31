#include "./priority_queue.h"
#define ARRAY_SIZE 3 // must be  >0

template <typename T>
Priority_queue<T>::~Priority_queue() { delete[] data;}

template <typename T>
size_t Priority_queue<T>::size(void) { return _size;}

template <typename T>
size_t Priority_queue<T>::capacity(void) { return _capacity;}

template <typename T>
bool Priority_queue<T>::empty(void) { return (_size == 0);}

/* 
This method doesn't delete any item, let them overwritten by push
*/
template <typename T>
void Priority_queue<T>::clear(void) { _size = 0;}

template <typename T>
void copy(T* to_be_copied, T* result, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        result[i] = to_be_copied[i];
    }
}

template <typename T>
void Priority_queue<T>::print(void) {
    // std::cout << "priority_queue: ";
    for (size_t i = 0; i < _size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

/*
The method reallocates space to make the data array double in memory
*/
template <typename T>
void Priority_queue<T>::resize(void) {
    if (_capacity == 0) { _capacity = ARRAY_SIZE;}

    T* tmp = data;
    _capacity *= 2;
    data = new T[_capacity];
    if (not data) {
        std::cout << "Sth went wrong in data allocation memory space" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    copy(tmp, data, _size);
}

template <typename T>
void Priority_queue<T>::heapify(void) {
    if (_size <= 1) {return;}

    size_t i = _size-1;
    while (((i-1)/2 < _size) & (data[i] > data[(i-1)/2])) {
        T tmp = data[i];
        data[i] = data[(i-1)/2];
        data[(i-1)/2] = tmp;

        i = (i-1)/2;
    }
}

template <typename T>
void Priority_queue<T>::push(const T& elem) {
    if (_capacity == _size) { this->resize();}
    data[_size] = elem;
    _size++;
    this->heapify();
}

template <typename T>
T Priority_queue<T>::top(void) { return data[0];}
