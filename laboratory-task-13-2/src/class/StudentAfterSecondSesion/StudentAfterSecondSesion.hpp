#ifndef STUDENTAFTERSECONDSESION_HPP
#define STUDENTAFTERSECONDSESION_HPP
#include"src/class/StudentAfterFirstSesion/StudentAfterFirstSesion.hpp"

class StudentAfterSecondSesion : public StudentAfterFirstSesion
{
private:
    size_t* marksOnSecondSession;
public:
    /*============== Конструкторы ==============*/
    // По умолчанию
    StudentAfterSecondSesion() = delete;
    // Конструктор с параметрами 
    StudentAfterSecondSesion(std::string, int64_t, int64_t, int64_t, size_t*, size_t, size_t*, size_t);
    // Конструктор копирования
    StudentAfterSecondSesion(const StudentAfterSecondSesion&);
    // Деструктор
    ~StudentAfterSecondSesion();

      /*============= Гетеры =============*/
    // Получение оценки за вторую сессию
    size_t getMarkToSecondSesion(size_t) const;
    // Получение списка оценок за вторую сессию
    size_t* getMarksToSecondSesion() const;

        /*============= Сетеры =============*/ 
    // Изменение оценки за вторую сессию
    void setMarkToSecondSesion(size_t, size_t);

        /*============= Методы =============*/

    // Вывод информации в поток 
    virtual std::ostream& print(std::ostream&) const override;
    // Метод подсчёта среднего балла за две сессии 
    virtual double middleMark() const override;

        /*============ Операторы ============*/

    friend std::ostream& operator<<(std::ostream&, const StudentAfterFirstSesion&);    
};

#endif // STUDENTAFTERSECONDSESION_HPP
