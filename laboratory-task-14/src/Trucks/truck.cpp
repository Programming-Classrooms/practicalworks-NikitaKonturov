#include "truck.hpp"

/*=============================================*/
/*========== Вспомогательные методы ===========*/
/*=============================================*/

// Клонирование
Truck& Truck::clone(const Truck& source)
{
    this->model = source.model;
    this->weight = source.weight;

    return *this;
}


/*=============================================*/
/*=============== Конструкторы ================*/
/*=============================================*/


// По умолчанию
Truck::Truck() : model(""), weight(0)
{}

// С параметрами
Truck::Truck(std::string sModel, size_t sWeight) : model(sModel), weight(sWeight)
{}

// Копирование
Truck::Truck(const Truck& source)
{
    this->clone(source);
}

/*=============================================*/
/*================== Гетеры ===================*/
/*=============================================*/


// Получение веса тягоча
size_t Truck::getWeight() const
{
    return this->weight;
}

// Получение модели тягоча
std::string Truck::getModel() const
{
    return this->model;
}


/*============================================*/
/*================ Операторы =================*/
/*============================================*/

// Оператор присваивания
Truck& Truck::operator=(const Truck& source)
{
    this->clone(source);
    return *this;
}

// Оператор сравнения
bool Truck::operator==(const Truck& source)
{
    return this->model == source.model && this->weight == source.weight;
}

// Вывод в поток
std::ostream& operator<<(std::ostream& out, const Truck& source)
{
    out << "Model: " << source.model << " Weight: " << source.weight;
    
    return out;
}
