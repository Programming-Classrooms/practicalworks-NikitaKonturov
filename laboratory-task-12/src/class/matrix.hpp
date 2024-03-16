#ifndef MATRIX_HPP
#define MATRIX_HPP
#include<iostream>
#include<iomanip>
#include"row.hpp"


class Matrix { 
private:
    size_t columns;
    size_t rows;
    Row* mtrx;

    // Перемножение строки и столбца
    int64_t multiplicateRowsColumns(size_t, size_t, const Matrix&) const;
public:

/*==========Конструкторы( + деструктор)==========*/

    //Конструтор по умолчанию
    Matrix(size_t = 1, size_t = 1);
    //Конструктор копирования
    Matrix(const Matrix&);
    //Деструктор
    ~Matrix();

        /*==========Гетеры==========*/
    
    // Получение колличества столбцов
    size_t getColumns() const;
    // Получение колличества строк
    size_t getRows() const;


        /*==========Операторы==========*/
    
    //Итератор
    Row& operator[](size_t);

    //Оператор присваивания
    Matrix& operator=(const Matrix&);
    Matrix& operator=(int64_t);

    /*======Алгебраические операторы======*/

    //Оператор домножения на костанту справа
    Matrix operator*(int64_t) const;
    //Оператор домножения на костанту слева
    friend Matrix operator*(int64_t, const Matrix&);

    //Оператор деления на костанту
    Matrix operator/(int64_t) const;

    //Оператор сложения матриц
    Matrix operator+(const Matrix&) const;

    //Оператор разности матриц
    Matrix operator-(const Matrix&) const;

    //Оператор перемножения матриц
    Matrix operator*(const Matrix&) const;

    /*======Логические операторы======*/

    //Оператор сранения матриц
    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;


        /*=====Поточные операторы=====*/
    
    //Оператор ввода
    friend std::istream& operator>>(std::istream&, Matrix&);
    //Оператор вывода
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

#endif // MATRIX_HPP