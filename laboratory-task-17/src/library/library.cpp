#include "library.hpp"


/*=====================================================*/
/*=================== Конструкторы ====================*/
/*=====================================================*/

// По умолчанию
Library::Library() : lib(std::map<std::string, Book>())
{}
// Копирование
Library::Library(const Library& source) : lib(source.lib) 
{}


/*=====================================================*/
/*====================== Гетеры =======================*/
/*=====================================================*/

// Поиск по ISBN
std::shared_ptr<Book> Library::find(std::string source) const
{
    std::shared_ptr<Book> result;
    std::map<std::string, Book>::const_iterator searchingBookIter = this->lib.find(source);
    if(searchingBookIter == this->lib.end()) {
        result = nullptr;
    }
    else {
        result = std::make_shared<Book>(searchingBookIter->second);
    }

    return result;
}

// Сортировка по названию
std::multimap<std::string, Book> Library::sortAboutTitle() const
{
    std::multimap<std::string, Book> result;

    for(const auto& book : this->lib) {
        result.insert(std::pair<std::string, Book>(book.second.getTitle(), book.second));
    }

    return result;
}


/*=====================================================*/
/*====================== Сетеры =======================*/
/*=====================================================*/

// Добавление книги
void Library::insert(const Book& source)
{
    this->lib.insert(std::pair<std::string, Book>(source.getISBN(), source));
}

// Удаление книги
void Library::ereas(std::string sISBN)
{
    this->lib.erase(sISBN);
}

// Удаление автора
void Library::eraseAuthor(std::string sISBN, std::string sAuthor)
{
    if(this->lib.find(sISBN) == this->lib.end()) {
        return;
    }
    this->lib[sISBN].deleteAuthor(sAuthor);
}

// Добавление автора
void Library::addAuthor(std::string sISBN, std::string sAuthor)
{
    if(this->lib.find(sISBN) == this->lib.end()) {
        return;
    }
    this->lib[sISBN].addAuthor(sAuthor);
}


/*=====================================================*/
/*===================== Операторы =====================*/
/*=====================================================*/

// Вывод в поток
std::ostream& operator<<(std::ostream& out, const Library& source) 
{
    for(const auto& book : source.lib) {
        out << book.second << std::endl;
        out << "##########################################" << std::endl;
    }
    return out;
}
