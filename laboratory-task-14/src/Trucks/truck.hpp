#ifndef TRUCK_HPP
#define TRUCK_HPP
#include<iostream>


class Truck
{
private:
    size_t weight;
    std::string model;

    Truck& clone(const Truck&);
public:
    Truck();
    Truck(std::string, size_t);
    Truck(const Truck&);
    ~Truck() = default;

    size_t getWeight() const;
    std::string getModel()const;

    bool operator==(const Truck&);
    Truck& operator=(const Truck&);

    friend std::ostream& operator<<(std::ostream&, const Truck&);
};

#endif // TRUCK_HPP