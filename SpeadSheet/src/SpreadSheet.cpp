#include "../headers/SpreadSheet.h"

SpreadSheet::SpreadSheet()
    : board(nullptr)
    , rowcnt{0}
    , colcnt{0}
{}

SpreadSheet::SpreadSheet(const SpreadSheet& rhv)
    : board{new Cell*[rhv.rowcnt]}
    , rowcnt{rhv.rowcnt}
    , colcnt{rhv.colcnt}
{
    for(size_t i = 0; i < rhv.rowcnt; ++i){
        board[i] = new Cell[colcnt];
    }
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhv)
{
    board = rhv.board;
    rowcnt = std::move(rhv.rowcnt);
    colcnt = std::move(rhv.colcnt);
    rhv.board = nullptr;
}

SpreadSheet::SpreadSheet(size_t size)
    : board(new Cell*[size])
    , rowcnt(size)
    , colcnt(size)
{
    for (size_t i = 0; i < size; i++){
        board[i] = new Cell[size];
    }

    
}

SpreadSheet::SpreadSheet(size_t row, size_t col)
    : board(new Cell* [row])
    , rowcnt{row}
    , colcnt{col}
{
    for (size_t i = 0; i < row; i++) {
        board[i] = new Cell[col];
    }
}

SpreadSheet::~SpreadSheet()
{}


const SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhv) 
{
    if (this != &rhv){
    
        clear();
        board = new Cell*[rhv.rowcnt];
        for (size_t i = 0; i < rhv.rowcnt; ++i) {
            board[i] = new Cell[rhv.colcnt];
        }

        for (size_t i = 0; i < rhv.rowcnt; i++) {
            for(size_t j = 0; j < rhv.colcnt; ++j) {
                board[i][j] = rhv.board[i][j];
            }
        }

        rowcnt = rhv.rowcnt;
        colcnt = rhv.colcnt;
    }
    
    return *this;
}


const SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv)
{
    if (this != &rhv) {
        clear();
        board = new Cell*[rhv.rowcnt];
        for (size_t i = 0 ; i < rhv.rowcnt; ++i){
            board[i] = new Cell[rhv.colcnt];
            for (size_t j = 0; j < rhv.colcnt; ++j) {
                board[i][j] = std::move(rhv.board[i][j]);
            }
        }
        
        rhv.clear();
        rowcnt = rhv.rowcnt;
        colcnt = rhv.colcnt;
        
    }
    return *this; 
}

SpreadSheet::Column SpreadSheet::operator[](size_t pos)
{   
    return Column(board[pos]);
}

const SpreadSheet::Column SpreadSheet::operator[](size_t pos) const
{
    return Column(board[pos]);
}

void SpreadSheet::clear() noexcept
{
    for(size_t i = 0; i < rowcnt; ++i)
    {
        delete[] board[i];
    }
    delete[] board;

}

size_t SpreadSheet::row() const 
{
    return rowcnt;
}

size_t SpreadSheet::col() const
{
    return colcnt;
}

void SpreadSheet::mirrorH()
{
    for(int i = 0; i < rowcnt/2; ++i)
    {
        for(int j = 0; j < colcnt; ++j)
        {
            Cell tmp = board[i][j];
            board[i][j] = board[rowcnt - 1 - i][j];
            board[rowcnt - 1 - i][j]  = tmp;
        }
    }
}

void SpreadSheet::mirrorV()
{
    rotate(2);
    mirrorH();
}

void SpreadSheet::mirrorD()
{
    rotate(3);
    mirrorH();
}

void SpreadSheet::mirrorSD()
{
    rotate(1);
    mirrorH();
}

void SpreadSheet::rotate(int count)
{
    int cnt = (count >= 0) ? (count % 4) : (4 - (-count % 4)) % 4;

    while (cnt--) {
        Cell** tmp = new Cell*[colcnt];
        for (int i = 0; i < colcnt; ++i) {
            tmp[i] = new Cell[rowcnt];
            for (int j = 0; j < rowcnt; ++j) {
                tmp[i][j] = board[rowcnt - 1 - j][i];
            }
        }

        size_t newRowCnt = colcnt;
        size_t newColCnt = rowcnt;

        clear();

        board = tmp;
        rowcnt = newRowCnt;
        colcnt = newColCnt;
    }
}


void SpreadSheet::removeRow(size_t row)
{
    if (row >= rowcnt) {
        throw 1;
    }

    for (size_t i = row; i < rowcnt - 1; ++i) {
        for (size_t j = 0; j < colcnt; ++j) {
            board[i][j] = board[i + 1][j];
        }
    }

    delete[] board[rowcnt - 1];
    board[rowcnt - 1] = nullptr;

    --rowcnt;
}

