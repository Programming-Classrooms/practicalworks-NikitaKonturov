#ifndef ROW_HPP
#define ROW_HPP
#include<iostream>


class Row{
private:
    size_t rowSize;
    int64_t* row;
public:
    
/*==========Конструкторы( + деструктор)==========*/

    // Конструктор по умолчанию
    Row(size_t = 1);
    // Конструктор копирования
    Row(const Row&);
    // Деструктор 
    ~Row();

/*=============Сеттеры=============*/

    // Установка размрера массива
    void setSize(size_t);

/*==========Операторы==========*/

    // Итератор
    int64_t& operator[](size_t);
    // Присваивание
    Row& operator=(const Row&);


};


#endif //ROW_HPP