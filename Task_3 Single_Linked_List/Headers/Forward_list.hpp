#ifndef __LINK_LIST__
#define __LINK_LIST__

#include <iostream>
#include <initializer_list>

template <typename T>
class LinkedList
{
  private:
      struct Node
      {
          T data;
          Node* next;
          Node(const T& val) : data(val), next(nullptr) {}// Parameterised constructor with default argument
          Node(T val, Node *tempNext): data(val),next(tempNext){}// Parameterise constructor
      };
      
      Node* head;
      size_t L_size{};

  public:
      using value_type = T;
      using size_type = size_t;
      using referance = value_type&;
      using const_referance = const value_type&;
      using pointer = value_type*;
      using const_pointer = const value_type*;

  public:
      LinkedList();
      LinkedList(std::initializer_list<T> initlist);
      LinkedList(const LinkedList<T>&);
      ~LinkedList();

  public:
      T& front();
      void displayList();
      size_t size();
      T& at(size_t);
      void push_back(const_referance);
      void pop_back();
      void push_front(const_referance);
      void pop_front();
      //void _swap(const LinkedList<T>& rhv);
      void insert(size_t  , const_referance );
      void erase(size_t);
      bool empty();
      void clear();
      
    
};

#include "Task_3 Single_Linked_List/Src/Forward_List.tpp"
#endif