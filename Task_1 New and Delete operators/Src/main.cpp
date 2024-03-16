#include <iostream>
#include "Task_1 New and Delete operators/Headers/New_op.hpp"


int main ()
{   
   
    char* p;
    p = New('h');
    //std::cout << *p << std::endl;
    *p = 55;
    //std::cout << *p << std::endl;

    char *r = New_Arr<char>(5);
    for (size_t i = 0; i < 5; i++)
    {
        std::cin >> r[i];

    }
    
    return 0;
}