#include "list.hpp"


template<typename T>
struct List<T>::Node {
	T item;
	Node* next;
	Node();
};


/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор по умолчанию для эллемента
template<typename T>
List<T>::Node::Node() : item(T()), next(nullptr)
{}

// Конструктор по умолчанию
template<typename T>
List<T>::List()
{	
	this->size = 0;
	this->root = nullptr;
}

// Конструктор копирования
template<typename T>
List<T>::List(List<T> &source)
{
	this->root = nullptr;
	this->size = 0;
	for (size_t i = 0; i < source.getSize(); ++i) {
		this->pushBack(source[i]);
	}
}

// Деструктор
template<typename T>
List<T>::~List()
{
	Node* nextRoot = root;
	while (this->root != nullptr) {
		nextRoot = root->next;
		delete root;
		root = nextRoot;
	}
}


/*==========================================================*/
/*==========М етоды для работы со списком ==================*/
/*==========================================================*/

// Добавление эллемента в конец списка
template<typename T>
void List<T>::pushBack(const T& item) 
{
	if (this->root == nullptr) {
		this->root = new Node;
		this->root->item = item;
		this->root->next = nullptr;
		++size;
	}
	else {
		Node* node = root;
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new Node;
		node = node->next;
		node->item = item;
		node->next = nullptr;
		++size;
	}
}

// Добавление элемента в начало списка
template<typename T>
void List<T>::pushFront(const T& item)
{
	if (this->root == nullptr) {
		this->root = new Node;
		this->root->item = item;
		this->root->next = nullptr;
		++size;
	}
	else {
		Node* tempNode = root;
		this->root = new Node;
		this->root->item = item;
		this->root->next = tempNode;
		++size;
	}
}

// Удаление элемента из списка по индексу
template<typename T>
void List<T>::deleteItem(size_t pos)
{
	if (pos >= this->size) {
		throw std::out_of_range("Out of range...");
	}
	if (this->root == nullptr || this->root->next == nullptr) {
		return;
	}
	Node* node = root;
	if (pos == 0) {
		Node* tempRoot = this->root->next;
		delete this->root;
		this->root = tempRoot;
		--size;
	}
	else
	{
		for (size_t i = 0; i < pos  - 1; ++i) {
			node = node->next;
		}
		Node* tempNode;
		tempNode = node->next->next;
		delete node->next;
		node->next = tempNode;
		--size;
	}
}

// Удаление эллемента по значению
template<typename T>
void List<T>::deleteItem(const T& ellem, size_t& count)
{
    this->deleteItem(this->find(ellem, count));
}

// Поиск эллемента по значению
template<typename T>
int64_t List<T>::find(const T& ellem, size_t& countOfEqual) const
{
    if (this->root == nullptr) {
        throw std::logic_error("List is empty...");
    }
    countOfEqual = 0;
    for (Node* node = root; node != nullptr; node = node->next, ++countOfEqual) {
        if (node->item == ellem) {
            return countOfEqual;
        }
    }
    
    return -1;
}

// Вставка элемента в список по индексу
template<typename T>
void List<T>::insert(size_t pos, T item)
{
	if (pos >= this->size) {
		throw std::out_of_range("Going beyond the list...");
	}
	if (pos == 0) {
		Node* tempNode = this->root;
		this->root = new Node;
		this->root->item = item;
		this->root->next = tempNode;
		++size;
	}
	else {
		Node* node = this->root;
		for (size_t i = 0; i < pos - 1; ++i) {
			node = node->next;
		}
		Node* tempNode = node->next;
		node->next = new Node;
		node = node->next;
		node->item = item;
		node->next = tempNode;
		++size;
	}
}

