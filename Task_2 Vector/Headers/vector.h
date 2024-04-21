#ifndef __VECTOR__
#define __VECTOR__
#include <iostream>
//#include <cstddef>
#include <initializer_list>

template <typename T>
class Vector
{
private:
    
    class Allocator
    {   
    public:
        T* ptr = nullptr;
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = size_t;
    
    public:
        Allocator() = default;
        Allocator(const Allocator& rhv) = default;
        ~Allocator() = default;

    public:
    
        pointer allocate(size_type count)
        {
            ptr = ::operator new(count);
    
        }

        void constract(T* ptr)
        {
            ptr = new (ptr) T;
        }

        void deallocate(void* ptr, size_type){}

        void destroy(T* ptr)
        {
            std::destroy(ptr);
        }

    
        std::size_t max_size();
    
    };

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
    Vector(std::initializer_list<value_type> init);
    Vector(Vector&& other);
    const Vector& operator=(const Vector& rhv);
    const Vector& operator=(Vector&& rhv);
    referance operator[](size_type ind);
    ~Vector();

private:
    void re_cap(size_type);

public:
    size_type capacity() const;
    size_type size() const;
    referance front();
    referance back();
    bool empty() const;
    void print();

public:
    void push_back(const_referance);
    void pop_back();
    void re_size(size_type, const value_type);
    void insert(size_type, const_referance);
    referance at(size_type);
    void erase(size_type);
    void clear();
    void Swap(Vector& ob);

};


namespace std
{
    template <typename T>
    std::ostream& operator<<(std::ostream& out, Vector<T>& ob);
} // namespace std


#include "../Headers/vector.hpp"
#endif
