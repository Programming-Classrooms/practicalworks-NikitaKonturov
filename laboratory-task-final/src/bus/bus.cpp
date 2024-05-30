#include "bus.hpp"

/*===========================================================*/
/*====================== Конструкторы =======================*/
/*===========================================================*/


Bus::Bus() : busRoute(0), driver(""), busNumber(0), marckBus(0) 
{}

Bus::Bus(const Bus &source) : busRoute(source.busRoute), 
                              driver(source.driver), 
                              busNumber(source.busNumber), 
                              marckBus(source.marckBus) 
{}

Bus::Bus(uint8_t sBusRoute, std::string sDriver, uint8_t sBusNumber, std::string sMarckBus) : busRoute(sBusRoute), 
                                                                                              driver(sDriver), 
                                                                                              busNumber(sBusNumber), 
                                                                                              marckBus(sMarckBus) 
{}

/*===========================================================*/
/*======================== Операторы ========================*/
/*===========================================================*/

std::ostream &operator<<(std::ostream &out, const Bus &source)
{
    out << source.busRoute << " " << source.driver << '\t' << source.busNumber << " " << source.marckBus;

    return out;
}

std::istream &operator>>(std::istream &in, Bus &source)
{
    std::string line;
    std::getline(in, line);
    if (line.empty()) {
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

    try{
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
