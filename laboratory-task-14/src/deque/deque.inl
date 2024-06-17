
#include "deque.hpp"

template<typename Tinfo>
struct TDeque<Tinfo>::TDequeItem // элемент дека
{
    Tinfo info; // данные
    TDequeItem* next; // указатель на следующий элемент
    TDequeItem* prev; // указатель на предыдущий элемент

    TDequeItem();
    TDequeItem(Tinfo);
    ~TDequeItem();

    Tinfo getInfo() const;
    TDeque<Tinfo>::TDequeItem& operator=(Tinfo&);
    TDeque<Tinfo>::TDequeItem& operator=(const TDequeItem&);
};

template<typename Tinfo>
TDeque<Tinfo>::TDequeItem::TDequeItem() : info(Tinfo()), next(nullptr), prev(nullptr)
{} 

template<typename Tinfo>
TDeque<Tinfo>::TDequeItem::TDequeItem(Tinfo source) : info(source), next(nullptr), prev(nullptr)
{}

template<>
TDeque<char*>::TDequeItem::TDequeItem(char* source) : next(nullptr), prev(nullptr)
{
    this->info = new char[strlen(source) + 1];
    strcpy(this->info, source);
}

template<typename Tinfo>
TDeque<Tinfo>::TDequeItem::~TDequeItem()
{}

template<>
TDeque<char*>::TDequeItem::~TDequeItem()
{
    if (this->info != nullptr) {
        delete[] this->info;
    }
}

template<typename Tinfo>
typename TDeque<Tinfo>::TDequeItem& TDeque<Tinfo>::TDequeItem::operator=(Tinfo& source)
{
    this->info = source;
    return *this;
}

template<>
typename TDeque<char*>::TDequeItem& TDeque<char*>::TDequeItem::operator=(char*& source)
{
    if (this->info != nullptr) {
        delete[] this->info;
    }

    this->info = new char[strlen(source) + 1];
    strcpy(this->info, source);

    return *this;
}

template<typename Tinfo>
typename TDeque<Tinfo>::TDequeItem& TDeque<Tinfo>::TDequeItem::operator=(const TDeque<Tinfo>::TDequeItem& source)
{
    this->info = source;
    return *this;
}

template<>
TDeque<char*>::TDequeItem& TDeque<char*>::TDequeItem::operator=(const TDeque<char*>::TDequeItem& source)
{
    if (this->info != nullptr) {
        delete[] this->info;
    }

    this->info = new char[strlen(source.info) + 1];
    strcpy(this->info, source.info);

    return *this;
}

template<typename Tinfo>
Tinfo TDeque<Tinfo>::TDequeItem::getInfo() const
{
    return this->info;
}

template<>
char* TDeque<char*>::TDequeItem::getInfo() const
{
    char* result = new char[strlen(this->info) + 1];
    strcpy(result, this->info);
    return result;
}


/*=========================================================================*/
/*======================== Вспомогательные методы =========================*/
/*=========================================================================*/


//По умолчанию
template<typename Tinfo>
TDeque<Tinfo>::TDeque() : capasity(0), front(nullptr), rear(nullptr)
{}

//Удаление всех эллемнтов
template<typename Tinfo>
void TDeque<Tinfo>::Erase()
{
    if (this->front != nullptr && this->rear != nullptr) {
        while(this->front->prev != nullptr) {
            this->front = this->front->prev;
            delete this->front->next;
        }
        delete this->front;
        this->front = nullptr;
        this->rear = nullptr;
        this->capasity = 0;    
    }
}

//Копирование списка
template<typename Tinfo>
void TDeque<Tinfo>::Clone(const TDeque& source)
{
    this->Erase();
    if (source.front == nullptr || source.rear == nullptr) {
        this->front = nullptr;
        this->rear = nullptr;
        this->capasity = 0;
        return;
    }
    
    TDequeItem* iteratorForSource = source.rear;
    this->rear = new TDequeItem;
    *this->rear= *iteratorForSource;
    iteratorForSource = iteratorForSource->next;
    this->rear->prev = nullptr;
    TDequeItem* iteratorForThis = this->rear;


    while (iteratorForSource != nullptr) {
        iteratorForThis->next = new TDequeItem;
        iteratorForThis->next->prev = iteratorForThis;
        *iteratorForThis->next = *iteratorForSource;
        iteratorForSource = iteratorForSource->next;
        iteratorForThis = iteratorForThis->next;
    }
    iteratorForThis->next = nullptr;
    this->front = iteratorForThis;
    this->capasity = source.capasity;
}

//Удаление элемента по указателю
template<typename Tinfo>
void TDeque<Tinfo>::DeleteItem(TDequeItem* item)
{
    if (item == nullptr) {
        throw std::invalid_argument("Pointer must be unequal nullptr...");
    }
    if(item->prev != nullptr) {
        item->prev->next = item->next;
    }
    if(item->next != nullptr) {
        item->next->prev = item->prev;
    }
    --this->capasity;
    delete item;
}

