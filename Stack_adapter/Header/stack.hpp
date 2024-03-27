#include "../Header/stack.h"

template <typename T, typename Container>
stack<T, Container>::stack()
    : ob()
{}


template <typename T, typename Container>
stack<T, Container>::stack(const stack& rhv)
    : ob(rhv.ob)
{}


template <typename T, typename Container>
stack<T, Container>::stack(stack&& other)
{   
    ob.clear();
    ob = other.ob;
    other.ob = {nullptr};
    
}


template <typename T, typename Container>
stack<T, Container>::stack(std::initializer_list<T> init)
{
    for (auto &i : init)
    {
        ob.push_back(i);
    }
    
}


template <typename T, typename Container>
const stack<T, Container>& 
stack<T, Container>::operator=(const stack<T, Container>& rhv)
{
    if (this != &rhv) {
        ob.clear();
        ob = (rhv.ob);
    }

    return *this;
    
    
}


template<typename T , typename Container>
stack<T,Container>& 
stack<T,Container>::operator=(stack&& rhv){
    if (this != &rhv) {        
        ob = std::move(rhv.ob);
    }

    return *this; 
}


template <typename T, typename Container>
stack<T, Container>::~stack()
{}


template <typename T, typename Container>
void 
stack<T, Container>::push(size_type elem)
{
    ob.push_back(elem);
}


template <typename T, typename Container>
void 
stack<T, Container>::pop()
{
    ob.pop_back();
}


template <typename T, typename Container>
typename stack<T, Container>::referance
stack<T, Container>::top()
{
    return ob.back();
}


template <typename T, typename Container>
typename stack<T, Container>::size_type
stack<T, Container>::Size()
{
    return ob.size();
}


template <typename T, typename Container>
void 
stack<T, Container>::swap(stack& other)
{
    std::swap(ob, other.ob);
}


template <typename T, typename Container>
bool 
stack<T, Container>::empty()
{
    return ob.empty();
}


//comparison operators
template <class T, class Container = std::vector<T>>
bool operator==(stack<T, Container>& lhv, stack<T, Container>& rhv)
{
    return lhv.Size() == rhv.Size();
}


template <class T, class Container>
bool operator!=(stack<T, Container>& lhv, stack<T, Container>& rhv)
{
    return lhv.Size() != rhv.Size();
}

template <class T, class Container>
bool operator>(stack<T, Container>& lhv, stack<T, Container>& rhv)
{
    return lhv.Size() > rhv.Size();
}

template <class T, class Container>
bool operator<(stack<T, Container>& lhv, stack<T, Container>& rhv)
{
    return lhv.Size() < rhv.Size();
}


template <class T, class Container>
bool operator<=(stack<T, Container>& lhv, stack<T, Container>& rhv)
{
    return lhv.Size() <= rhv.Size();
}


template <class T, class Container>
bool operator>=(stack<T, Container>& lhv, stack<T, Container>& rhv)
{
    return lhv.Size() >= rhv.Size();
}