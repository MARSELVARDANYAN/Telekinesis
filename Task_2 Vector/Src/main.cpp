#include "../Headers/vector.h"
#include <iostream>


int main() {
    Vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    vec.insert(vec.begin(), 10);  
    //vec.insert(20);


    for (int value : vec) {
        std::cout << value << " ";
    }

    std::cout << std::endl;
    return 0;
}

