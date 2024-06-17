#include"FruitTree.hpp"


    /*====================================*/
    /*=========== Конструкторы ===========*/
    /*====================================*/

// Конструткор с параметрами[+ по умолчанию]
FruitTree::FruitTree(std::string sName, TreeType sType, int64_t sAge, int64_t sCropeMass, int64_t sStorageDuration) : Tree(sName, sType, sAge) 
{
    if (sCropeMass <= 0) {
        throw std::invalid_argument("Crope mass must be natural...");
    }
    if (sStorageDuration <= 0) {
        throw std::invalid_argument("Storage duration must be natural...");
    }
    this->cropMass = sCropeMass;
    this->storageDuration = sStorageDuration;
}

    /*===================================*/
    /*============= Методы ==============*/
    /*===================================*/

// Метод вывода в поток
std::ostream& FruitTree::print(std::ostream& out)
{
    Tree::print(out);
    out << "Cross mass: " << this->cropMass << std::endl;
    out << "Storage duration: " << this->storageDuration << std::endl;

    return out;
}
