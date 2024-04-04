
#ifndef TREE_HPP
#define TREE_HPP
#include<iostream>

enum class TreeType{
    Coniferous,
    Deciduous   
};

class Tree {
protected:
    TreeType type;
    std::string name; 
    size_t age;
public:

/*================ Конструкторы ================*/

    // Конструктор по с параметрами[+ по умолчанию]
    Tree(std::string = "", TreeType = TreeType::Deciduous, int64_t = 1);
    // Деструктор 
    ~Tree() = default;

    /*================ Методы ================*/

    // Метод вывода информации в поток
    virtual std::ostream& print(std::ostream&);

    /*================ Гетеры ================*/

    // Метод получения названия
    std::string getName() const;
    // Метод получения возраста
    size_t getAge() const;
    // Метод получения типа
    TreeType getType() const;
};

#endif //TREE_HPP
