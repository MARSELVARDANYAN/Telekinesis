#ifndef __VECTOR__
#define __VECTOR__
//#include <iostream>
//#include <cstddef>
#include <initializer_list>

template <typename T>
class Vector
{
private:
    std::size_t v_size;
    std::size_t v_capacity;
    T* arr;

public:
    using value_type = T;
    using size_type = std::size_t;
    using referance = value_type&;
    using const_referance = const value_type&;
    using pointer = value_type*;
    using const_pointer = const pointer;

public:
    Vector();
    Vector(size_type);
    Vector(size_type, const_referance);
    Vector(const Vector&);
    Vector(std::initializer_list<value_type>);
    const Vector& operator=(const Vector&);
    ~Vector();

private:
    void re_cap(size_type);

public:
    size_type capacity();
    size_type size();
    referance front();
    referance back();
    bool empty();
    void print();

public:
    void push_back(const_referance);
    void pop_back();
    void re_size(size_type, const value_type);
    void insert(size_type, const_referance);
    referance at(size_type);
    void erase(size_type);
    void clear();

};


#include "Task_2 Vector/Src/vector.tpp"
#endif
