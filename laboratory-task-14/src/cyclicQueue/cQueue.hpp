#ifndef CQUEUE_HPP
#define CQUEUE_HPP
#include<iostream>
#include<typeinfo>
#include<cstring>


template<typename T>
class CQueue {
protected:
    struct Item
    {
        T value;

        Item();
        Item(T);
        ~Item();

        CQueue<T>::Item& operator=(const CQueue<T>::Item&);

        CQueue<T>::Item& operator=(T);

        bool operator==(T);
    };

    Item* arr;
    int64_t back;
    int64_t front;
    size_t capasity;
    
    void clone(const CQueue&);
    void clear();

public:

/*====================== Конструкторы ======================*/

// Конструктор по умолчанию;
    CQueue();
// Конструктор копирования
    CQueue(const CQueue&);
// Деструктор 
    virtual ~CQueue();

/*======================= Операторы ========================*/

// Оператор присваивания
CQueue& operator=(const CQueue&);
// Оператор индексации
T& operator[](size_t);

/*========================= Методы =========================*/

// Добавление в конец
void push_back(T);
// Удаление из начал
T pop_front();
// Поиск эллемента
int64_t find(T) const;
// Вывод в поток
std::ostream& print(std::ostream&) const;
// Доступ к эллементу по его номеру
T at(size_t) const;
// Получение размера очереди
size_t size() const;

};

#include"cQueue.inl"

#endif // CQUEUE_HPP
