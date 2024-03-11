#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>

template <typename T>
class Vector
{
private:
    size_t v_size;
    size_t v_capacity;
    T* arr;

public:
    using value_type = T;
    //using size_type = size_t;
    using referance = T&;
    using const_referance = const T&;
    //using pointer = T*;
    using const_pointer = const T*;

public:
    Vector();
    Vector(size_t);
    Vector(size_t, const_referance);
    Vector(const Vector&);
    const Vector& operator=(const Vector& rhv);
    ~Vector();

private:
    void re_cap(size_t);

public:
    size_t capacity();
    size_t size();
    T& front();
    T& back();
    bool empty();
    void print();

public:
    void push_back(const_referance);
    void pop_back();
    void re_size(size_t, const value_type);
    void insert(size_t, const_referance);
    T& at(size_t);
    void erase(size_t);
    void clear();

};


#include "vector.cpp"
#endif