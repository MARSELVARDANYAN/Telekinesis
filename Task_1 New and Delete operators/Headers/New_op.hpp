#ifndef _NEW__
#define _NEW__
#include <iostream>

// Custom memory allocation function: Allocates memory of 'size' bytes
void* operator_new(size_t size);

// Custom memory deallocation function: Deallocates memory allocated by operator_new
void operator_delete(void*);

// Custom new function: Allocates memory for a single object of type T and calls its constructor
template <typename T>
T* New(T);

// Custom new function for arrays: Allocates memory for an array of objects of type T and calls their constructors
template <typename T>
T* New_Arr(size_t);

// Custom delete function: Calls the destructor of the object and deallocates memory
template <typename T>
void Delete(T*);

// Custom delete function for arrays: Calls the destructors of the objects in the array and deallocates memory
template <typename T>
void Delete_Arr(T*, size_t);


#include "../Src/New_op.tpp"
#endif