#define _CRT_SECURE_NO_WARNINGS
#include "Person.hpp"


/*====================================*/
/*=========== Конструкторы ===========*/
/*====================================*/

// Конструктор по умолчанию[+ c параметрами]
Person::Person(char* source)
{
    this->fullName = new char[strlen(source) + 1];
    strcpy(this->fullName, source);
}

// Конструктор копирования
Person::Person(const Person& source) : Person(source.fullName)
{}

// Деструктор
Person::~Person()
{
    if(this->fullName != nullptr) {
        delete[] this->fullName;
        this->fullName = nullptr;
    }
}

/*=========================================*/
/*================ Методы =================*/
/*=========================================*/

    /*====================================*/
    /*============== Гетеры ==============*/
    /*====================================*/

// Получение полного имени
char* Person::getFullName() const
{
    char* temp = new char[strlen(fullName) + 1];
    strcpy(temp, fullName);
    return temp;
}


    /*====================================*/
    /*============== Сетеры ==============*/
    /*====================================*/

// Установка полного имени
void Person::setFullName(char* source)
{
    delete[] this->fullName;
    this->fullName = new char[strlen(source) + 1];
    strcpy(this->fullName, source);
}

// Метод вывода информации 
std::ostream& Person::print(std::ostream& out)
{
    out << "Full name: " << this->fullName << std::endl;
    return out;
}