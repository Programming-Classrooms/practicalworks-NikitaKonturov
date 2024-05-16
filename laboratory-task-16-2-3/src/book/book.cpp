#include "book.hpp"


/*=====================================================*/
/*=================== Конструкторы ====================*/
/*=====================================================*/

// По умолчанию
Book::Book() : DDC(0), authors(AuthorsList()), title(""), year(0)
{}

// Копирвание
Book::Book(const Book& source) : DDC(source.DDC), authors(source.authors), title(source.title), year(source.year)
{}

// C параметрами
Book::Book(size_t sDDC, AuthorsList& sAuthors, std::string sTitle, size_t sYear) : DDC(sDDC), authors(sAuthors), title(sTitle)
{
    tm nowYear;
    time_t nowTime = time(0);
    localtime_r(&nowTime, &nowYear);
    nowYear.tm_year += 1900;
    if(sYear > nowYear.tm_year) {
        throw std::invalid_argument("Invalid year....");
    }
    this->year = sYear;
}


/*=====================================================*/
/*====================== Гетеры =======================*/
/*=====================================================*/

// Получение УДК
size_t Book::getDDC() const
{
    return this->DDC;
}

// Получение списка автор 
AuthorsList Book::getAuthors() const
{
    return this->authors;
}

// Получение название
std::string Book::getTitle() const
{
    return this->title;
} 

// Получение года
size_t Book::getYear() const
{
    return this->year;
}


/*=====================================================*/
/*====================== Cетеры =======================*/
/*=====================================================*/

// Добавлене автора
void Book::addAuthor(std::string sName, std::string sSureName, std::string sFatheName) 
{
    this->authors.emplace(sName, sSureName, sFatheName);
}

// Удаление автора
void Book::deleteAuthor(std::string sName, std::string sSureName, std::string sFatherName)
{
    this->authors.erase(sName, sSureName, sFatherName);
}


/*=====================================================*/
/*==================== Операторы ======================*/
/*=====================================================*/

// Присваивание 
Book& Book::operator=(const Book& source)
{
    this->DDC = source.DDC;
    this->authors = source.authors;
    this->title = source.title;
    this->year = source.year;

    return *this;
}

// Сравнение
bool Book::operator==(const Book& rhs) const
{
    return this->DDC == rhs.DDC && this->authors == rhs.authors && this->title == rhs.title && this->year == rhs.year;
}

// Меньше
bool Book::operator<(const Book& rhs) const
{
    return this->title < rhs.title;
}

// Вывод в поток
std::ostream& operator<<(std::ostream& out, const Book& source)
{
    out << "УДК: "<< source.DDC << std::endl;
    out << "Список авторов: " << source.authors << std::endl;
    out << "Название: " << source.title << std::endl;
    out << "Год: " << source.year << std::endl;

    return out;
}

// Ввод с потока
std::istream& operator>>(std::istream& in, Book& source)
{
    std::string line;
    source.authors.clear();
    std::getline(in, line);
    if(line.empty()) {
        in.setstate(std::ios_base::failbit);
        return in;
    }
    std::regex delim(";");
    std::sregex_token_iterator element(line.begin(), line.end(), delim, -1);
    std::sregex_token_iterator empty;
    if (element == empty) {
        in.setstate(std::ios_base::failbit);
        return in;
    }
    source.DDC = std::stoi(*element);
    if (++element == empty) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    std::string authors = *element;

    std::regex delimForAuthor(",");
    std::sregex_token_iterator author(authors.begin(), authors.end(), delimForAuthor, -1);

    Author temp;
    std::stringstream streamWithAuthor;
    while (author != empty) {
        streamWithAuthor << *author;
        streamWithAuthor >> temp;
        source.authors.insert(temp);
        streamWithAuthor.clear();
        ++author;
    }

    if (++element == empty) {
        in.setstate(std::ios_base::failbit);
        return in;
    }
    source.title = *element;

    if (++element == empty) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    source.year = std::stoi(*element);

    return in;
}