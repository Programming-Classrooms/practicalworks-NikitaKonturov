#include "Train.hpp"

/*======================================================*/
/*==================== Конструторы =====================*/
/*======================================================*/

Train::Train(size_t sTrainNumber, std::string sDestonation, Time sDepartureTime, Time sTravelTime, trainType sTypeOfTrain) : trainNumber(sTrainNumber), destination(sDestonation), typeOfTrain(sTypeOfTrain)
{}


/*======================================================*/
/*====================== Сетеры ========================*/
/*======================================================*/

void Train::setTrainNumber(size_t sTrainNumber)
{
    if (sTrainNumber == 0) {
        throw std::invalid_argument("Train number must have natural number...");
    }
    this->trainNumber = sTrainNumber;
}

void Train::setDestination(std::string sDestination)
{
    this->destination = sDestination;
}

void Train::setDepartureTime(Time sDepartureTime)
{
    this->departureTime = sDepartureTime;
}

void Train::setTravelTime(Time sTravelTime)
{
    this->travelTime = sTravelTime;
}

void Train::setTupeOfTrain(trainType sTypeOfTrain) 
{
    this->typeOfTrain = sTypeOfTrain;
}


/*======================================================*/
/*====================== Гетеры ========================*/
/*======================================================*/


size_t Train::getTrainNumber() const 
{
    return this->trainNumber;
}

std::string Train::getDestination() const
{
    return this->destination;
}

double Train::getDepartureTime() const 
{
    return this->departureTime.getTime();
}

double Train::getTravelTime() const
{
    return this->travelTime.getTime();
}

trainType Train::getTypeOfTrain() const
{
    return this->typeOfTrain; 
}


/*======================================================*/
/*===================== Операторы ======================*/
/*======================================================*/

std::ostream& operator<<(std::ostream& out, const Train& source)
{
    out << "Номер поезда: "<< source.trainNumber << std::endl;
    out << "Пункт назначения: " << source.destination << std::endl;
    out << "Тип поезда: " << ((source.typeOfTrain == trainType::Passenger) ? "Passenger":"Express") << std::endl;
    out << "Время отправления: " << std::setprecision(4) << source.departureTime << std::endl;
    out << "Впемя в пути: " << std::setprecision(4) << source.travelTime << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Train& source)
{
    size_t numberOfTrain = 0;
    std::string destination = "";
    std::string typeOfTrain = "Passenger";
    Time departureTime = {0, 0};
    Time travelTime = {0, 0};

    in >> numberOfTrain;
    if (in.fail()) {
        in.setstate(std::ios_base::failbit);
        return in;
    }
    
    in >> destination;
    if (in.fail()) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    in >> typeOfTrain;
    if (in.fail() || typeOfTrain != "Passenger" && typeOfTrain != "Express") {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    in >> departureTime;
    if (in.fail()) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    in >> travelTime;
    if (in.fail()) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    source.trainNumber = numberOfTrain;
    source.destination = destination;
    source.typeOfTrain = (typeOfTrain == "Passenger" ? trainType::Passenger : trainType::Express);
    source.departureTime = departureTime;
    source.travelTime = travelTime;    

    return in;
}