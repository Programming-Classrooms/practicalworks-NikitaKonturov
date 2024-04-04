#ifndef MENU_HPP
#define MENU_HPP
#include"../class/Professor/Professor.hpp"
#include"../class/Student/Student.hpp"
#include"../class/Person/Person.hpp"

void menu();
void addStudent(Person**, size_t&);
void addProfessor(Person**, size_t&);
void printStudents(Person**, size_t);
void printProfessors(Person**, size_t);

#endif // MENU_HPP
