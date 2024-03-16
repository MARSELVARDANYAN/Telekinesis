#include "Task_2 Vector/Headers/vector.h"
#include <iostream>

int main () 
{
   
    Vector<int> ob(4);
    Vector<int> ob1(5, 55);
    Vector<int> ob2(ob1);
    Vector<int> ob3{1, 2, 3, 4, 5, 6, 7};

    ob1.print();
    std::cout << std::endl;
    ob2.print();

    std::cout << std::endl;
    ob3.print();

    return 0;
}
