#include "cQueue.hpp"

template<typename T>
CQueue<T>::Item::Item() : value(T())
{}

template<typename T>
CQueue<T>::Item::Item(T source) : value(source)
{}

template<>
CQueue<char*>::Item::Item(char* source)
{
    this->value = new char[strlen(source) + 1];
    strcpy(this->value, source);
}

template<typename T>
CQueue<T>::Item::~Item()
{}

template<>
CQueue<char*>::Item::~Item()
{
    if(this->value != nullptr) {
        delete[] this->value;
    }
}

template<typename T>
typename CQueue<T>::Item& CQueue<T>::Item::operator=(const CQueue<T>::Item& source)
{
    if (this == &source) {
        throw std::invalid_argument("Self-education...");
    }

    this->value = source.value;
    return *this;
}

template<>
CQueue<char*>::Item& CQueue<char*>::Item::operator=(const CQueue<char*>::Item& source)
{
    if (this == &source) {
        throw std::invalid_argument("Self-education...");
    }

    if (this->value != nullptr) {
        delete[] this->value;
    }
    this->value = new char[strlen(source.value) + 1];
    strcpy(this->value, source.value);
    return *this;
}

template<typename T>
typename CQueue<T>::Item& CQueue<T>::Item::operator=(T source)
{
    this->value = source;
    return *this;
}

template<>
CQueue<char*>::Item& CQueue<char*>::Item::operator=(char* source)
{
    if(this->value != nullptr) {
        delete[] this->value;
    }

    if(source == nullptr) {
        this->value = nullptr;
    }
    else {
        this->value = new char[strlen(source) + 1];
        strcpy(this->value, source);
    }
    return *this;
}

template<typename T>
bool CQueue<T>::Item::operator==(T rhs)
{
    return this->value == rhs;
}

template<>
bool CQueue<char*>::Item::operator==(char* rhs)
{
    return !static_cast<bool>(strcmp(this->value, rhs));
}


/*=========================================================================*/
/*======================== Вспомогательные функции ========================*/
/*=========================================================================*/

// Очистка массива
template<typename T>
void CQueue<T>::clear()
{
    delete[] this->arr;
    this->arr = new Item[this->capasity];
    this->back = 0;
    this->front = -1;
}

// Копирование очереди
template<typename T>
void CQueue<T>::clone(const CQueue& source)
{
    this->clear();
    this->capasity = source.capasity;
    this->arr = new Item[this->capasity];
    this->back = source.back;
    this->front = source.front;
    for (size_t i = this->front; i < this->back; ++i) {
        this->arr[i] = source.arr[i];
    }
}   


/*=========================================================================*/
/*============================== Конструкторы =============================*/
/*=========================================================================*/

// По умолчанию
template<typename T>
CQueue<T>::CQueue() : back(0), front(-1), capasity(1000), arr(new Item[1000]) 
{}

// Копирование
template<typename T>
CQueue<T>::CQueue(const CQueue& source) 
{
    this->clone(source);
}

// Деструктор
template<typename T>
CQueue<T>::~CQueue()
{
    if (this->arr != nullptr) {
        delete[] arr;
    }
}


/*=========================================================================*/
/*=============================== Операторы ===============================*/
/*=========================================================================*/

// Оператор присваивания
template<typename T>
CQueue<T>& CQueue<T>::operator=(const CQueue& source)
{
    if(this == &source) {
        throw std::invalid_argument("Self-education...");
    }
    this->clone(source);
}

// Оператор индексации
template<typename T>
T& CQueue<T>::operator[](size_t pos) 
{
    if (this->back == 0 || this->front == -1) {
        throw std::invalid_argument("Queue is epmty...");
    }
    return this->arr[this->front + (pos % this->back)].value;
} 


/*=========================================================================*/
/*================================ Методы =================================*/
/*=========================================================================*/

// Добавление в конец
template<typename T>
void CQueue<T>::push_back(T value)
{
    if (this->capasity == this->back) {
        throw std::out_of_range("CQueue is full...");
    }

    if(this->back == 0) {
        this->front = 0;
    }
    this->arr[back++] = value;
}

// Удаление из начала
template<typename T>
T CQueue<T>::pop_front() 
{
    if (this->front == -1) {
        throw std::out_of_range("CQueue is empty...");        
    }

    T result = this->arr[this->front].value;
    this->arr[this->front++] = T();
    
    return result;
}

template<>
char* CQueue<char*>::pop_front()
{
    if (this->front == -1) {
        throw std::out_of_range("CQueue is empty...");        
    }

    char* result = new char[strlen(this->arr[front].value) + 1];
    strcpy(result, this->arr[this->front].value);

    this->arr[this->front++] = nullptr;

    return result;
}

// Поиск эллемента
template<typename T>
int64_t CQueue<T>::find(T value) const
{
    if(this->back == 0) {
        throw std::invalid_argument("CQueue is empty...");
    }

    for (size_t i = this->front; i < back; ++i) {
        if(this->arr[i] == value) {
            return (i - this->front);
        }
    }
    return -1;
}

// Вывод в поток
template<typename T>
std::ostream& CQueue<T>::print(std::ostream& out) const
{
    if (this->back == 0) {
        out << "CQueue is empty...";
    }
    else {
        for (size_t i = this->front; i < this->back; ++i) {
            out << this->arr[i].value << " ";
        }
    }
    std::cout << std::endl;

    return out;
}
 
// Доступ к эллементу по его номеру
template<typename T>
T CQueue<T>::at(size_t index) const
{
    if(this->back == 0) {
        throw std::invalid_argument("CQueue is empty...");
    }

    return this->arr[this->front + index % this->back].value;
}

template<>
char* CQueue<char*>::at(size_t index) const
{
    if(this->back == 0) {
        throw std::invalid_argument("CQueue is empty...");
    }

    char* result = new char[strlen(this->arr[this->front + index % this->back].value) + 1];
    strcpy(result, this->arr[this->front + index % this->back].value);

    return result;
}

// Получение размера очереди 
template<typename T>
size_t CQueue<T>::size() const
{
    if (this->front == -1) {
        return 0;
    }
    return  (this->back - this->front);
} 
