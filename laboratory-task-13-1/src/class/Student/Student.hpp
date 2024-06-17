#ifndef STUDENT_HPP
#define STUDENT_HPP
#include"src/class/Person/Person.hpp"

class Student : public Person
{
private:
    size_t cource;
    size_t group;
public:

/*========== Конструкторы ==========*/

    // По умолчанию[+ c параметрами]
    Student(char* = "", int64_t = 1, int64_t = 1);
    // Копирования
    Student(const Student&);
    // Деструктор
    ~Student() = default;


/*=========== Методы ===========*/

    /*======= Гетеры =======*/
// Получение курса
size_t getCource() const;
// Получение группы
size_t getGroup() const;

    /*======= Сетеры =======*/
// Установка курса
void setCource(int64_t); 
// Установка группы
void setGroup(int64_t);

// Метод вывода информации
std::ostream& print(std::ostream&) override final;
};


#endif // STUDENT_HPP
