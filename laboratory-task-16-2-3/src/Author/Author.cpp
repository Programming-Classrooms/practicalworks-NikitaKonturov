#include"Author.hpp"


/*=====================================================*/
/*=================== Конструкторы ====================*/
/*=====================================================*/


// По умолчанию
Author::Author(std::string sName, std::string sSureName, std::string sFatherName) : name(sName), sureName(sSureName), fatherName(sFatherName) 
{}

// Копирования 
Author::Author(const Author& source) : name(source.name), sureName(source.sureName), fatherName(source.fatherName)
{}

/*=====================================================*/
/*===================== Геттеры =======================*/
/*=====================================================*/

// Получени имени
std::string Author::getName() const
{
    return this->name;
}

// Получение фамилии
std::string Author::getSurenaem() const
{
    return this->sureName;
}

// Получение отчества
std::string Author::getFathername() const
{
    return this->fatherName;
}


/*=====================================================*/
/*=================== Операторы =======================*/
/*=====================================================*/

// Вывод
std::ostream& operator<<(std::ostream& out, const Author& source)
{
    out << source.name;
    
    if(!source.sureName.empty()) {
        out << " " << source.sureName;
    }

    if(!source.fatherName.empty()) {
        out << " " << source.fatherName;
    }

    return out;
}

// Ввод
std::istream& operator>>(std::istream& in, Author& source)
{   
    source.name = "";
    source.sureName = "";
    source.fatherName = "";
    std::string author;
    std::getline(in, author); 

    if(author.empty()) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    author.erase(0, author.find_first_not_of(" "));
    std::regex delim("\\s+");
    std::sregex_token_iterator name(author.begin(), author.end(), delim, -1);
    std::sregex_token_iterator epmty;
    
    if(name == epmty) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    source.name = *name;
    ++name;

    if(name == epmty) {
        return in;
    }
    
    source.sureName = *name;
    ++name;

    if(name == epmty) {
        return in;
    }
    
    source.fatherName = *name;
    return in;
}

// Присваивание
Author& Author::operator=(const Author& source)
{
    if(this == &source) {
        throw std::invalid_argument("Self-education...");
    }

    this->name = source.name;
    this->sureName = source.sureName;
    this->fatherName = source.fatherName;

    return *this;
}

// Оператор сравнения
bool Author::operator==(const Author& rhs) const
{
    return this->name == rhs.name && this->sureName == rhs.sureName && this->fatherName == rhs.fatherName;
}

// Оператор меньше
bool Author::operator<(const Author& rhs) const
{
    if (this->name == rhs.name) {
        if (this->sureName == rhs.sureName) {
            return this->fatherName < rhs.fatherName;
        }
        return this->sureName < rhs.sureName;
    }
    return this->name < rhs.name;
}

// Оператор больше
bool Author::operator>(const Author& rhs) const
{
    return !(*this < rhs) && !(*this == rhs);
}