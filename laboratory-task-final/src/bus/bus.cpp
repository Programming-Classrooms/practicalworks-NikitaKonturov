#include "bus.hpp"

/*===========================================================*/
/*====================== Конструкторы =======================*/
/*===========================================================*/


// По умолчанию
Bus::Bus() : busRoute(0), driver(""), busNumber(0), marckBus("") 
{}

// Копирования
Bus::Bus(const Bus &source) : busRoute(source.busRoute), 
                              driver(source.driver), 
                              busNumber(source.busNumber), 
                              marckBus(source.marckBus) 
{}

// С параметрами
Bus::Bus(uint8_t sBusRoute, std::string sDriver, uint8_t sBusNumber, std::string sMarckBus) : busRoute(sBusRoute), 
                                                                                              driver(sDriver), 
                                                                                              busNumber(sBusNumber), 
                                                                                              marckBus(sMarckBus) 
{}

/*===========================================================*/
/*======================== Операторы ========================*/
/*===========================================================*/

// Вывод
std::ostream &operator<<(std::ostream &out, const Bus &source)
{
    out << static_cast<int>(source.busRoute) << " " << source.driver << std::setw(4) << static_cast<int>(source.busNumber) << " " << source.marckBus;

    return out;
}

// Ввод
std::istream &operator>>(std::istream &in, Bus &source)
{
    std::string line;
    std::getline(in, line);
    if (line.empty()) { // Фишка позволяющая не кидать исключения а устанавливать поток в fail
        in.setstate(std::ios_base::failbit);
        return in;
    }   
    std::regex delim("\\s+");
    std::sregex_token_iterator word(line.begin(), line.end(), delim, -1);
    std::sregex_token_iterator end;
    if(word == end) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    try{
        source.busRoute = std::stoi(*word);
    }
    catch(std::invalid_argument &err) {
        in.setstate(std::ios_base::failbit);
        return in;
    }
    
    ++word;
    if(word == end) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    source.driver = *word;

    ++word;
    if(word == end) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    try{ // необходим для проверки на коректное значение номера
        source.busNumber = std::stoi(*word);
    }
    catch(std::invalid_argument &err) {
        in.setstate(std::ios_base::failbit);
        return in;
    }
    
    ++word;
    if(word == end) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    source.marckBus = *word;
    
    return in;
}


/*===========================================================*/
/*========================= Геттеры =========================*/
/*===========================================================*/


uint8_t Bus::getBusRoute() const
{
    return this->busRoute;
}

std::string Bus::getDriver() const
{
    return this->driver;
}

uint8_t Bus::getBusNumber() const
{
    return this->busNumber;
}

std::string Bus::getMarckBus() const
{
    return this->marckBus;
}
