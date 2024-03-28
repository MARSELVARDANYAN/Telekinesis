
#include "../Headers/queue.h"

template <typename T, typename Container>
QUEUE<T, Container>::QUEUE()
    : ob()
{}

template <typename T, typename Container>
QUEUE<T, Container>::QUEUE(const QUEUE<T, Container>& rhv)
    : QUEUE()
{
    this->ob = rhv.ob;
}

template <typename T, typename Container>
QUEUE<T, Container>::QUEUE(QUEUE && other)
{   

    other = ob;
    other = nullptr;

}

template <typename T, typename Container>
QUEUE<T, Container>::QUEUE(std::initializer_list<T> init)
    : QUEUE()
{
    for (auto &i : init)
    {
        ob.push_back(i);
    }
    
}

template <typename T, typename Container>
QUEUE<T, Container>::~QUEUE()
{}

template <typename T, typename Container>
void 
QUEUE<T, Container>::push(size_type elem)
{
    ob.push_back(elem);
}

template <typename T, typename Container>
void 
QUEUE<T, Container>::pop()
{
    ob.erase(0);//
}

template <typename T, typename Container>
typename QUEUE<T, Container>::referance
QUEUE<T, Container>::front()
{
    return ob.front();
}

template <typename T, typename Container>
typename QUEUE<T, Container>::referance
QUEUE<T, Container>::back()
{
    return ob.back();
}

template <typename T, typename Container>
typename QUEUE<T, Container>::size_type
QUEUE<T, Container>::size()
{
    return ob.size();
}

template <typename T, typename Container>
void 
QUEUE<T, Container>::swap(QUEUE & rhv)
{
    std::swap(ob, rhv);
}

template <typename T, typename Container>
bool 
QUEUE<T, Container>::empty()
{
    return ob.empty();
}



//Non-member functions
//Operator ==
template <class T, class Container = std::vector<T>>
bool 
operator==(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv)
{
    return lhv.Size() == rhv.Size();
}

//Operator !=
template <class T, class Container>
bool 
operator!=(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv)
{
    return lhv.Size() != rhv.Size();
}

//Operator >
template <class T, class Container>
bool 
operator>(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv)
{
    return lhv.Size() > rhv.Size();
}

//Operator <
template <class T, class Container>
bool 
operator<(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv)
{
    return lhv.Size() < rhv.Size();
}

//Operator <=
template <class T, class Container>
bool 
operator<=(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv)
{
    return lhv.Size() <= rhv.Size();
}

//Operator >=
template <class T, class Container>
bool 
operator>=(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv)
{
    return lhv.Size() >= rhv.Size();
}