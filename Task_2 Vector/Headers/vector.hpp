#include "vector.h"


//Constructors
template <typename T>
Vector<T>::Vector(): v_size(1), v_capacity(5), arr(nullptr){} //default constructor

template <typename T>
Vector<T>::Vector(size_type len)
    : v_size(len)
    , v_capacity(v_size * 2)
    , arr(new value_type[v_capacity])
{}

template <typename T>
Vector<T>::Vector(size_type len, const_referance val)
    : Vector(len)
{
    for (size_t i = 0; i < v_size; i++)
    {
        this->arr[i] = val;
    }
    
}

template <typename T>
Vector<T>::Vector(const Vector& rhv)
{
    this->v_size = rhv.v_size;
    this->v_capacity = rhv.v_capacity;
    this->arr = new value_type[rhv.v_capacity];
    for (size_t i = 0; i < v_size; i++)
    {
        this->arr[i] = rhv.arr[i];
    }
    
}

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> init)
    : Vector(0)
{
    for (const T &val : init)
    {
        push_back(val);
    }

}

template <typename T>
Vector<T>::Vector(Vector&& other)
{   
    //std::cout << "ctor" << std::endl;

    v_size = other.v_size;
    v_capacity = other.v_capacity;
    arr = other.arr;
    other.arr = {nullptr};
    
}

//Operator '=' for vector objects
template <typename T>
const Vector<T>& 
Vector<T>::operator=(const Vector& rhv)
{
    if (this != &rhv) {
        clear();
        this->v_size = rhv.v_size;
        this->v_capacity = rhv.v_capacity;
        this->arr = new value_type[rhv.v_capacity];
        for(size_t i = 0; i < v_size; ++i){
            this->arr[i] = rhv.arr[i];
        }
    }
    return *this;
}


template <typename T>
const Vector<T>& 
Vector<T>::operator=(Vector&& rhv)
{
    if (this == &rhv)
    {
        clear();
        v_size = rhv.v_size;
        v_capacity = rhv.v_capacity;
        arr = rhv.arr;
        rhv.arr = nullptr;
    }
    
    return *this;
}


template <typename T>
typename Vector<T>::referance
Vector<T>::operator[](size_type ind)
{
    return arr[ind];
}

//Destructor
template <typename T>
Vector<T>::~Vector()
{
    clear();
}

//private: re_cap member function.
template <typename T>
void 
Vector<T>::re_cap(size_type new_cap)
{
    this->v_capacity = new_cap * 2;
    pointer tmp;
    tmp = new value_type[v_capacity];
    for (size_t i = 0; i < v_size; i++)
    {
        tmp[i] = this->arr[i];
    }
    
    delete [] this->arr;
    this->arr = nullptr;
    this->arr = tmp; 

}

//Functions that change the contens of an array
template <typename T>
typename Vector<T>::size_type 
Vector<T>::capacity() const
{
    return this->v_capacity;
}

template <typename T>
typename Vector<T>::size_type
Vector<T>::size() const
{
    return this->v_size;
}

template <typename T>
typename Vector<T>::referance
Vector<T>::front()
{
    return this->arr[0];
}

template <typename T>
typename Vector<T>::referance
Vector<T>::back()
{
    this->arr[v_size-1];
}

template <typename T>
bool 
Vector<T>::empty() const
{
    if (v_size == 0) {
        return true;
    }
        return false;
}

template <typename T>
void 
Vector<T>::print()
{
    for (size_t i = 0; i < v_size; i++)
    {
        std::cout << this->arr[i] << " ";
    }
    
}

template <typename T>
void 
Vector<T>::push_back(const_referance val)
{
    if (v_capacity <= v_size + 1) {
        re_cap(v_size + 1);
    }
    this->arr[v_size] = val;
    this->v_size++;
}

template <typename T>
void 
Vector<T>::pop_back()
{
    if (v_size == 0) {
        throw 1;
    }
    
    this->v_size--;
}

template <typename T>
void 
Vector<T>::re_size(size_type new_size, const value_type val)
{
    if (new_size >= v_capacity) {
        re_cap(new_size);
    }
            
    for (size_t i = v_size; i < new_size; ++i)
    {
        this->arr[i] = val;
    }
    this->v_size = new_size;
       
}

template <typename T>
void 
Vector<T>::insert(size_type index, const_referance val)
{
    if (index >= v_size || index < 0) {
        std::cout << "There is no such index" << std::endl;
        return;
    }
    if (v_size + 1 == v_capacity) {
        re_cap(v_size + 1);
    }
            
    this->v_size += 1;
    for (size_t i = index + 1; i < v_size; ++i)
    {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[index] = val;
        
}

template <typename T>
typename Vector<T>::referance
Vector<T>::at(size_type index)
{
    if (index >= v_size) {
       throw 1;
    }
    
    return this->arr[index];

}

template <typename T>
void 
Vector<T>::erase(size_type index)
{
    if (index >= v_size || index < 0) {
        std::cout << "There is no such index" << std::endl;
        return;
    }
    for (size_t i = index; i < v_size; ++i)
    {
        this->arr[i] = this->arr[i + 1];
    } 
    --this->v_size;

}   

template <typename T>
void 
Vector<T>::clear()
{
    delete []arr;
    this->arr = nullptr;
    this->v_size = 0;
    this->v_capacity = 0;
}

template<typename T>
void Vector<T>::Swap(Vector<T>& ob)
{   
    std::swap(arr, ob.arr);
    std::swap(v_size, ob.v_size);
   
}


//Non member function
namespace std
{
    template <typename T>
    std::ostream& operator<<(std::ostream& out, Vector<T>& ob)
    {      
    
        for (size_t i = 0; i < ob.size(); i++)
        {
        
            out << ob[i] << ' ';
        }
    
        return out;
    }
} // namespace std




