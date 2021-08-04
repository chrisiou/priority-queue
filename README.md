# Priority_queue

## Table of Contents

- [Description](#description)
- [Template parameters](#templateparameters)
- [Member functions](#memberfunctions)
    - [Element Access](#elementaccess)
    - [Capacity](#capacity)
    - [Modifiers](#modifiers)
- [Member Objects](#memberobjects)
- [Non-member functions](#nonmemberfunctions)

## Description

A priority queue (PQ) is a container adaptor that provides constant time lookup of the largest element, at the expense of logarithmic insertion and extraction. Working with a priority_queue is similar to managing a heap in some random access container, with the benefit of not being able to accidentally invalidate the heap.

## Template parameters <a id="templateparameters"></a>

- `T` the type of the stored elements.

## Member functions <a id="memberfunctions"></a>

- `constructor` *(public member function)*
- `destructor`  *(public member function)*
- `operator <<` *(public member function)* returns an output stream of the PQ's elements seperated by whitespace character

### Access <a id="elementaccess"></a>

- `top` *(public member function)* returns a copy of the first element

### Capacity <a id="capacity"></a>

- `size` *(public member function)* returns the number of elements
- `capacity` *(public member function)* returns the capacity of PQ container
- `empty` *(public member function)* checks whether the underlying container is empty
- `clear` *(public member function)* sets the existed elements as garbage values of the container and makes its size equals to 0
- `resize` *(private member function)* increases the available capacity og PQ

### Modifiers <a id="modifiers"></a>

- `push` *(public member function)* inserts element and sorts the underlying container
- `pop` *(public member function)* returns and removes the top element
- `bottom_up_heapify`*(private member function)* restoring heap order from bottom to top
- `top_down_heapify` *(private member function)* restoring heap order from top to bottom
- `bigger_family_member` *(private member function)* returns the index of the biggest node between parent and children

## Member objects <a id="memberobjects"></a>

- `data` *(private member object)* container
- `_size_` *(private member object)* number of elements in the container
- `_capacity` *(private member object)* container's capacity

## Non-member functions <a id="nonmemberfunctions"></a>

- `test_bottom_up_heapify` *(friend function)*
- `test_top_down_heapify` *(friend function)*
- `test_bigger_family_member_method` *(friend function)*

These functions are declared only in testing mode and they are used in order to have access in the private members of the PQ for testing them.
To use these functions, add `-DTESTING` as compiler flag.
