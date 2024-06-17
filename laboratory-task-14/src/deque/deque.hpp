
#ifndef DEQUE_HPP
#define DEQUE_HPP
#include<iostream>
#include<cstring>
#include<typeinfo>
#include<functional>


template<typename  Tinfo>
class TDeque /* дек – двустороння очередь */
{
protected:

struct TDequeItem; // элемент дека

/* указатели на первый и последний элементы в списке */
TDequeItem *front, *rear;
int capasity; // количество элементов в деке
void Erase(); // удаление всех элементов
void Clone(const TDeque&); // Копирование списка
void DeleteItem(TDequeItem*); // удаление элемента по указателю
TDequeItem* PtrByIndex(size_t)const; // указатель на элемент с заданным индексом

public:

TDeque(); // конструктор
TDeque(const TDeque &); // конструктор копирования

virtual ~TDeque(); // деструктор


/*======================= Вставка эллемента =======================*/

void InsFront(Tinfo); // включить элемент в голову дека
void InsRear(Tinfo); // включить элемент в хвост дека

/*======================= Удаление эллеменета ======================*/

bool DelFront(Tinfo &); // исключить элемент из головы дека
bool DelRear(Tinfo &); // исключить элемент из хвоста дека

/*============================= Геттеры ============================*/

const Tinfo& GetByIndex(size_t)const; // получить элемент по индексу

/*============================= Сеттеры ============================*/

void SetByIndex(Tinfo, size_t); // изменить элемент по индексу

/*========================= Просмотры дека =========================*/

void BrowseWithModification(std::function<void(Tinfo&)>); // просмотр с изменением элементов
void BrowseWithoutModification(std::function<void(Tinfo)>) const; // просмотр без изменения элементов

/*============================ Операторы ===========================*/

const TDeque& operator = (const TDeque &);// оператор присваивания

};

#include"deque.inl"

#endif //DEQUE_HPP
