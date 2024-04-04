
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include<iostream>
#include<string>


class Student{
protected:
static size_t countID;
const size_t ID;
const size_t recordNumber;
std::string name;
size_t cource;
size_t group;
public:

/*============== Конструкторы ==============*/

// По умолчанию
Student() = delete;
// С параметрами
Student(std::string, int64_t, int64_t, int64_t);
// Копирования
Student(const Student&);
// Деструктор
~Student() = default;

    /*============ Сетеры ============*/

// Установка имени
void setName(std::string);
// Установка группы
void setGroup(int64_t);
// Установка курса
void setCource(int64_t);

    /*============ Гетеры ============*/

// Получение имени
std::string getName() const;
// Получение номера зачётки
size_t getRecordNumber() const;
// Получение номера группы
size_t getGroup() const;
// Получение курса
size_t getCource() const;
// Получение уникального числового идентификатора
size_t getID() const;

        /*============= Методы =============*/
// Метод вывода информации в поток
virtual std::ostream& print(std::ostream&) const;

/*======== Дружественные методы ======== */

// Оператор вывода в поток
friend std::ostream& operator<<(std::ostream&, const Student&);
};

#endif //STUDENT_HPP