// Указатель на эллемент с заданным индексом
template<typename Tinfo>
typename TDeque<Tinfo>::TDequeItem* TDeque<Tinfo>::PtrByIndex(size_t index) const
{
    if(index >= capasity) {
        throw std::out_of_range("Index must be within the capasity limits...");
    }
    size_t mid = this->capasity >> 1;
    TDequeItem* node = nullptr;
    if(index < mid) {
        node = this->rear;
        for (size_t i = 0; i < index; ++i) {
            node = node->next;
        }
    }
    else {
        node = this->front;
        for (size_t i = 0; i < (capasity - index); ++i) {
            node = node->prev;
        }
    }

    return node;
}


/*==============================================================================*/
/*=============================== Конструкторы =================================*/
/*==============================================================================*/

//Копирования
template<typename Tinfo>
TDeque<Tinfo>::TDeque(const TDeque& source)
{
    this->Clone(source);
}

template<typename Tinfo>
TDeque<Tinfo>::~TDeque() 
{
    this->Erase();
}


/*==============================================================================*/
/*=========================== Вставка эллемента ================================*/
/*==============================================================================*/

// Включение эллемента в голову дека
template<typename Tinfo>
void TDeque<Tinfo>::InsFront(Tinfo value)
{
    if(this->front == nullptr) {
        this->front = new TDequeItem;
        this->rear = this->front;
        this->front->next = nullptr;
        this->rear->prev = nullptr;
        *this->front = value;
        ++this->capasity;
        return;
    }

    this->front->next = new TDequeItem;
    this->front->next->prev = this->front;
    this->front = this->front->next;
    *this->front = value;
    this->front->next = nullptr;
    ++this->capasity;
}


// Включение эллемента в хвост дека
template<typename Tinfo>
void TDeque<Tinfo>::InsRear(Tinfo value)
{
    if(this->rear == nullptr) {
        this->rear = new TDequeItem;
        this->front = this->rear;
        this->front->next = nullptr;
        this->rear->prev = nullptr;
        *this->rear = value;
        ++this->capasity;
        return;
    }

    this->rear->prev = new TDequeItem;
    this->rear->prev->next = this->rear;
    this->rear = this->rear->prev;
    *this->rear = value;
    this->rear->prev = nullptr;
    ++this->capasity;
}


/*==============================================================================*/
/*=========================== Удаление элемента ================================*/
/*==============================================================================*/


// Исключение элемента из головы дека
template<typename Tinfo>
bool TDeque<Tinfo>::DelFront(Tinfo& source) 
{
    if (this->front == nullptr) {
        return false;
    }
    source = this->front->getInfo();
    this->front = this->front->prev;
    this->DeleteItem(this->front->next);
    return true;
}

// Исключение элемента
template<typename Tinfo>
bool TDeque<Tinfo>::DelRear(Tinfo& source)
{
    if (this->rear == nullptr) {
        return false;
    }
    source = this->rear->getInfo();    
    this->rear = this->rear->next;
    this->DeleteItem(this->rear->prev);
    return true;
}


/*==============================================================================*/
/*================================ Геттеры =====================================*/
/*==============================================================================*/

// Получение эллемента по индексу
template<typename Tinfo>
const Tinfo& TDeque<Tinfo>::GetByIndex(size_t index) const
{
    return PtrByIndex(index)->info;
}


/*==============================================================================*/
/*================================ Cеттеры =====================================*/
/*==============================================================================*/

// Изменение элемента по индексу
template<typename Tinfo>
void TDeque<Tinfo>::SetByIndex(Tinfo value, size_t index)
{
    PtrByIndex(index)->info = value;
}


/*==============================================================================*/
/*=========================== Просмотры дека ===================================*/
/*==============================================================================*/

// Просмотр с изменением элементов
template<typename Tinfo>
void TDeque<Tinfo>::BrowseWithModification(std::function<void(Tinfo&)> func)
{
    TDequeItem* item = this->rear;
    while (item != nullptr) {
        func(item->info);
        item = item->next;
    }
}

// Просмотр без изменения элементов
template<typename Tinfo>
void TDeque<Tinfo>::BrowseWithoutModification(std::function<void(Tinfo)> func) const
{
    TDequeItem* item = this->rear;
    while (item != nullptr) {
        func(item->info);
        item = item->next;
    }
}


/*==============================================================================*/
/*============================== Операторы =====================================*/
/*==============================================================================*/

// Оператор присваивания
template<typename Tinfo>
const TDeque<Tinfo>& TDeque<Tinfo>::operator=(const TDeque<Tinfo>& source)
{
    if(this == &source) {
        throw std::invalid_argument("Self-education...");
    }
    this->Clone(source);
    return *this;
}
