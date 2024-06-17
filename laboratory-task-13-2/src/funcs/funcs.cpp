#include "funcs.hpp"

// Случайное заполнение массива отметками
void randomFilling(size_t* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        arr[i] = 1 + (rand() % 10);
    }
}

// Вычисление среднего балла группы за перый семестр
double midlleMarkOfGroupOnFirstSession(Student** arr, size_t size, size_t group)
{
    double midlleMark = 0;
    double studentsInThisGroup = 0;

    for (size_t i = 0; i < size; ++i) {
        if(dynamic_cast<StudentAfterFirstSesion*>(arr[i]) && arr[i]->getGroup() == group) {
            midlleMark += dynamic_cast<StudentAfterFirstSesion*>(arr[i])->middleMark();
            ++studentsInThisGroup;
        }
    }
    
    if(studentsInThisGroup == 0) {
        return 0;
    }

    return midlleMark / studentsInThisGroup;
}

// Вычисление среднего балла группы за год
double midlleMarkOfGroupOnSecondSession(Student** arr, size_t size, size_t group)
{
    double midlleMark = 0;
    double studentsInThisGroup = 0;

    for (size_t i = 0; i < size; ++i) {
        if(dynamic_cast<StudentAfterSecondSesion*>(arr[i]) && arr[i]->getGroup() == group) {
            midlleMark += dynamic_cast<StudentAfterSecondSesion*>(arr[i])->middleMark();
            ++studentsInThisGroup;
        }
    }
    
    if(studentsInThisGroup == 0) {
        return 0;
    }

    return midlleMark / studentsInThisGroup;
}
