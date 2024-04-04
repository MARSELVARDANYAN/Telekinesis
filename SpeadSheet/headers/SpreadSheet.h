#ifndef __SPREADSHEET__
#define __SPREADSHEET__
#include "../headers/Cell.h"

class SpreadSheet
{
private:
    Cell** arr;
    std::size_t row;
    std::size_t col;

private:

    struct  SUBS
    {
        size_t x;
        size_t y;
    }obj;
    
public:
    SpreadSheet();
    SpreadSheet(size_t n);
    SpreadSheet(size_t row, size_t col);
    ~SpreadSheet();
    Cell& operator[](SUBS obj);
    const SpreadSheet& operator=(const SpreadSheet& rhv);
    const SpreadSheet& operator=(SpreadSheet&& rhv);


public:
    size_t get_row();
    size_t get_col();
    void add_row(size_t row, size_t col, std::string str);
    void add_colum(size_t row, size_t col, std::string str);
    void resize_row(size_t row);
    void resize_column(size_t col);
    void delete_row(size_t del_row);
    void delete_column(size_t del_col);
    void copy_from(size_t oth_row, size_t oth_col, const SpreadSheet& rhv);
    //SpreadSheet slice(size_t row, size_t col);

};

std::ostream& operator<<(std::ostream& out, SpreadSheet& rhv);
std::istream& operator>>(std::istream& inp, SpreadSheet& rhv);


#endif
