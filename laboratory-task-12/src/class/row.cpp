#include "row.hpp"


/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/


// Консттруктор по умолчанию
Row::Row(size_t size) : rowSize(size), row(new int64_t[rowSize])
{
    for (size_t i = 0; i < rowSize; ++i) {
        row[i] = 0;
    }
}

// Конструктор копирования
Row::Row(const Row& source) : rowSize(source.rowSize), row(new int64_t[rowSize])
{
    for (size_t i = 0; i < rowSize; ++i) {
        row[i] = source.row[i];
    }
}

// Деструктор
Row::~Row()
{
    delete[] row;
    row = nullptr;
}

/*==========================================================*/
/*========================Сетеры============================*/
/*==========================================================*/


// Установка размера массива
void Row::setSize(size_t size) 
{
    delete[] this->row;
    this->row = new int64_t[size];
    this->rowSize = size;
}


/*==========================================================*/
/*======================Операторы===========================*/
/*==========================================================*/

// Итератор
int64_t& Row::operator[](size_t index)
{
    if(index >= rowSize) {
        throw std::out_of_range("Out of range...");
    }

    return row[index];
}

// Присваивание
Row& Row::operator=(const Row& source)
{
    rowSize = source.rowSize;
    if(row != nullptr) {
        delete[] row;
    }
    row = new int64_t[rowSize];

    for (size_t i = 0; i < rowSize; ++i) {
        row[i] = source.row[i];
    }
    return *this;
}