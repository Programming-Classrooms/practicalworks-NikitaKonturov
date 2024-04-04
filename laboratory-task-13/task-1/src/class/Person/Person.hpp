
#ifndef PERSON_HPP
#define PERSON_HPP
#include<iostream>
#include<string.h>


class Person
{
protected:
    // Полное имя
    char* fullName;
public:

/*========== Конструкторы ==========*/

    // По умолчанию[+ c параметрами]
    Person(char* = "");
    // Копирования
    Person(const Person&);
    // Деструктор
    virtual ~Person();

/*=========== Методы ===========*/

    /*======= Гетеры =======*/
// Получение полного имении
char* getFullName() const;

    /*======= Сетеры =======*/
// Установка полного имени
void setFullName(char*); 


// Метод вывода информации
virtual std::ostream& print(std::ostream&);

};


#endif //PERSON_HPP
