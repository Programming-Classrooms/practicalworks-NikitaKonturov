#ifndef FOREST_HPP
#define FOREST_HPP
#include<vector>
#include<algorithm>
#include"ForestTree/ForestTree.hpp"
#include"FruitTree/FruitTree.hpp"
#include"Tree/Tree.hpp"


class Forest
{
private:
    std::vector<Tree*> arrWithTrees;
// Копоратор для сортировки
    static bool compareByNameAndAge(Tree*, Tree*);

public:

/*=================== Конструкторы ===================*/

// Конструктор по умолчанию[+ с параметрами]
    Forest(size_t = 0);
// Деструктор
    ~Forest() = default;

    /*=================== Методы ===================*/

 
// Метод вывода информации в неотсортированном виде
    std::ostream& print(std::ostream&) const;
// Метод вывода информации в остортированном виде
    std::ostream& sortPrint(std::ostream&) const;

// Метод подсчёта количества деревьев определлённого вида
    size_t countingView(Tree *) const;
// Метод подсчёта количества деревьев определённого типа
    size_t countingType(TreeType) const;
// Метод добавления дерева с конца
    void pushBack(Tree*);
// Метод получение размера контейнера
    size_t size() const;

    /*=================== Операторы ===================*/

// Оператор ввода
    friend std::istream& operator>>(std::istream&, Forest&);
};

#endif //FOREST_HPP
