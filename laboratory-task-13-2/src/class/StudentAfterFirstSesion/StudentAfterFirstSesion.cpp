#include "StudentAfterFirstSesion.hpp"

    /*============================================*/
    /*============= Конструкторы =================*/
    /*============================================*/

// Конструктор с параметрами
StudentAfterFirstSesion::StudentAfterFirstSesion(std::string sName, 
                                                int64_t sRecordNumber, 
                                                int64_t sCource,   
                                                int64_t sGroup, 
                                                size_t* sMarks, 
                                                size_t sizeArr) :
                                                Student(sName, sRecordNumber, sCource, sGroup)

{   
    if (sizeArr != 4) {
        throw std::invalid_argument("Arr size must be equal 4...");
    }

    this->marksOnFirstSession = new size_t[4];
    for (size_t i = 0; i < sizeArr; ++i) {
        if(sMarks[i] > 10 || sMarks[i] == 0) {
            throw std::invalid_argument("Mark must be natural and less that 10...");
        }
        this->marksOnFirstSession[i] = sMarks[i];
    }
}

// Контсруктор копирования
StudentAfterFirstSesion::StudentAfterFirstSesion(const StudentAfterFirstSesion& source) :
                                                StudentAfterFirstSesion(source.name, source.recordNumber, source.cource, source.group, source.marksOnFirstSession, 4)
{}

// Деструктор 
StudentAfterFirstSesion::~StudentAfterFirstSesion()
{
    if(this->marksOnFirstSession != nullptr) {
        delete[] marksOnFirstSession;
        this->marksOnFirstSession = nullptr;
    }
}


    /*============================================*/
    /*================ Гетеры ====================*/
    /*============================================*/

// Получение оценки
size_t StudentAfterFirstSesion::getMarkToFirstSesion(size_t index) const
{
    if (index > 3) {
        throw std::out_of_range("Index must be natural and less that 4");
    }
    return this->marksOnFirstSession[index];
}

// Получение списка с оценками
size_t* StudentAfterFirstSesion::getMarksOnFirstSesion() const
{
    return this->marksOnFirstSession;
}    


    /*============================================*/
    /*================ Cетеры ====================*/
    /*============================================*/

// Изменение оценки 
void StudentAfterFirstSesion::setMarkToFirstSesion(size_t index, size_t mark)
{
    if (index > 3) {
        throw std::out_of_range("Index must be natural and less that 4");
    }
    if(mark > 10 || mark == 0) {
            throw std::invalid_argument("Mark must be natural and less that 10...");
    }
    this->marksOnFirstSession[index] = mark; 
}


    /*============================================*/
    /*================ Методы ====================*/
    /*============================================*/    

// Метод вывода в поток
std::ostream& StudentAfterFirstSesion::print(std::ostream& out) const
{
    Student::print(out);
    out << "Marks after first session: ";
    for (size_t i = 0; i < 4; ++i) {
        out << " " << this->marksOnFirstSession[i];
    }
    out << std::endl;
    return out;
}

// Метод подсчёта среднего балла за первую сессию
double StudentAfterFirstSesion::middleMark() const
{
    double res = 0;
    for (size_t i = 0; i < 4; ++i) {
        res += this->marksOnFirstSession[i];
    }
    return res / 4;
}


    /*============================================*/
    /*=============== Операторы ==================*/
    /*============================================*/  

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& out, const StudentAfterFirstSesion& source)
{
    return source.print(out);
}
