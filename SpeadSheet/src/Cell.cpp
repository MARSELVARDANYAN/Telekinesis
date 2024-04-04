#include "../headers/Cell.h"
#include <iostream>

Cell::operator int()
{
    return std::stoi(storage);
}

Cell::operator double()
{
    return std::stoi(storage);
}

Cell::operator std::string()
{
    return static_cast<Cell>(storage);
}

const Cell& Cell::operator=(const Cell& rhv)
{
    if (this != &rhv)
    {
        storage = rhv.storage;
    }
        return *this;
}

const Cell& Cell::operator=(Cell&& rhv)
{
    if (this != &rhv)
    {
        storage = std::move(rhv.storage);
    }

    return *this;
}

Cell::Cell(){}

Cell::Cell(int n)
{
    storage = n;
}

Cell::Cell(double d)
{
    storage = d;
}

Cell::Cell(std::string str)
{
    storage = str;
}

Cell::Cell(Cell&& rhv)
{
    storage = std::move(rhv.storage);
}

Cell::Cell(const Cell& rhv)
{
    storage = rhv.storage;
}

Cell::~Cell()
{}

std::ostream& operator<<(std::ostream& out, Cell& rhv)
{     
        
       out << std::stod(rhv);
      return out;  
}


std::istream& operator>>(std::istream& inp, Cell& rhv)
{   
    
    inp >> rhv;

    return inp;
}
