#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "src/class/Tree/Tree.hpp"


class ForestTree : public Tree
{
private:
    size_t woodAmount;
public:

/*================ Конструторы ================*/
    
// Конструктор с параметрами [+ по умолчанию] 
    ForestTree(std::string = "", TreeType = TreeType::Coniferous, int64_t = 1, int64_t = 1);
// Деструктор 
    ~ForestTree() = default;

/*=============== Методы ===============*/

// Вывод в поток
virtual std::ostream& print(std::ostream&) override;

};

#endif // FORESTTREE_HPP
