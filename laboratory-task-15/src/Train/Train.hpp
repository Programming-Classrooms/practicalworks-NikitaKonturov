#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <iostream>
#include <iomanip>
#include <regex>
#include "src/Time/Time.hpp"


enum class trainType {
    Passenger,
    Express
};

class Train {
private:
size_t trainNumber;
std::string destination;
trainType typeOfTrain;
Time departureTime;
Time travelTime;
public:
    Train(size_t = 1, std::string = "", Time = {0, 0}, Time = {0, 0}, trainType = trainType::Passenger);
    ~Train() = default;

    void setTrainNumber(size_t);
    void setDestination(std::string);
    void setDepartureTime(Time);
    void setTravelTime(Time);
    void setTupeOfTrain(trainType);

    size_t getTrainNumber() const;
    std::string getDestination() const;
    double getDepartureTime() const;
    double getTravelTime() const;
    trainType getTypeOfTrain() const;

    friend std::ostream& operator<<(std::ostream&, const Train&);
    friend std::istream& operator>>(std::istream&, Train&);

};


#endif //TRAIN_HPP
