#ifndef AUTHOR_HPP
#define AUTHOR_HPP
#include<regex>
#include<iostream>

class Author
{
private:
    std::string name;
    std::string sureName;
    std::string fatherName;
public:

/*================== Конструкторы ==================*/


// С параметрами[+ по умолчанию]
    Author(std::string = "", std::string = "", std::string = "");
// Копирование
    Author(const Author&);
// Деструктор
    ~Author() = default;

/*==================== Геттеры =====================*/

// Получение имение
    std::string getName() const;
// Получение фамилии
    std::string getSurenaem() const;
// Получение отчества
    std::string getFathername() const;

/*=================== Операторы ====================*/

// Вывод
friend std::ostream& operator<<(std::ostream&, const Author&);
// Ввод
friend std::istream& operator>>(std::istream&, Author&);
// Присваивание
Author& operator=(const Author&);
// Оператор сравнения
bool operator==(const Author&) const;
// Оператор меньше
bool operator<(const Author&) const;
// Оператор больше
bool operator>(const Author&) const;
};

#endif // AUTHOR_HPP
