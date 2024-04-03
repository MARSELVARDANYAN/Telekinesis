/*#ifndef __SPREADSHEET__
#define __SPREADSHEET__
#include "Cell.h"

class SpreadSheet
{
private:
    Cell** ob;
    struct subs
    {
        int x;
        int y;
    };
    
public:
    SpreadSheet(int n);
    SpreadSheet(int n, int m);
    ~SpreadSheet();

public:
    void add_row(int n, double d, std::string str);
    void add_colum(int n, double d, std::string str);
    void resize_roe(int n);
    void resize_column(int n);
    void delete_row(int n);
    void delete_column(int n);
    void copy_from(int n, int m, const SpreadSheet& rhv);
    //SpreadSheet slice(size_t n, size_t m);


};




#endif
*/