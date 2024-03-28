#ifndef __QUEUE__
#define __QUEUE__
#include <vector>
#include <initializer_list>


template <typename T, typename Container = std::vector<T>>
class QUEUE
{
    private:
        Container ob;

    public:
        //Member types
        using value_type = T;
        using size_type = std::size_t;
        using referance = value_type&;
        using const_referance = const value_type&;
        using pointer = value_type*;
        using const_pointer = const pointer;


    public:
        //Member functions
        QUEUE();
        QUEUE(const QUEUE & rhv);
        QUEUE(QUEUE&& other);
        QUEUE(std::initializer_list<T> init);
        ~QUEUE();

    public:
        //Element access
        referance front();
        referance back();

    public:
        //Capasity
        bool empty();
        size_type size();

    public:
        //Modifiers
        void push(size_type elem);
        void push_range();
        void emplase();
        void pop();
        void swap(QUEUE&);

};

    //Non-member functions
    template <class T, class Container>
    bool operator==(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv);

    //Operator !=
    template <class T, class Container>
    bool operator!=(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv);

    //Operator >
    template <class T, class Container>
    bool operator>(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv);

    //Operator <
    template <class T, class Container>
    bool operator<(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv);


    //Operator <=
    template <class T, class Container>
    bool operator<=(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv);


    //Operator >=
    template <class T, class Container>
    bool operator>=(QUEUE<T, Container>& lhv, QUEUE<T, Container>& rhv);

    //operator<=>
  

#include "../Src/queue.cpp"

#endif

    
