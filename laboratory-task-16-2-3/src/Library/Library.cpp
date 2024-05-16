#include"Library.hpp"


/*=====================================================*/
/*=================== Конструкторы ====================*/
/*=====================================================*/

// По умолчанию
Library::Library() : lib(std::multimap<std::string, Book>())
{}

// Копирования
Library::Library(const Library& source) : lib(source.lib)
{}


/*=====================================================*/
/*====================== Сетеры =======================*/
/*=====================================================*/

// Добавление книги
void Library::insert(const Book& item)
{
    this->lib.insert(std::pair<std::string, Book>(item.getTitle(), item));
}

// Удаление книги
void Library::ereas(const Book& item) 
{
    this->lib.erase(item.getTitle());
}

// Удаление автора
void Library::eraseAuthor(Book& item, const Author& author)
{
    this->lib.find(item.getTitle())->second.deleteAuthor(author.getName(), author.getSurenaem(), author.getFathername());
}

// Добавление автора
void Library::addAuthor(const Book& item, const Author& author)
{
    this->lib.find(item.getTitle())->second.addAuthor(author.getName(), author.getSurenaem(), author.getFathername());
}


/*=====================================================*/
/*====================== Сетеры =======================*/
/*=====================================================*/

// Поиск по названию
std::multimap<size_t, Book> Library::find(std::string& sTitle) const
{
    auto iter = this->lib.lower_bound(sTitle);
    auto end = this->lib.upper_bound(sTitle);

    std::multimap<size_t, Book> result;

    while (iter != end) {
        result.insert(std::pair<size_t, Book>(iter->second.getDDC(), iter->second));
        ++iter;
    }
    
    return result;
}

// Поиск по автору
std::multimap<std::string, Book> Library::find(Author& sAuthor) const
{
    std::multimap<std::string, Book> result;    

    for(const auto& element : this->lib) {
        if(element.second.getAuthors().find(sAuthor)) {
            result.insert(element);
        }
    }

    return result;
}


/*=====================================================*/
/*==================== Операторы ======================*/
/*=====================================================*/

//Вывод в поток
std::ostream& operator<<(std::ostream& out, const Library& source)
{
    for(auto book : source.lib) {
        std::cout << book.second << std::endl;
        std::cout << "****************************";
    }
    out << std::endl;
    return out;
}