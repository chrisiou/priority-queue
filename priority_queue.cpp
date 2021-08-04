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
        std::cout << "Sth went wrong in data allocation memory space!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < _size; ++i) { data[i] = tmp[i];} // copy tmp to data
}

template <typename T>
void Priority_queue<T>::bottom_up_heapify(void) {
    if (_size <= 1) {return;}

    size_t i = _size-1; // at last decresion of i, it will wrap around close to the biggest unsigned int
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
    data[_size++] = elem;
    this->bottom_up_heapify();
}

template <typename T>
T Priority_queue<T>::top(void) {
    if (_size < 1) {
        std::cout << "Queue is empty! Nothing to return!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return data[0];
}

/*
Returns the index of the bigger family member between parent and child(ren)
- if parent is equal to one of its children, it returns the parent index
*/
template <typename T>
size_t Priority_queue<T>::bigger_family_member(size_t parent_i) {
    if (_size < 1) { 
        std::cout << "Queue is empty!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (parent_i > _size) {return parent_i;}
    if ((2*parent_i + 2 == _size) && (data[parent_i] < data[2*parent_i + 1])) { 
        return 2*parent_i + 1; // returned if parent has only one child which is larger
    }

    size_t bigger_child = parent_i;
    if (2*parent_i + 2 < _size) { // true, if parent node has two children
        if (data[2*parent_i + 1] < data[2*parent_i + 2]) { bigger_child = 2*parent_i + 2;}
        else { bigger_child = 2*parent_i + 1;}
    }

    if (data[parent_i] < data[bigger_child]) { return bigger_child;}
    return parent_i;
}

template <typename T>
void Priority_queue<T>::top_down_heapify(void) {
    if (_size <= 1) {return;}

    size_t parent = 0;
    size_t bigger_child = this->bigger_family_member(parent);
    while (data[parent] < data[bigger_child]) {
        T tmp = data[parent];
        data[parent] = data[bigger_child];
        data[bigger_child] = tmp;

        parent = bigger_child;
        bigger_child = this->bigger_family_member(parent);
    }
}

template <typename T>
T Priority_queue<T>::pop(void) {
    if (_size < 1) { 
        std::cout << "Queue is empty! No elements to pop!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    T root = this->top();
    data[0] = data[--_size];
    this->top_down_heapify();

    return root;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Priority_queue<T>& q) {
    for (size_t i = 0; i < q._size; ++i) { out << q.data[i] << " ";}
    return out;
}
