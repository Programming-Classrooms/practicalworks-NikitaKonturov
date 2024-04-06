#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <exception>

template<typename T>
class List {
private:
	struct Node;
	Node* root;
	size_t size;

public:

/*==========Конструкторы( + деструктор)==========*/
    // Конструктор по умолчанию
	List();
    // Конструктор копирования
	List(List<T> &_);
    // деструктор 
	~List(); 

/*===========Методы для работы со списком===========*/

    // Добавление эллемента в конец списка
	void pushBack(const T&); 
	// Добавление элемента в начало списка
    void pushFront(const T&);
    // Удаление элемента из списка по индексу
    void deleteItem(size_t);
    // Удаление эллемента по значению
    void deleteItem(const T&, size_t&);
    // Поиск эллемента по значению
    int64_t find(const T&, size_t&) const;
    // Вставка элемента в список по индексу
    void insert(size_t, T); 
    // Вставка списка в другой список
	void merge(List<T>&, size_t); 
    // Вывод списка в косоль
	void printList() const;
    // Инвертирование списка 
	void revers();  
	// Очистка списка
	void clear(); 
    // Проверка списка на пустоту
	bool empty() const; 
    // Получение размера списка
	size_t getSize() const; 
    // Просмотр списка с изменением всех его значений
    void editList();
    // Просмотр спискс вызовом callback функции
    void checkList(void func(T)) const;
	
/*===========Операторы для работы со списком===========*/

    // Оператор индексации списка
    T& operator[](size_t); 
	// Оператор присваивания
    List& operator=(List<T>); 
    // Оператор слияния двух списков
	List operator+(List<T>&); 
};

#include"list.inl"

#endif // LIST_HPP