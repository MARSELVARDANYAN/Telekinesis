#include "../headers/Cell.h"

std::ostream& operator<<(std::ostream& out, const std::vector<int>& ob)
{   
    for (auto &i : ob) {
        out << i << ' ';
    }
    return out;
}

std::istream& operator>>(std::istream& in, std::vector<int>& ob)
{   
    ob.clear();
    int tmp{};
    while (in >> tmp) {
        ob.push_back(tmp);
    }
    return in;
}

Cell::Cell()
: str{}
{}

Cell::Cell(const Cell& rhv)
    : str(rhv.str)
{}

Cell::Cell(Cell&& rhv)
    : str(std::move(rhv.str))
{}

Cell::Cell(int val)
    : str(std::to_string(val))
{}

Cell::Cell(double val)
    : str(std::to_string(val))
{}

Cell::Cell(char val)
    : str(std::to_string(val))
{}


Cell::Cell(bool val)
{
    str = (val == true) ? "true" : "false";
}

Cell::Cell(std::string val)
    : str(val)
{}

Cell::Cell(const std::vector<int>& val)
{
    std::stringstream word;
    for (const auto& elem : val) {
        word << elem << ' '; 
    }
    str = word.str();
}

const Cell& Cell::operator=(const Cell& rhv)
{
    if (this != &rhv) {
        str = rhv.str;
    }
    return *this;
}

const Cell& Cell::operator=(Cell&& rhv)
{
    if (this != &rhv) {
        str = std::move(rhv.str);
    }
    return *this;
}

const Cell& Cell::operator=(int rhv)
{
    str = std::to_string(rhv);
    return *this;
}

const Cell& Cell::operator=(double rhv)
{
    str = std::to_string(rhv);
    return *this;
}

const Cell& Cell::operator=(char rhv)
{
    str = std::to_string(rhv);
    return *this;
}

const Cell& Cell::operator=(bool rhv)
{
    str = (rhv == true) ? "true": "false";
    return *this;
}

const Cell& Cell::operator=(std::string rhv)
{
    str = rhv;
    return *this;
}

const Cell& Cell::operator=(const std::vector<int>& rhv)
{
    std::stringstream word;
    for (const auto& elem : rhv) {
        word << elem << ' '; 
    }
    str = word.str();
    return *this;
}

Cell::operator int() const
{
    return std::stoi(str);
}

Cell::operator double() const
{
    return std::stod(str);
}

Cell::operator char() const
{
    if (str.empty()) {
        return '\0'; 
    }
    return str[0];
}

Cell::operator bool() const
{
    return !str.empty();
}

Cell::operator std::string() const
{
    return str;
}

Cell::operator std::vector<int>() const
{
    std::vector<int> vec;
    vec.push_back(std::stoi(str));
    return vec;
}

bool operator==(const Cell& lhv, const Cell& rhv)
{
    // std::string lhs = lhv;  //.operator std::string();
    // std::string rhs = rhv;  //.operator std::string();
    // return lhs == rhs;
    return (lhv.operator std::string() == rhv.operator std::string());
}

bool operator!=(const Cell& lhv, const Cell& rhv)
{
    std::string lhs = lhv;//.operator std::string();
    std::string rhs = rhv;//.operator std::string();
    return lhs != rhs;
}

std::ostream& operator<<(std::ostream& out, const Cell& rhv)
{            
    out << rhv.operator std::string();
    return out;  
}


std::istream& operator>>(std::istream& inp, Cell& rhv)
{   
    std::string tmp;
    inp >> tmp;
    rhv.operator=(tmp);
    return inp;
}
