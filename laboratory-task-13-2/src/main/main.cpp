/*
                Лабораторная работа №4 задание 2
    
    Разработать следующие классы:
    1. Базовый класс Student с полями: 
        ◦ уникальный неизменяемый идентификатор, создаваемый автоматически - константное поле,
        ◦ имя (string),
        ◦ курс,
        ◦ группа, 
        ◦ номер зачетки (неизменяемое после создания объекта поле)- константное поле;
    2. Производный от базового класса класс «студент после первой сессии». 
        Добавить поле – массив из 4 оценок;
    3. Производный от класса «студент после первой сессии» класс «студент после второй сессии». 
        Добавить поле – массив из 5 оценок.
        Реализовать конструкторы с параметрами и конструктор копирования. 
        Запретить вызов конструктора без параметров. 
        Обеспечить уникальность идентификатора. Реализовать методы:
            ◦ set- и get-методы для полей класса Student (где это допустимо);
            ◦ для производных классов определить методы для доступа к оценке (чтение и изменение);
        Во всех 3 классах перегрузить оператор вывода в поток (<<) для вывода сведений о студенте и об оценках.
        Решение оформить как многофайловый проект с использованием стража многократного включения.
        Определить метод подсчета среднего балла (полиморфный):
            – у класса «студент после первой сессии» - после 1 сессии;
            – у класса «студент после второй сессии» - за год.
        Определить средний балл в указанной группе после первой сессии, после двух сессий.
*/


#include "src/class/StudentAfterSecondSesion/StudentAfterSecondSesion.hpp"
#include "src/funcs/funcs.hpp"


int main()
{
    try {
        srand(time(0));
        Student* arr[4];
        size_t arrWithSecondMarks[5] = {0, 0, 0, 0, 0};
        size_t arrWithFirstMarks[4] = {0, 0, 0 ,0};


        randomFilling(arrWithFirstMarks, 4);
        randomFilling(arrWithSecondMarks, 5);
        arr[0] = new StudentAfterFirstSesion(std::string("Kostay"), 1, 1, 7121, arrWithFirstMarks, 4);
        randomFilling(arrWithFirstMarks, 4);
        randomFilling(arrWithSecondMarks, 5);
        arr[1] = new StudentAfterSecondSesion(std::string("Maxim"), 2, 1, 7121, arrWithFirstMarks, 4, arrWithSecondMarks, 5);
        randomFilling(arrWithFirstMarks, 4);
        randomFilling(arrWithSecondMarks, 5);
        arr[2] = new StudentAfterFirstSesion(std::string("Vanya"), 3, 1, 7121, arrWithFirstMarks, 4);
        randomFilling(arrWithFirstMarks, 4);
        randomFilling(arrWithSecondMarks, 5);
        arr[3] = new StudentAfterSecondSesion(std::string("Vadim"), 4, 1, 7121, arrWithFirstMarks, 4, arrWithSecondMarks, 5);

        for (size_t i = 0; i < 4; ++i) {
            std::cout << *arr[i] << std::endl;
        }

        size_t group = 0;
        std::cout << "Enter group: ";
        std::cin >> group;

        double midlleMarkOnFirstSession = midlleMarkOfGroupOnFirstSession(arr, 4, group);
        double midlleMarkOnSecondSession = midlleMarkOfGroupOnSecondSession(arr, 4, group);

        std::cout << "Midlle mark on first session: ";
        if (midlleMarkOnFirstSession < 0) {
            std::cout << "Group not founded" << std::endl;
        } 
        else {
            std::cout << midlleMarkOnFirstSession << std::endl;
        }

        std::cout << "Midlle mark on yer: ";
        if (midlleMarkOnSecondSession < 0) {
            std::cout << "Group not founded" << std::endl;
        } 
        else {
            std::cout << midlleMarkOnSecondSession << std::endl;
        }  
    }
    
    catch (std::invalid_argument& err) {
        std::cerr << err.what() << std::endl;
    }
    return 0;
}
