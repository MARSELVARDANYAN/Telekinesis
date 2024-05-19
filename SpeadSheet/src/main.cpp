#include <iostream>
#include "../headers/Cell.h"
#include "../headers/SpreadSheet.h"


int main() {
    
SpreadSheet ob(2, 2);

std::vector<int> v{33, 44, 55};


std::string i = "hy";
ob = 4;
ob[0][0] = v.front();
ob[0][1] = v[1];
ob[1][0] = v[2];
ob[1][1] = i;

double d = ob[0][1];

Cell ob1(65);

std::cout << ob[0][0] << std::endl;
std::cout << ob[0][1] << std::endl;
std::cout << ob[1][0] << std::endl;
std::cout << ob[1][1] << std::endl;

    return 0;
}