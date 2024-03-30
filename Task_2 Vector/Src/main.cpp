#include "../Headers/vector.h"
#include <iostream>


int main () 
{
   
    Vector<int> ob(std::move(Vector{9, 5}));
    Vector<int> ob1(5, 55);
    Vector<int> ob2(ob1);
    Vector<int> ob3{1, 2, 3, 4, 5, 6, 7};

    /*ob1.print();
    std::cout << std::endl;
    ob2.print();

    std::cout << std::endl;
    ob3.print();
    std::cout << std::endl;

    std::cout << ob3 << std::endl;
    */
    ob = std::move(ob3);
   
    ob3.print();

    return 0;
}
