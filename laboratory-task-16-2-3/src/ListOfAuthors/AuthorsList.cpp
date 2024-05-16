#include"AuthorsList.hpp"


/*=====================================================*/
/*=================== Конструкторы ====================*/
/*=====================================================*/

// По умолчанию
AuthorsList::AuthorsList() : list(std::set<Author>())
{}

// Копирования
AuthorsList::AuthorsList(const AuthorsList& source) : list(source.list)
{}

// С параметрами
AuthorsList::AuthorsList(std::set<Author>& source) : list(source)
{}

/*=====================================================*/
/*===================== Методы ========================*/
/*=====================================================*/

// Вставка 
void AuthorsList::insert(const Author& source)
{
    this->list.insert(source);
}

// Вставка с перемещением
void AuthorsList::insert(Author&& source)
{
    this->list.insert(source);
}

// Вставка с параметрами
void AuthorsList::emplace(std::string sName, std::string sSureName, std::string sFatherName)
{
    this->list.emplace(sName, sSureName, sFatherName);
}

// Удаление автора
void AuthorsList::erase(std::string sName, std::string sSureName, std::string sFatherName) 
{
    std::set<Author>::iterator itToElement = list.find(Author(sName, sSureName, sFatherName));
    if (itToElement == this->list.end())
    {
        return;
    }
    else {
        list.erase(itToElement);
    }
}

// Поиск автора
bool AuthorsList::find(const Author& source)
{
    return this->list.find(source) != this->list.end(); 
}

// Получение размера
size_t AuthorsList::size() const
{
    return this->list.size();
}

// Очистка
void AuthorsList::clear()
{
    this->list.clear();
}

/*=====================================================*/
/*==================== Операторы ======================*/
/*=====================================================*/

// Вывод в поток
std::ostream& operator<<(std::ostream& out, const AuthorsList& source)
{
    std::copy(source.list.begin(), source.list.end(), std::ostream_iterator<Author>(out, ", "));
    return out;
}

// Оператор сравнения
bool AuthorsList::operator==(const AuthorsList& rhs) const
{
    if(this->list.size() != rhs.list.size()) {
        return false;
    }
    else {
        for(const auto& author : this->list) {
            if(rhs.list.find(author) == rhs.list.end()) {
                return false;
            }
        }
        return true;
    }
}

// Оператор присваивания
AuthorsList& AuthorsList::operator=(const AuthorsList& source) 
{
    this->list = source.list;
    return *this;
}
