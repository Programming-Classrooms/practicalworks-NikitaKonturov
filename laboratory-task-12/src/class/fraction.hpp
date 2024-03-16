
#ifndef FRACTION_HPP
#define FRACTION_HPP
#include<iostream>


class Fraction{
private:
    int64_t numerator;
    int64_t denumerator;
    // Сокращение дроби
    void reduction();
public:

/*==========Конструкторы( + деструктор)==========*/

    //Конструктор по умолчанию
    Fraction(int64_t = 0, int64_t = 1);
    //Конструктор копирования
    Fraction(const Fraction&);
    //Дестругтор 
    ~Fraction() = default;

        /*==========Гетеры==========*/

    //Получение числителя
    int64_t getNumerator() const;
    //Получние знаменателя
    int64_t getDenumerator() const;

        /*==========Сетеры==========*/
    
    //Установка числителя
    void setNumerator(int64_t);
    //Установка знаменателя
    void setDenumerator(int64_t);

       /*==========Операторы==========*/


        /*Б. а. о*/
    // Опреатор сложения дробей
    Fraction operator+(const Fraction&) const;
    Fraction& operator+=(const Fraction&);
    // Оператор получения разности дробей
    Fraction operator-(const Fraction&) const;
    Fraction& operator-=(const Fraction&);
    // Опреатор перемножения дробей
    Fraction operator*(const Fraction&) const;
    Fraction& operator*=(const Fraction&);
    // Оператор деления дробей
    Fraction operator/(const Fraction&) const;
    Fraction& operator/=(const Fraction&);

    //Оператор присваивания
    Fraction& operator=(const Fraction&);
    Fraction& operator=(int64_t);

        /*Логические Операторы*/
    //Оператор сравнения
    bool operator==(const Fraction&) const;
    //Оператор не равно
    bool operator!=(const Fraction&) const;
    //Оператор меньше
    bool operator<(const Fraction&) const;
    //Оператор больше
    bool operator>(const Fraction&) const;
    //Оператор меньше или равно
    bool operator<=(const Fraction&) const;
    //Оператор больше или равно
    bool operator>=(const Fraction&) const;

        /*Унарные операторы*/

    //Унарный минус
    Fraction operator-() const;
        
           /*Инкременты*/
    //Постфиксный
    Fraction operator++(int);
    //Префиксный
    Fraction& operator++();

           /*Декремент*/
    //Постфиксный
    Fraction& operator--();
    //Префиксный 
    Fraction operator--(int);



    //Получение обратной дроби
    Fraction operator!() const;
     
        /*=====Поточные операторы=====*/

    //Оператор ввода
    friend std::istream& operator>>(std::istream&, Fraction&);
    //Оператор вывода
    friend std::ostream& operator<<(std::ostream&, const Fraction&);

        /*=====Операторы привидения типов=====*/

    explicit operator double() const;

};


#endif //FRACTION_HPP
