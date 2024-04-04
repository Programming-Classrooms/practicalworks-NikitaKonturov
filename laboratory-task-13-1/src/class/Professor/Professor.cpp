#include"Professor.hpp"



/*====================================*/
/*=========== Конструкторы ===========*/
/*====================================*/

// По умолчанию[+ с параметрами]
Professor::Professor(char* sFullName, char* sDepartment) : Person(sFullName)
{
    this->department = new char[strlen(sDepartment) + 1];
    strcpy(department, sDepartment);
}

// Копирования
Professor::Professor(const Professor& source) : Professor(source.fullName, source.department)
{}

// Деструктор 
Professor::~Professor() 
{
    if(this->department != nullptr) {
        delete[] this->department;
        this->department = nullptr;
    }
}


/*=========================================*/
/*================ Методы =================*/
/*=========================================*/

    /*====================================*/
    /*============== Гетеры ==============*/
    /*====================================*/

// Получение кафедры
char* Professor::getDepartmen() const
{
    char* result = new char[strlen(this->department) + 1];
    strcpy(result, this->department);
    return result;
}


    /*====================================*/
    /*============== Сетеры ==============*/
    /*====================================*/

// Установка кафедры
void Professor::setDepartment(char* sDepartment)
{
    delete[] this->department;
    this->department = new char[strlen(sDepartment) + 1];
    strcpy(this->department, sDepartment);
}


// Метод вывода информации
std::ostream& Professor::print(std::ostream& out)
{
    Person::print(out);
    out << "Department: " << this->department << std::endl;
    return out;
}
