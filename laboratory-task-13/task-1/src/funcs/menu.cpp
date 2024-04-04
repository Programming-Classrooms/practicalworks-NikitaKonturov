#include"menu.hpp"

void addStudent(Person** arr, size_t& countOfPersons)
{
    char name[1000];
    size_t cource = 0;
    size_t group = 0;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::cin.getline(name, 1000);
    std::cout << "\nEnter cource: ";
    std::cin >> cource;
    std::cout << "\nEnter group: ";
    std::cin >> group;
    arr[countOfPersons++] = new Student(name, cource, group);
}
 
void addProfessor(Person** arr, size_t& countOfPersons)
{
    char name[1000];
    char department[1000];
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::cin.getline(name, 1000);
    std::cout << "\nEnter department: ";
    std::cin.getline(department, 1000);
    arr[countOfPersons++] = new Professor(name, department);
}

void printStudents(Person** arr, size_t countOfPersons)
{
    std::cout << "======================================" << std::endl;
    std::cout << "Students: " << std::endl;
    bool arrHaveStudents = false;
    for (size_t i = 0; i < countOfPersons; ++i) {
        if(dynamic_cast<Student *>(arr[i])) {
            arrHaveStudents = true;
            arr[i]->print(std::cout);
            std::cout << "######################################" << std::endl;
        }
    }

    if (!arrHaveStudents) {
        std::cout << "В списке отсутствуют студенты" << std::endl;
        std::cout << "######################################" << std::endl;
    }
}

void printProfessors(Person** arr, size_t countOfPersons)
{
    std::cout << "======================================" << std::endl;
    std::cout << "Professors: " << std::endl;
    bool arrHaveProfessors = false;  
    for (size_t i = 0; i < countOfPersons; ++i) {
        if(dynamic_cast<Professor *>(arr[i])) {
            arrHaveProfessors = true;
            arr[i]->print(std::cout);
            std::cout << "######################################" << std::endl;
        }
    }
    if(!arrHaveProfessors) {
        std::cout << "В списке отсутствуют преподаватели" << std::endl;
        std::cout << "######################################" << std::endl;
    }
}

void menu()
{
    size_t command = 0;
    size_t sizeOfList = 0;
    size_t countOfPersons = 0;
    std::cout << "Enter size of list: ";
    std::cin >> sizeOfList;
    std::cout << std::endl; 

    Person** listAllPersons = new Person*[sizeOfList];

    while(command != 5) {
        std::cout << "=============== Меню ===============" << std::endl;
        std::cout << "  1. Ввести студента " << std::endl;
        std::cout << "  2. Ввести преподавателя " << std::endl;
        std::cout << "  3. Вывести список студентов " << std::endl;
        std::cout << "  4. Вывести список преподавателей " << std::endl;
        std::cout << "  5. Закончить работу " << std::endl; 

        std::cin >> command;

        if(command == 1) {
            if (sizeOfList == countOfPersons) {
                std::cout << "Список заполнен" << std::endl;
            }
            addStudent(listAllPersons, countOfPersons);
        }
        if(command == 2) {
            if (sizeOfList == countOfPersons) {
                std::cout << "Список заполнен" << std::endl;
            }
            addProfessor(listAllPersons, countOfPersons);
        }
        if(command == 3) {
            printStudents(listAllPersons, countOfPersons);
        }
        if(command == 4) {
            printProfessors(listAllPersons, countOfPersons);
        }
        
    }
    for (size_t i = 0; i < countOfPersons; ++i) {
        delete listAllPersons[i];
    }
    delete[] listAllPersons;
}
