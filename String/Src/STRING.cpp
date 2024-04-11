#include "../Header/STRING.h"

STRING::STRING()
    : str{nullptr}
    , sz{}
    , cap{}
{}

STRING::STRING(const STRING& other)
{
    sz = other.sz;
    cap = other.cap;
    str = new char [other.cap];
}

STRING::STRING(STRING&& other) noexcept
{
    sz = std::move(other.sz);
    cap = std::move(other.cap);
    str = other.str;
    other.str = nullptr;
}

STRING& STRING::operator=(const STRING& str)
{
    
}

STRING& STRING::operator=(const char* s)
{
    
}

STRING& STRING::operator=(char s)
{
    
}

STRING& STRING::operator=(std::initializer_list<char> il)
{
    
}

STRING& STRING::operator=(STRING&& str) noexcept
{
    
}

STRING& STRING::assign (const STRING& str)
{

}

STRING& STRING::assign (const STRING& str, size_type subpos, size_type sublen = npos)
{

}
    
STRING& STRING::assign (const char* s)
{

}
    
STRING& STRING::assign (const char* s, size_type n)
{

}	

STRING& STRING::assign (size_type n, char c)
{

}

STRING& STRING::assign (std::initializer_list<char> il)
{

}	

STRING& STRING::assign (STRING&& str) noexcept
{

}