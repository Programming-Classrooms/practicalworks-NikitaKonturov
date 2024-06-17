#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <map>
#include "../book/book.hpp"



class Library 
{
private:
    std::map<std::string, Book> lib;
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
    void ereas(std::string);
//  Удаление автора
    void eraseAuthor(std::string, std::string);
//  Добавление автора
    void addAuthor(std::string, std::string);

/*==================== Гетеры ====================*/

// Поиск по ISBN       
    std::shared_ptr<Book> find(std::string) const;
// Сортировка по названию   
    std::multimap<std::string, Book> sortAboutTitle() const;


/*=================== Операторы ===================*/

// Вывод в поток
    friend std::ostream& operator<<(std::ostream&, const Library&);
};


#endif // LIBRARY_HPP