#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <iostream>

template <typename T>
class Priority_queue {
    T* data = nullptr;
    size_t _size = 0; // the number of elements
    size_t _capacity = 0; // the number of elements that can be held in currently allocated storage

public:
    Priority_queue() = default;
    ~Priority_queue();

    size_t size(void);
    bool empty(void);
    void clear(void);

    T top(void);
    void push(const T& elem);
    T pop(void);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Priority_queue<U>& v);
};
#endif // PRIORITY_QUEUE_H