#include "../Header/stack.h"
#include <iostream>

int main() 
{
    stack<int, std::vector<int>> ob{1, 2, 3};

    stack<int, std::vector<int>> ob1(ob);

    stack<int, std::vector<int>> ob2 = (stack{1, 5, 5, 2});

    stack<int, std::vector<int>> ob4{9, 7, 8, 9};

    bool i = (ob1 < ob2);
    

    std::cout << i << std::endl;
    std::cout << std::endl;
}