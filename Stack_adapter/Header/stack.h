#ifndef __STACK__
#define __STACK__
#include <vector>
#include <initializer_list>

template <typename T, typename Container = std::vector<T>>
class stack
{
    private:
        Container ob;

    public:
        using value_type = T;
        using Container_type = Container;
        using size_type = std::size_t;
        using referance = value_type&;
        using const_referance = const value_type&;
       

    public:
        stack();
        explicit stack(const stack & rhv);
        explicit stack(stack&& other);
        stack(std::initializer_list<T> init);
        const stack<T, Container>& operator=(const stack<T, Container>& rhv);
        stack<T, Container>& operator=(stack<T, Container>&& rhv);
        ~stack();
        void push(size_type elem);
        void pop();
        value_type& top();
        size_type Size();
        void swap(stack& other);
        bool empty();
};


#include "../Header/stack.hpp"

#endif

