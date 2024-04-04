#include"StudentAfterSecondSesion.hpp"


    /*============================================*/
    /*============= Конструкторы =================*/
    /*============================================*/

// Конструктор с параметрами
StudentAfterSecondSesion::StudentAfterSecondSesion(std::string sName, 
                                                    int64_t sRecordNumber, 
                                                    int64_t sCource,   
                                                    int64_t sGroup, 
                                                    size_t* sMarksOnFirstSesion, 
                                                    size_t sizeMarksOnFirstSesion,
                                                    size_t* sMarksOnSecondSesion, 
                                                    size_t  sizeMarksOnSecondSesion) : 
                                                    StudentAfterFirstSesion(sName, sRecordNumber, sCource, sGroup, sMarksOnFirstSesion, sizeMarksOnFirstSesion) 
{
    if (sizeMarksOnSecondSesion != 5) {
        throw std::invalid_argument("Arr size must be equal 5...");
    }

    this->marksOnSecondSession = new size_t[5];
    for (size_t i = 0; i < sizeMarksOnSecondSesion; ++i) {
        if(sMarksOnSecondSesion[i] > 10 || sMarksOnSecondSesion[i] == 0) {
            throw std::invalid_argument("Mark must be natural and less that 10...");
        }
        this->marksOnSecondSession[i] = sMarksOnSecondSesion[i];
    }
}

// Конструктор копирования
StudentAfterSecondSesion::StudentAfterSecondSesion(const StudentAfterSecondSesion& source) :  StudentAfterSecondSesion(source.name, source.recordNumber, source.cource, source.group, source.marksOnFirstSession, 4, source.marksOnSecondSession, 5)
{}
 
// Деструктор
StudentAfterSecondSesion::~StudentAfterSecondSesion()
{
    StudentAfterFirstSesion::~StudentAfterFirstSesion();
    if(this->marksOnSecondSession != nullptr) {
        delete[] this->marksOnSecondSession;
        this->marksOnSecondSession = nullptr;
    }
}


    /*============================================*/
    /*================ Гетеры  ===================*/
    /*============================================*/

// Получени оценки за вторую сессию
size_t StudentAfterSecondSesion::getMarkToSecondSesion(size_t index) const
{
    if (index > 4) {
        throw std::out_of_range("Index must be natural and less that 5");
    }
    return this->marksOnSecondSession[index];
}

// Получение списка оценок за вторую сессию
size_t* StudentAfterSecondSesion::getMarksToSecondSesion() const
{
    return this->marksOnSecondSession;
}


    /*============================================*/
    /*================ Cетеры  ===================*/
    /*============================================*/

// Изменение оценки за вторую сессию
void StudentAfterSecondSesion::setMarkToSecondSesion(size_t index, size_t mark)
{
    if (index > 4) {
        throw std::out_of_range("Index must be natural and less that 4");
    }
    if(mark > 10 || mark == 0) {
            throw std::invalid_argument("Mark must be natural and less that 10...");
    }
    this->marksOnSecondSession[index] = mark; 
}


    /*============================================*/
    /*================ Методы  ===================*/
    /*============================================*/

// Вывод информации в поток
std::ostream& StudentAfterSecondSesion::print(std::ostream& out) const
{
    StudentAfterFirstSesion::print(out);
    out << "Marks after second sesion: ";
    for (size_t i = 0; i < 5; ++i) {
        out << " " << this->marksOnSecondSession[i];
    }
    out << std::endl;
    
    return out;
}

// Метод подсчёта среднего балла за две сессии 
double StudentAfterSecondSesion::middleMark() const
{
    double res = 0;
    size_t* marksOnFirstSession = this->getMarksOnFirstSesion();
    size_t* marksOnSecondSession = this->marksOnSecondSession;
    for (size_t i = 0; i < 4; ++i) {
        res += marksOnFirstSession[i];
    }
    for (size_t i = 0; i < 5; ++i) {
        res += marksOnSecondSession[i];
    }
    
    return res / 9;
}


    /*============================================*/
    /*================ Оператор ==================*/
    /*============================================*/

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& out, const StudentAfterSecondSesion& source)
{
    source.print(out);
    return out;
}
