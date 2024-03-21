#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <cstring>
#include <iostream>
#include <cmath>


class myString 
{
private:
    char *pStr;
    size_t size;
    size_t capacity;

public:

/*========Конструкторы myString========*/
    myString();
    myString(int64_t);
    myString(const myString &);
    myString(myString &&);
    myString(const char *);
    ~myString();


/*======Методы изменения myString======*/

// Метод добавления символа в конец строки

    void push_back(char);

// Метод добавления подстрокиd к концу строки

    void append(const char *);
    void append(const myString &);

// Метод вставки подстроки в строку

    void insert(const char *, size_t);
    void insert(const myString &, size_t);


// Метод замены подстроки

    void replace(const char *, size_t, size_t);
    void replace(const myString &, size_t, size_t);

// Метод очистки myString
    void clear();

/*===================Гетеры===================*/ 

    bool empty() const;
    char *c_str() const;
    size_t getSize() const;
    myString substr(size_t, size_t) const;


/*===================Операторы===================*/
   
/*=======Операторы длля работы со строкой========*/

    myString operator+(const myString &) const;
    void operator=(const myString &);
    char &operator[](size_t);

/*==============Операторы сравнения==============*/  

    bool operator==(const myString &) const;
    bool operator!=(const myString &) const;
    bool operator<(const myString &) const;
    bool operator>(const myString &) const;
    bool operator<=(const myString &) const;
    bool operator>=(const myString &) const;
   

/*========Операторы приобразвания типов========*/

    explicit operator std::string() const;
    explicit operator int64_t() const;
    explicit operator double() const;


// Операторы ввода, вывода
    friend std::ostream &operator<<(std::ostream &, myString &);
    friend std::istream &operator>>(std::istream &, myString &);
    
};

#endif // MYSTRING_HPP
