#include"Student.hpp"


/*====================================*/
/*=========== Конструкторы ===========*/
/*====================================*/

// Конструктор по умолчанию[+ c параметрами]
Student::Student(char* sName, int64_t sCource, int64_t sGroup) : Person(sName)
{
    if (sCource <= 0) {
        throw std::invalid_argument("Cource must be natural...");
    }
    if (sGroup <= 0) {
        throw std::invalid_argument("Group must be natural...");
    }

    this->cource = sCource;
    this->group = sGroup;
}

// Конструктор копирования
Student::Student(const Student& source)
{
    char* fullName = source.getFullName();
    Student(fullName, source.cource, source.group);
    delete[] fullName;
}

// Деструктор 
Student::~Student()
{
    Student::~Person();
}

/*=========================================*/
/*================ Методы =================*/
/*=========================================*/

    /*====================================*/
    /*============== Гетеры ==============*/
    /*====================================*/

// Получение курса
size_t Student::getCource() const
{
    return this->cource;
} 

// Получение группы
size_t Student::getGroup() const
{
    return this->group;
}


    /*====================================*/
    /*============== Сетеры ==============*/
    /*====================================*/

// Установка группы
void Student::setGroup(int64_t sGroup)
{
    if (sGroup <= 0) {
        throw std::invalid_argument("Group must be natural...");
    }

    this->group = sGroup;
}

// Установка курса
void Student::setCource(int64_t sCource)
{
    if (sCource <= 0) {
        throw std::invalid_argument("Cource must be natural...");
    }

    if (sCource > 6) {
        throw std::invalid_argument("Cource must be less that 7...");
    }

    this->cource = sCource;
}

// Метод вывода информации
std::ostream& Student::print(std::ostream& out)
{
    Person::print(out);
    out << "Cource: " << this->cource << std::endl;
    out << "Group: " << this->group << std::endl;
    return out;
}
