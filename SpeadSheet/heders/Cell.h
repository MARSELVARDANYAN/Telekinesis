#ifndef __CELL__
#define __CELL__
#include <iostream>

class Cell
{
private:
    std::string storage;

public:
    explicit operator int();
    explicit operator double();
    operator std::string();
    const Cell& operator=(const Cell& rhv);
    const Cell& operator=(Cell&& rhv);
    Cell();
    explicit Cell(int n);
    explicit Cell(double d);
    Cell(std::string str);
    Cell(Cell&& rhv);
    Cell(const Cell& rhv);
    ~Cell();
};

std::ostream& operator<<(std::ostream& out, const Cell& rhv);
std::istream& operator>>(std::istream& inp, const Cell& rhv);


#endif