
#include "Student.hpp"

size_t Student::countID = 0;

    /*========================================*/
    /*=========== Конструкторы ===============*/
    /*========================================*/

// Конструктор с параметрами
Student::Student(std::string sName, int64_t sRecordNumber, int64_t sCource, int64_t sGroup) : name(sName), ID(++countID), recordNumber(sRecordNumber)
{
    if (sRecordNumber <= 0) {
        throw std::invalid_argument("Record number must be natural number...");
    }
    if (sCource <= 0 || sCource > 6) {
        throw std::invalid_argument("Cource must be natural number and less that 6...");
    }
    if (sGroup <= 0) {
        throw std::invalid_argument("Group number must be natural number...");
    }

    this->cource = sCource;
    this->group = sGroup;
}

// Конструктор копирования
Student::Student(const Student& source) : Student(source.name, source.recordNumber, source.cource, source.group)
{}

    /*========================================*/
    /*=============== Сетеры =================*/
    /*========================================*/

// Установка имени
void Student::setName(std::string sourceName)
{
    this->name = sourceName;
}

// Установка группы
void Student::setGroup(int64_t sGroup)
{
    if (sGroup <= 0) {
        throw std::invalid_argument("Group number must be natural number...");
    }
    this->group = sGroup;
}

// Установка курса
void Student::setCource(int64_t sCource)
{
     if (sCource <= 0 || sCource > 6) {
        throw std::invalid_argument("Cource must be natural number and less that 6...");
    }

    this->cource = sCource;
}

    /*========================================*/
    /*=============== Гетеры =================*/
    /*========================================*/

// Получение имени
std::string Student::getName() const
{
    return this->name;
}

// Получение номера зачётки
size_t Student::getRecordNumber() const
{
    return this->recordNumber;
}

// Получение номера группы
size_t Student::getGroup() const
{
    return this->group;
}

// Получение курса
size_t Student::getCource() const
{
    return this->cource;
}

// Получение уникального идентификатора
size_t Student::getID() const
{
    return this->ID;
}

// Метод вывода информации в поток
std::ostream& Student::print(std::ostream& out) const
{
    out << "ID: " << this->ID << std::endl;
    out << "Record number: " << this->recordNumber << std::endl;
    out << "Name: " << this->name << std::endl;
    out << "Group: " << this->group << std::endl;
    out << "Cource: " << this->cource << std::endl;

    return out;
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& out, const Student& source)
{
    source.print(out);
    return out;
}
