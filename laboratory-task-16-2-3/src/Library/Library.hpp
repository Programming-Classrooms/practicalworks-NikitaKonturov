#ifndef LIBRARY
#define LIBRARY
#include<map>
#include<iterator>
#include<algorithm>
#include<functional>
#include"../book/book.hpp"


class Library
{
private:
    std::multimap<std::string, Book> lib;
public:
    
/*================= Конструкторы =================*/
    
// По умолчанию
    Library();
// Копирования
    Library(const Library&);
// Деструктор
    ~Library() = default;

/*==================== Сетеры ====================*/

// Добавление книги
    void insert(const Book&);
// Удаление книги
    void ereas(const Book&);
//  Удаление автора
    void eraseAuthor(Book&, const Author&);
//  Добавление автора
    void addAuthor(const Book&, const Author&);

/*==================== Гетеры ====================*/

// Поиск по названию
     std::multimap<size_t, Book> find(std::string&) const;
// Поик по автору
    std::multimap<std::string, Book> find(Author&) const;


/*=================== Операторы ===================*/

// Вывод в поток
    friend std::ostream& operator<<(std::ostream&, const Library&);

};

#endif //LIBRARY
