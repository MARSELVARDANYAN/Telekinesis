#include "../heders/Cell.h"

explicit Cell::operator int()
{
    return std::stoi(storage);
}

explicit Cell::operator double()
{
    return std::stod(storage);
}

const Cell& Cell::operator=(const Cell& rhv)
{
    if (this != &rhv)
    {
        storage = rhv.storage;
    }
        
}

const Cell& Cell::operator=(Cell&& rhv)
{
    if (this != &rhv)
    {
        storage = std::move(rhv.storage);
    }
}

Cell::Cell(){}

explicit Cell::Cell(int n)
{
    storage = n;
}

explicit Cell::Cell(double d)
{
    storage = d;
}

/*Cell::Cell(std::string str)
{
    storage = str;
}*/

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

std::ostream& operator<<(std::ostream& out, const Cell& rhv)
{     
        
        out << (rhv);
    
        return out;
}


std::istream& operator>>(std::istream& inp, const Cell& rhv)
{
    inp >> (rhv);

    return inp;
}
