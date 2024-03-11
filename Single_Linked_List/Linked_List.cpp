#include "Lincked_list.hpp"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList()
    : head(nullptr)
    , L_size(0)
{}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhv)
    : head{nullptr}
    , L_size{0}
{
    if (rhv.head == nullptr) 
    {
        return;
    }
    Node* current = rhv.head;
    while(current != nullptr)
    {
        push_back(current->val);
        current = current->next;
    }
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> initlist) 
        : head{nullptr} 
        , L_size{0}
{
     for(const T& val : initlist)
     {
        push_back(val);
     }
}

template<typename T>
LinkedList<T>::~LinkedList() 
{
    clear();
}

template <typename T>
T& LinkedList<T>::front()
{
    if (!size())
    {
        throw 1;
    }
    return head->val;
}

template <typename T>
void LinkedList<T>::displayList()
{
    Node* current = this->head;
    while(current)
    {
        std::cout << current->val << "--->";
        current = current->next;
    }
    std::cout << std::endl; 
}   

template <typename T>
size_t LinkedList<T>::size()
{
    size_t size = 0; 
    Node* tmp = this->head;
    while (tmp)
    {
        tmp = tmp->next;
        ++size;
    }
    return size;
}

template <typename T>
T& LinkedList<T>::at(size_t index){
    size_t counter = 0;
    Node* current = this->head;

    while(current != nullptr) 
    {
        if (counter == index) 
        {
            return current->val;
        }
        current = current->next;
        ++counter;
    }
    
    throw std::out_of_range("Index out of range");
}

template <typename T>
void LinkedList<T>::push_back(const_referance)
{
    if (this->head == nullptr)
    {
        return;
    }
    if (this->head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else {
        Node* current = this->head;
        while(current->next->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    --L_size;
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if (this->head == nullptr)
    {
        return;
    }
    if (this->head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else {
        Node* current = this->head;
        while(current->next->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    --L_size;
}

template <typename T>
void LinkedList<T>::push_front(const_referance val)
{
    Node* newNode = new Node(val);
    newNode->next = this->head;
    head = newNode;
}

template <typename T>
void LinkedList<T>::pop_front()
{
    Node* tmp = this->head;
    tmp->next = this->head->next; 
    delete tmp; 
    tmp = nullptr;
}


template<typename T>
void LinkedList<T>::insert(size_t index , const_referance val)
{
    if (index >= L_size)
    {
        throw 1;
    }
    if (this->head == nullptr)
    {
        return;
    }
    if (index == 0)
    {
        push_front(val);
    } 
    else{
        Node* current = this->head; 
        if (current != nullptr)
        for (int i = 0; i < index - 1 && current != nullptr; ++i)
        {
             current = current->next; 
        }
        if (current != nullptr)
        {
            Node* temp = new Node(val);
            temp->next = this->head->next;
            this->head->next = temp; 
            ++L_size; 
        }
        else {
            throw 1;
        }
    }
}

template<typename T>
void LinkedList<T>::erase(size_t index){
    if (index >= L_size){
        throw 1;
    }

    if (index == 0){
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
        --L_size;
        return;
    }

    Node* current = this->head;
    for(size_t i = 0; i < index - 1; ++i){
        current = current->next;
    }
    Node* todelete = current->next;
    current->next = todelete->next;
    delete todelete;
    --L_size;
}

template <typename T>
bool LinkedList<T>::empty()
{
    return (L_size == 0);
}

template<typename T>
void LinkedList<T>::clear()
{
    while(!size()) 
    {
       
        pop_front();
    }
}

