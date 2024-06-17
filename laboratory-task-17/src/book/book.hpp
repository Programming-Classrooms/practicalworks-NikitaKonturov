
#ifndef BOOK_HPP
#define BOOK_HPP
#include<vector>
#include<iostream>
#include<iterator>
#include<stdint.h>
#include<regex>
#include<set>
#include"../genISBN/genISBN.hpp"


class Book 
{
private:
    static std::vector<uint8_t> permutation;
    static std::vector<int8_t> direction;
    std::string ISBN;
    std::string title;
    std::set<std::string> authors;
    size_t price;
    size_t count;

// Генерация ISBN
    std::string genISBN();
public:
    
/*===================== Конструкторы =====================*/

// По умолчанию
    Book();
// Копирования 
    Book(const Book&);
// С параметрами
    Book(std::string, std::set<std::string>, size_t, size_t);
// Со списком инициализации
    Book(std::string, std::initializer_list<std::string>, size_t, size_t);
// Деструктор
    ~Book() = default;


/*======================== Гетеры ========================*/

// Получение ISDN
    std::string getISBN() const;
// Получение списка авторов
    std::set<std::string> getAuthors() const;
// Получение названия
    std::string getTitle() const;
// Получение цены
    size_t getPrice() const;
// Получение количества
    size_t getCount() const;


/*======================== Cетеры ========================*/

// Добавление автора
    void addAuthor(std::string);
// Удаление автора
    void deleteAuthor(std::string);
    
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