void SpreadSheet::removeRows(std::initializer_list<size_t> rows)
{
    std::vector<size_t> sortedRows(rows);
    std::sort(sortedRows.rbegin(), sortedRows.rend());

    for (size_t row : sortedRows) {
        if (row >= rowcnt) {
            throw 1;
        }

        for (size_t i = row; i < rowcnt - 1; ++i) {
            for (size_t j = 0; j < colcnt; ++j) {
                board[i][j] = board[i + 1][j];
            }
        }

        delete[] board[rowcnt - 1];
        board[rowcnt - 1] = nullptr;
        --rowcnt;
    }
}

void SpreadSheet::removeCol(size_t col)
{
    if (col >= colcnt) {
        throw 1;
    }

    for (size_t i = 0; i < rowcnt; ++i) {
        for (size_t j = col; j < colcnt - 1; ++j) {
            board[i][j] = board[i][j + 1];
        }

        board[i][colcnt - 1] = Cell();
    }

    --colcnt;
}

void SpreadSheet::removeCols(std::initializer_list<size_t> cols)
{
    std::vector<size_t> sortedCols(cols);
    std::sort(sortedCols.begin(), sortedCols.end(), std::greater<size_t>());

    for (size_t col : sortedCols) {
        if (col >= colcnt) {
            throw 1;
        }
        for (size_t i = 0; i < rowcnt; ++i) {
            for (size_t j = col; j < colcnt - 1; ++j) {
                board[i][j] = board[i][j + 1];
            }
            board[i][colcnt - 1] = Cell(); 
        }
        --colcnt;
    }
}

void SpreadSheet::resizeRow(size_t r)
{
    if (r == rowcnt) {
        return;
    }

    Cell** newBoard = new Cell*[r];
    for (size_t i = 0; i < r; ++i) {
        newBoard[i] = new Cell[colcnt];
    }

    size_t minRows = std::min(r, rowcnt);
    for (size_t i = 0; i < minRows; ++i) {
        for (size_t j = 0; j < colcnt; ++j) {
            newBoard[i][j] = board[i][j];
        }
    }

    for (size_t i = 0; i < rowcnt; ++i) {
        delete[] board[i];
    }
    delete[] board;

    board = newBoard;
    rowcnt = r;
}


void SpreadSheet::resizeCol(size_t c)
{
    if (c == colcnt) {
        return;
    }

    Cell** newBoard = new Cell*[rowcnt];
    for (size_t i = 0; i < rowcnt; ++i) {
        newBoard[i] = new Cell[c];
    }

    size_t minCols = std::min(c, colcnt);
    for (size_t i = 0; i < rowcnt; ++i) {
        for (size_t j = 0; j < minCols; ++j) {
            newBoard[i][j] = board[i][j];
        }
    }

    for (size_t i = 0; i < rowcnt; ++i) {
        delete[] board[i];
    }
    delete[] board;

    board = newBoard;
    colcnt = c;
}


void SpreadSheet::resize(size_t r, size_t c)
{
    Cell** newBoard = new Cell*[r];
    for (size_t i = 0; i < r; ++i) {
        newBoard[i] = new Cell[c];
    }

    size_t rowsToCopy = std::min(r, rowcnt);
    size_t colsToCopy = std::min(c, colcnt);
    for (size_t i = 0; i < rowsToCopy; ++i) {
        for (size_t j = 0; j < colsToCopy; ++j) {
            newBoard[i][j] = board[i][j];
        }
    }

    for (size_t i = 0; i < rowcnt; ++i) {
        delete[] board[i];
    }
    delete[] board;

    rowcnt = r;
    colcnt = c;
    board = newBoard;
}


SpreadSheet SpreadSheet::slice(std::initializer_list<size_t> rows, std::initializer_list<size_t> cols)
{
    size_t new_rowcnt = rows.size();
    size_t new_colcnt = cols.size();

    SpreadSheet slicedSheet(new_rowcnt, new_colcnt);

    size_t new_row = 0;
    for (size_t row : rows) {
        if (row >= rowcnt) {
            throw 1;
        }
        size_t new_col = 0;
        for (size_t col : cols) {
            if (col >= colcnt) {
                throw 1;
            }
            slicedSheet.board[new_row][new_col] = board[row][col];
            ++new_col;
        }
        ++new_row;
    }

    return slicedSheet;
}

SpreadSheet::Column::Column(Cell* col) 
    : column(col) 
{}

Cell& SpreadSheet::Column::operator[](size_t pos)
{
    return column[pos];
}

const Cell& SpreadSheet::Column::operator[](size_t pos) const
{
    return column[pos];
}

bool operator==(const SpreadSheet& lhv, const SpreadSheet& rhv)
{
    if (lhv.row() != rhv.row() || lhv.col() != rhv.col()) {
        return false;
    }

    for (size_t i = 0; i < lhv.row(); ++i) {
        for (size_t j = 0; j < lhv.col(); ++j) {
            if (lhv[i][j] != rhv[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(const SpreadSheet& lhv, const SpreadSheet& rhv)
{
    return !(lhv == rhv);
}

std::ostream& operator<<(std::ostream& out, const SpreadSheet& rhv)
{     
    return  out << rhv << " ";
}
