
#ifndef BOOK_HPP
#define BOOK_HPP
#include<ctime>
#include<string>
#include<chrono>
#include<sstream>
#include<iostream>
#include"../ListOfAuthors/AuthorsList.hpp"


class Book 
{
private:
    size_t DDC;
    std::string title;
    size_t year;
    AuthorsList authors;
public:
    
/*===================== Конструкторы =====================*/

// По умолчанию
    Book();
// Копирования 
    Book(const Book&);
// С параметрами
    Book(size_t, AuthorsList&, std::string, size_t);
// Деструктор
    ~Book() = default;


/*======================== Гетеры ========================*/

// Получение УДК
    size_t getDDC() const;
// Получение списка авторов
    AuthorsList getAuthors() const;
// Получение названия
    std::string getTitle() const;
// Получение года
    size_t getYear() const;

/*======================== Cетеры ========================*/

// Добавление автора
    void addAuthor(std::string, std::string, std::string);
// Удаление автора
    void deleteAuthor(std::string, std::string, std::string);
    
/*====================== Операторы =======================*/

// Присваивание
    Book& operator=(const Book&);
// Сранение 
    bool operator==(const Book&) const;
// Меньше
    bool operator<(const Book&) const;
// Вывод в поток
   friend std::ostream& operator<<(std::ostream&, const Book&);
// Ввод с потока
    friend std::istream& operator>>(std::istream&, Book&);

};


#endif //BOOK_HPP
