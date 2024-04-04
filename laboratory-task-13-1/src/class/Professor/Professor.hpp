#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include"src/class/Person/Person.hpp"

class Professor : public Person 
{
private:
    char* department;
public:
/*========== Конструкторы ==========*/

    // По умолчанию[+ c параметрами]
    Professor(char* = "", char* = "");
    // Копирования
    Professor(const Professor&);
    // Деструктор
    ~Professor();

/*=========== Методы ===========*/

    /*======= Гетеры =======*/
// Получение кафедры
char* getDepartmen() const;

    /*======= Сетеры =======*/
// Установка кафедры
void setDepartment(char*); 

// Метод вывода информации
std::ostream& print(std::ostream&) override final;
};

#endif // PROFESSOR_HPP
