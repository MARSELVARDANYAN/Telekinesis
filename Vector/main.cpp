#include "vector.hpp"
#include <iostream>

int main () 
{
    Vector<int>ob(4);
    Vector<int>ob1(5, 55);
    Vector<int>ob2(ob);

    ob1.print();
    std::cout << std::endl;
    ob1.print();

    
}
