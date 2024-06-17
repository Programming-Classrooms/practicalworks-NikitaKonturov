#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include "src/class/Tree/Tree.hpp"

class FruitTree : public Tree {
private:
    size_t cropMass;
    size_t storageDuration;
public:
    
/*=================== Конструкторы ===================*/
    
    // Конструктор с параметрами[+ по умолчанию]
    FruitTree(std::string = "", TreeType = TreeType::Deciduous, int64_t = 1, int64_t = 1, int64_t = 1);
    // Деструктор
    ~FruitTree() = default;

    /*=================== Методы ===================*/

    // Метод вывода информации в поток
    virtual std::ostream& print(std::ostream&) override;
};

#endif // FRUITTREE_HPP
