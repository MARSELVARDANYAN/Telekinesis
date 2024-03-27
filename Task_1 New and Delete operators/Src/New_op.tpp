#include "../Headers/New_op.hpp"
#include <iostream>

// Custom memory allocation function: Allocates memory of 'size' bytes
void* operator_new(size_t size)
{
    void *p = std::malloc(size);
    if (!p)
    {
        throw std::bad_alloc();
    }
    return p;
    
}

// Custom memory deallocation function: Deallocates memory allocated by operator_new
void operator_delete(void* pt)
{
    if (pt)
    {
        std::free(pt);
    }
    return;
}

// Custom new function: Allocates memory for a single object of type T and calls its constructor
template <typename T>
T* New(T val)
{
    void* p = ::operator_new(sizeof(T));
    T* ob = static_cast<T*>(p);
    *ob = val;
   
    new (ob) T;

    return ob;
}

// Custom new function for arrays: Allocates memory for an array of objects of type T and calls their constructors
template <typename T>
T* New_Arr(size_t i_size)
{
    void* p = ::operator_new(i_size * sizeof(T));
    T *t = static_cast<T*>(p);

    for (size_t i = 0; i < i_size; i++)
    {
        new (t + i) T;
    }
    return t;
}

// Custom delete function: Calls the destructor of the object and deallocates memory
template <typename T>
void Delete(T* in_p)
{
    if (in_p)
    {
        ::operator_delete(in_p);
        T::~T(in_p);
    }
    
}

// Custom delete function for arrays: Calls the destructors of the objects in the array and deallocates memory
template <typename T>
void Delete_Arr(T* in_p, size_t size)
{
    if (in_p)
    {
        for (size_t i = size - 1; i != -1 ; --i)
        {
            T::~T(in_p + i);
        }
        ::operator_delete(in_p);

    }
    
}