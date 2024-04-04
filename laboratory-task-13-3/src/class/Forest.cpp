#include"Forest.hpp"


    /*========================================================*/
    /*===================== Конструкторы =====================*/
    /*========================================================*/

// Конструктор по умолчанию[+ с параметрами]
Forest::Forest(size_t sSize) : arrWithTrees(std::vector<Tree *>(sSize, nullptr))
{}

    /*========================================================*/
    /*======================== Методы ========================*/
    /*========================================================*/


// Копоратор для сортировки
bool Forest::compareByNameAndAge(Tree* first, Tree* second)
{
    if (first == nullptr) {
        return false;
    }

    if (second == nullptr) {
        return false;
    }

    std::string firstName = first->getName();
    std::string secondName = second->getName();
    if ((firstName < secondName)) {
        return true;
    }
    else if(firstName == secondName) {
        return first->getAge() > second->getAge(); 
    }

    return false;
}

// Метод вывода информации в неосортированном виде    
std::ostream& Forest::print(std::ostream& out) const
{
    size_t size = this->arrWithTrees.size();
    for (size_t i = 0; i < size; ++i) {
        if (arrWithTrees[i] != nullptr) { 
            arrWithTrees[i]->print(out);
            out << "################################" << std::endl;
        }
    }
    return out;
}

// Метод вывода информации в осортированном виде
std::ostream& Forest::sortPrint(std::ostream& out) const
{
    std::vector<Tree*> temp = this->arrWithTrees;
    std::sort(temp.begin(), temp.end(), compareByNameAndAge);
   
    size_t size = temp.size();
    for (size_t i = 0; i < size; ++i) {
        if (temp[i] != nullptr) {
            temp[i]->print(out);
            out << "################################" << std::endl;
        }
    }
    return out;
}

// Метод подсчёта количества деревьев определённого типа
size_t Forest::countingType(TreeType seekType) const
{
    size_t count = 0;
    size_t size = this->arrWithTrees.size();
    for (size_t i = 0; i < size; ++i) {
        if (this->arrWithTrees[i] != nullptr && this->arrWithTrees[i]->getType() == seekType) {
            ++count;
        }
    }
    
    return count;
}

// Метод подсчёта колличества деревьев определённого вида
size_t Forest::countingView(Tree* seekView) const
{
    size_t count = 0;
    size_t size = this->arrWithTrees.size();

    if(dynamic_cast<ForestTree*>(seekView)) {
        for (size_t i = 0; i < size; ++i) {
            if(dynamic_cast<ForestTree*>(this->arrWithTrees[i])) {
                ++count;
            }
        }   
        return count;
    }
    if(dynamic_cast<FruitTree*>(seekView)) {
        for (size_t i = 0; i < size; ++i) {
            if(dynamic_cast<FruitTree*>(this->arrWithTrees[i])) {
                ++count;
            }
        }
        return count;
    }

    throw std::invalid_argument("Ptr to tree must be convert to forest tree or fruit tree...");
}

// Метод добавление в поток
void Forest::pushBack(Tree* newTree)
{
    this->arrWithTrees.push_back(newTree);
}

// Метод получения размера контейнера
size_t Forest::size() const
{
    return this->arrWithTrees.size();
}


    /*===============================================*/
    /*================== Операторы ==================*/
    /*===============================================*/

// Оператор ввода
std::istream& operator>>(std::istream& in, Forest& source)
{
    std::string type;
    std::string name;
    std::string veiw;
    std::string con("Coniferous");
    std::string dec("Deciduous");
    size_t age;
    size_t woodAmount;
    size_t cropeMass;
    size_t storageDuration;
    Tree* newTree = nullptr;

    while(in >> type) {
        if((type == con) || (type == dec)) {
            in >> name;
            in >> age;
            in >> veiw;
            if (veiw == "forest") {
                in >> woodAmount;
                newTree = new ForestTree(name, (type == con ? TreeType::Coniferous : TreeType::Deciduous), age, woodAmount);
                source.pushBack(newTree);
            }   
            else if (veiw == "fruit") {
                in >> cropeMass;
                in >> storageDuration;
                newTree = new FruitTree(name, (type == con ? TreeType::Coniferous : TreeType::Deciduous), age, cropeMass, storageDuration);
                source.pushBack(newTree);
            }
            else {
                throw std::invalid_argument("Error: Invalid argument");
            }
        }
        else {
            throw std::invalid_argument("Error: Invalid argument");
        }
    }

    return in;
}
