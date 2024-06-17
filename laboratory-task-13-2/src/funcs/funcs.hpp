#ifndef FUNCS_HPP
#define FUNCS_HPP
#include<iostream>
#include<random>
#include"src/class/StudentAfterSecondSesion/StudentAfterSecondSesion.hpp"


// Заполение случайными отметками массива
void randomFilling(size_t*, size_t);
// Вычисление среднего балла за первый семестр
double midlleMarkOfGroupOnFirstSession(Student**, size_t, size_t);
// Вычисление среднего балла за год
double midlleMarkOfGroupOnSecondSession(Student**, size_t, size_t);

#endif
