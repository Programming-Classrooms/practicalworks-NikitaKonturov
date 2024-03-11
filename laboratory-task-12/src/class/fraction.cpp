
#include<math.h>
#include"fraction.hpp"


//Сокращение дроби
void Fraction::reduction()
{
    for (size_t i = 1; i <= sqrt(this->numerator) && i <= sqrt(this->denumerator); ++i) {
        if (this->numerator % i == 0 && this->denumerator % i == 0) {
            this->numerator /= i;
            this->denumerator /= i;
        }
    }
}


/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

//Конструктор по умолчанию
Fraction::Fraction(int64_t sourceNumerator, int64_t sourceDenumerator)
{
    this->numerator = sourceNumerator;
    if (sourceDenumerator == 0) {
        throw std::invalid_argument("Bad argument, denumerator must be non-null...");
    } 
    
    if(sourceDenumerator < 0) {
        this->numerator *= -1;
        sourceDenumerator *= -1;
    }
    this->denumerator = sourceDenumerator;
    this->reduction();
}

//Конструктор копирования
Fraction::Fraction(const Fraction& origin) {
    this->numerator = origin.numerator;
    this->denumerator = origin.denumerator;
} 


/*==========================================================*/
/*=======================Гетеры=============================*/
/*==========================================================*/

//Получение числителя
int64_t Fraction::getNumerator() const
{
    return this->numerator;
}

//Получение знаменателя
int64_t Fraction::getDenumerator() const
{   
    return this->denumerator;
}


/*==========================================================*/
/*=======================Cетеры=============================*/
/*==========================================================*/

//Установка числителя
void Fraction::setNumerator(int64_t source)
{
    this->numerator = source;
    
    this->reduction();
}

//Установка знаменателя
void Fraction::setDenumerator(int64_t source)
{   
    if (source == 0) {
        throw std::invalid_argument("Bad argument, denumerator must be non-null...");
    }
    else if (source < 0) {
        this->numerator *= -1;
        source *= -1;
    }
    this->denumerator = source;
    this->reduction();
}

/*==========================================================*/
/*==========================================================*/
/*=====================Операторы============================*/
/*==========================================================*/
/*==========================================================*/


/*==========================================================*/
/*=================Бинарные операторы=======================*/
/*==========================================================*/

//Оператор сложения дробей
Fraction Fraction::operator+(const Fraction& source) const
{
    Fraction res = *this;  
    res.numerator = res.numerator*source.denumerator + source.numerator * res.denumerator;
    res.denumerator *= source.denumerator;
    res.reduction();
    return res;
}

Fraction& Fraction::operator+=(const Fraction& source)
{
    *this = *this + source;
    return *this;
}

// Оператор получения разности дробей
Fraction Fraction::operator-(const Fraction& source) const
{
    return *this + (-source);
}

Fraction& Fraction::operator-=(const Fraction& source)
{
    return *this += -source;
}

 // Опреатор перемножения дробей
Fraction Fraction::operator*(const Fraction& source) const
{
    Fraction res(this->numerator * source.numerator, this->denumerator * source.denumerator);
    res.reduction();
    return res;
}

Fraction& Fraction::operator*=(const Fraction& source)
{
    *this = *this * source; 
    return *this;
}

// Оператор деления дробей
Fraction Fraction::operator/(const Fraction& source) const
{
    return *this * (!source);
}

Fraction& Fraction::operator/=(const Fraction& source)
{
    *this = *this / source;
    return *this;
}

//Оператор присваивания
Fraction& Fraction::operator=(const Fraction& source)
{
    this->numerator = source.numerator;
    this->denumerator = source.denumerator;
    return *this;
}

Fraction& Fraction::operator=(int64_t source)
{
    this->numerator = source;
    this->denumerator = 1;
    return *this;
}


/*==========================================================*/
/*================Логические операторы======================*/
/*==========================================================*/


//Оператор сравнения
bool Fraction::operator==(const Fraction& source) const
{
    return (this->numerator * source.denumerator) == (this->denumerator * source.numerator);
}

//Оператор меньше
bool Fraction::operator<(const Fraction& source) const
{
    return (this->numerator * source.denumerator) < (this->denumerator * source.numerator);
}

//Оператор не равно
bool Fraction::operator!=(const Fraction& source) const
{
    return !(*this == source);
}

//Оператор меньше или равно
bool Fraction::operator<=(const Fraction& source) const
{
    return (*this < source || *this == source);
}

//Оператор больше
bool Fraction::operator>(const Fraction& source) const
{
    return !(*this <= source);
}

//Оператор больше или равно
bool Fraction::operator>=(const Fraction& source) const
{
    return !(*this < source);
}


/*==========================================================*/
/*==================Унарные операторы=======================*/
/*==========================================================*/

//Получение обратной дроби
Fraction Fraction::operator!() const
{
    return Fraction(this->denumerator, this->numerator);
}

//Унарный минус
Fraction Fraction::operator-() const
{
    return Fraction(-(this->numerator), this->denumerator);
}


/*=======================Инкременты=========================*/

//Префиксный
Fraction& Fraction::operator++(int)
{
    *this = *this + Fraction(1, 1);
    this->reduction();
    return *this;
}

//Постфиксный
Fraction Fraction::operator++()
{
    Fraction res = *this;
    ++*this;
    return res;
}

/*=======================Декременты=========================*/

//Префиксный
Fraction& Fraction::operator--(int)
{
    *this = *this - Fraction(1, 1);
    this->reduction();
    return *this;
}

//Постфиксный
Fraction Fraction::operator--()
{
    Fraction res = *this;
    --*this;
    return res;
}


/*==========================================================*/
/*==================Поточные операторы======================*/
/*==========================================================*/

//Оператор вывода
std::ostream& operator<<(std::ostream &out, const Fraction& source)
{
    out << source.numerator << "/" << source.denumerator;
    return out;
}

//Оператор ввода
std::istream& operator>>(std::istream& in, Fraction& source)
{
    int64_t numer = 0;
    int64_t denumer = 1;
    char let = '0';
    in.get(let);
    int isNegative = 1;
    if(let == '-') {
        isNegative *= -1;
    }
    else if (!isdigit(let)) {
        source.numerator = 0;
        source.denumerator = 1;
        return in;
    }
    else {
        numer = static_cast<int>(let) - '0';
    } 
    while(in.get(let) && isdigit(let)) {
        numer *= 10;
        numer += static_cast<int>(let) - '0';
    }

    if (let != '/') {
        source.numerator = numer;
        source.denumerator = 1;
        source.reduction();
        return in;
    }
    else {
        while(in.get(let) && isdigit(let)) {
            denumer *= 10;
            denumer += static_cast<int>(let) - '0';
        }
        source.numerator = numer;
        source.denumerator = denumer;
        source.reduction();
        return in;
    }
}

/*==============Приведение типов==============*/

Fraction::operator double() const
{
    return (static_cast<double>(this->numerator) / static_cast<double>(this->denumerator));
}
