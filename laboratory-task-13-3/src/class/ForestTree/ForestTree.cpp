#include"ForestTree.hpp"


    /*========================================================*/
    /*===================== Конструкторы =====================*/
    /*========================================================*/

// Конструкторы с параметрами[+ по умолчанию] 
ForestTree::ForestTree(std::string sName, TreeType sType, int64_t sAge, int64_t sAmount) : Tree(sName, sType, sAge), woodAmount(sAmount) 
{}


    /*========================================================*/
    /*===================== Методы ===========================*/
    /*========================================================*/

// Метод вывода в поток
std::ostream& ForestTree::print(std::ostream& out)
{
    Tree::print(out);
    out << "Amount of wood: " << this->woodAmount << std::endl;
    
    return out;
}
