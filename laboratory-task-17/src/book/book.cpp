#include "book.hpp"
#define MAIN_PERMUT "0123456789012"

// Перестановка
std::vector<uint8_t> Book::permutation = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
// Вспомогательный вектор направлений
std::vector<int8_t> Book::direction = std::vector<int8_t>(13, -1);


// Генерация перестановки
std::string Book::genISBN()
{
    std::string ISBN(13, ' ');

    generatePermutation(permutation, direction);
    for (size_t i = 0; i < 13; ++i) {
        ISBN[this->permutation[i]] = MAIN_PERMUT[i];
    }

    return ISBN;
}


/*=====================================================*/
/*=================== Конструкторы ====================*/
/*=====================================================*/

// По умолчанию
Book::Book() : authors(std::set<std::string>()), title(""), price(0), count(0), ISBN(genISBN())
{}

// Копирвание
Book::Book(const Book& source) : authors(source.authors), title(source.title), price(source.price), count(source.count), ISBN(source.ISBN)
{}

// C параметрами
Book::Book(std::string sTitle, std::set<std::string> sAuthors, size_t sPrice, size_t sCount) : ISBN(genISBN()), title(sTitle), authors(sAuthors), price(sPrice), count(sCount)
{}

// Со списком инициализации
Book::Book(std::string sTitle, std::initializer_list<std::string> sAuthors, size_t sPrice,  size_t sCount) : ISBN(genISBN()), title(sTitle), authors(sAuthors), price(sPrice), count(sCount)
{}


/*=====================================================*/
/*====================== Гетеры =======================*/
/*=====================================================*/


// Получение ISBN
std::string Book::getISBN() const
{
    return this->ISBN;
}

// Получение списка авторов
std::set<std::string> Book::getAuthors() const
{
    return this->authors;
}

// Получение названий 
std::string Book::getTitle() const
{
    return this->title;
}

// Получение цены
size_t Book::getPrice() const
{
    return this->price;   
}

// Получение количества
size_t Book::getCount() const
{
    return this->count;
}


/*=====================================================*/
/*====================== Cетеры =======================*/
/*=====================================================*/

// Добавление автора
void Book::addAuthor(std::string author)
{
    std::regex unnecessarySpace("\\s+");
    std::regex bounderSpace("^\\s+|\\s+$");

    author = std::regex_replace(author, unnecessarySpace, " ");
    author = std::regex_replace(author, bounderSpace, "");
    this->authors.insert(author);
}

// Ужаление автора
void Book::deleteAuthor(std::string author)
{
    this->authors.erase(author);
}


/*=====================================================*/
/*==================== Операторы ======================*/
/*=====================================================*/

// Присваивание
Book& Book::operator=(const Book& source) 
{
    if(this == &source) {
        throw std::invalid_argument("Self-education...");
    }

    this->authors = source.authors;
    this->ISBN = source.ISBN;
    this->count = source.count;
    this->price = source.price;
    this->title = source.title; 

    return *this;
}

// Сравнение
bool Book::operator==(const Book& rhs) const
{
    return this->ISBN == rhs.ISBN;
}

// Меньше 
bool Book::operator<(const Book& rhs) const
{
    return this->ISBN < rhs.ISBN;
}

// Вывод в поток
std::ostream& operator<<(std::ostream& out, const Book& source)
{
    out << "ISBN: " << source.ISBN << std::endl;
    out << "Title: " << source.title << std::endl;
    out << "Authors: ";
    std::copy(source.authors.begin(), source.authors.end(), std::ostream_iterator<std::string>(std::cout, ", "));
    out << std::endl;
    out << "Price: " << source.price << std::endl;
    out << "Count: " << source.count << std::endl;

    return out;
}

// Ввод с потока
std::istream& operator>>(std::istream& in, Book& source) 
{
    source.count = 0;
    source.ISBN.clear();
    source.price = 0;
    source.title.clear();
    
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
  
    source.title = *element;
    if (++element == empty) {
        in.setstate(std::ios_base::failbit);
        return in;
    }
    
    std::string authors = *element;

    std::regex delimForAuthor(",");
    std::sregex_token_iterator author(authors.begin(), authors.end(), delimForAuthor, -1);

    std::regex unnecessarySpace("^\\s+|\\s+$");
    std::string temp;
    while (author != empty) {
        temp = *author;
        temp = std::regex_replace(temp, unnecessarySpace, "");
        source.authors.insert(temp);
        ++author;
    }

    if (++element == empty) {
        in.setstate(std::ios_base::failbit);
        return in;  
    }

    source.price = std::stoi(*element);

    if (++element == empty) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    source.count = std::stoi(*element);
    source.ISBN = source.genISBN();
    return in;
}
