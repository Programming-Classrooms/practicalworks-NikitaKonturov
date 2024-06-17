#ifndef AUTHORSLIST_HPP
#define AUTHORSLIST_HPP
#include<set>
#include<iostream>
#include<iterator>
#include<algorithm>
#include"../Author/Author.hpp"

class AuthorsList
{
private:
    std::set<Author> list;
public:

/*=================== Конструкторы ===================*/
// По умолчанию
    AuthorsList();
// Копирования
    AuthorsList(const AuthorsList&);
// С параметрами
    AuthorsList(std::set<Author>&);
// Деструктор
    ~AuthorsList() = default;

/*====================== Методы ======================*/
// Добавление в список
    void insert(const Author&);
    void insert(Author&&);
    void emplace(std::string = "", std::string = "", std::string = "");

// Удаление из списка
    void erase(std::string, std::string, std::string);

// Поиск автора 
    bool find(const Author&);

// Получение размера
    size_t size() const;

// Очистка
    void clear();


/*===================== Операторы =====================*/

// Вывод в поток
    friend std::ostream& operator<<(std::ostream&, const AuthorsList&);
// Оператор сравнения
    bool operator==(const AuthorsList&) const;
// Оператор присваивание
    AuthorsList& operator=(const AuthorsList&);
};


#endif // AUTHORSLIST_HPP
