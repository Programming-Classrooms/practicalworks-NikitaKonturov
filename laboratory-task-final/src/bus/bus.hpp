#ifndef BUS_HPP
#define BUS_HPP
#include<iostream>
#include<stdint.h>
#include<regex>


class Bus {
private:
    uint8_t busRoute;
    std::string driver;
    uint8_t busNumber;
    std::string marckBus;
public:

/*================== Конструкторы ==================*/ 
    Bus();
    Bus(const Bus& source);
    Bus(uint8_t sBusRoute, std::string sDriver, uint8_t sBusNumber, std::string sMarckBus);
    ~Bus() = default;

/*==================== Операторы ==================*/
    friend std::ostream& operator<<(std::ostream& out, const Bus& source);
    friend std::istream& operator>>(std::istream& in, Bus& source);   

/*==================== Геттеры ====================*/
    uint8_t getBusRoute() const;
    std::string getDriver() const;
    uint8_t getBusNumber() const;
    std::string getMarckBus() const;
};



#endif //BUS_HPP