// Вставка списка в другой список
template<typename T>
void List<T>::merge(List<T>& source, size_t pos)
{
	if (source.empty()) {
		throw std::logic_error("source is empty...");
	}
	if (pos > size) {
		throw std::out_of_range("Going beyond the list...");
	}

	if (pos == 0) {
		Node* tempNode = this->root;
		this->root = new Node;
		Node* node = this->root;
		for (size_t i = 0; i < source.getSize(); ++i) {
			node->item = source[i];
			node->next = new Node;
			if (i == source.getSize() - 1) {
				break;
			}
			node = node->next;
		}
		node->next = tempNode;
	}
	else {
		Node* tempNode = this->root;
		Node* node = this->root;
		for (size_t i = 0; i < pos - 1; ++i) {
			node = node->next;
		}
		tempNode = node->next;
		node->next = new Node;
		for (size_t i = 0; i < source.getSize(); ++i) {
			node = node->next;
			node->item = source[i];
			if (i == source.getSize() - 1) {
				break;
			}
			node->next = new Node;
		}
		node->next = tempNode;
	}
	this->size += source.getSize();
}

// Инвертирование списка 
template<typename T>
void List<T>::revers()
{
	Node* firstNode = this->root;
	Node* secondNode = this->root;
	for (size_t i = 0, j = this->size - 1; i < j; ++i, --j) {
		firstNode = this->root;
		secondNode = this->root;
		for (size_t k = 0; k < i; ++k) {
			firstNode = firstNode->next;
		}
		for (size_t k = 0; k < j; ++k) {
			secondNode = secondNode->next;
		}
		T tempItem = firstNode->item;
		firstNode->item = secondNode->item;
		secondNode->item = tempItem;
	}
}

// Очистка списка
template<typename T>
void List<T>::clear()
{
	if (this->root == nullptr) {
		return;
	}
	for (size_t i = this->size - 1; i > 0; --i) {
		deleteItem(i);
	}
	deleteItem(0);
	this->root = nullptr;
	this->size = 0;
}

// Проверка списка на пустоту
template<typename T>
bool List<T>::empty() const
{
	return this->root == nullptr;
}

// Вывод списка в косоль
template<typename T>
void List<T>::printList() const
{
	Node* node = this->root;
	if (this->root == nullptr) {
		std::cout << "List is empty....";
	}
	while (node != nullptr) {
		std::cout << node->item << " ";
		node = node->next;
	}
	std::cout << std::endl;
} 

// Получение размера списка
template<typename T>
size_t List<T>::getSize() const
{
	return this->size;
}

// Просмотр списка с изменением всех его значений
template<typename T>
void List<T>::editList()
{
	Node* node = this->root;
	for (size_t i = 0; node != nullptr; ++i, node = node->next) {
		std::cout << i << " Item has value: " << node->item << " Enter new value: ";
		std::cin >> node->item;
		std::cout << std::endl;
	}
}

// Просмотр спискс вызовом callback функции
template<typename T>
void List<T>::checkList(void func(T)) const
{
	Node* node = this->root;
	for (size_t i = 0; node != nullptr; ++i, node = node->next) {
		func(node->item);	
	}
}


/*==========================================================*/
/*=====================Операторы============================*/
/*==========================================================*/


// Оператор индексации списка
template<typename T>
T& List<T>::operator[](size_t pos)
{
	if (pos >= this->size) {
		throw std::out_of_range("The element at this position is undefined...");
	}
	Node* node = this->root;
	for (size_t i = 0; i < pos; ++i) {
		node = node->next;
	}
	return node->item;
}

// Оператор присваивания
template<typename T>
List<T>& List<T>::operator=(List<T> source)
{
    if(&source == this || source.root == this->root) {
        throw std::logic_error("Self-assignment is not possible..."); 
    }

    this->clear();
    this->root = nullptr;
	this->size = 0;
	for (size_t i = 0; i < source.getSize(); ++i) {
		pushBack(source[i]);
	}

	return *this;
}

// Оператор слияния двух списков
template<typename T>
List<T> List<T>::operator+(List<T>& source)
{
	List<T> res(*this);
	res.merge(source, res.size);
	return res;
}
