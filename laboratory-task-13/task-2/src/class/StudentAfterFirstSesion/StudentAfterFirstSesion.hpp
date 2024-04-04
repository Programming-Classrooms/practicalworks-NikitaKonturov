#ifndef STUDENTAFTERFIRSTSESION_HPP
#define STUDENTAFTERFIRSTSESION_HPP
#include"src/class/Student/Student.hpp"


class StudentAfterFirstSesion : public Student
{
protected:
    size_t* marksOnFirstSession;
    public:
    /*============== Конструкторы ==============*/
    // По умолчанию
    StudentAfterFirstSesion() = delete;
    // Конструктор с параметрами
    StudentAfterFirstSesion(std::string, int64_t, int64_t, int64_t, size_t*, size_t);
    // Конструктор копирования
    StudentAfterFirstSesion(const StudentAfterFirstSesion&);
    // Деструктор
    ~StudentAfterFirstSesion();

        /*============= Гетеры =============*/
    // Получение оценки за первую сессию
    size_t getMarkToFirstSesion(size_t) const;
    // Получение списка оценнок за первую сессию
    size_t* getMarksOnFirstSesion() const;
        /*============= Сетеры =============*/ 
    // Изменение оценки за первую сессию
    void setMarkToFirstSesion(size_t, size_t);

        /*============= Методы =============*/

    // Вывод информации в поток 
    virtual std::ostream& print(std::ostream&) const override;
    // Метод подсчёта среднего балла за первую сессию 
    virtual double middleMark() const;

        /*============ Операторы ============*/

    friend std::ostream& operator<<(std::ostream&, const StudentAfterFirstSesion&);    
};
#endif // STUDENTAFTERFIRSTSESION_HPP
