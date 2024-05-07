#include "Time.hpp"


Time::Time() : hours(0), minutes(0) 
{}

Time::Time(const Time& source) : hours(source.hours), minutes(source.minutes)
{}

Time::Time(uint8_t sHours, uint8_t sMinutes) 
{
    if (sHours > 23 || sMinutes > 59) {
        throw std::invalid_argument("Time must be less 23.59...");
    }
    this->hours = sHours;
    this->minutes = sMinutes;
}

Time& Time::operator=(const Time& source)
{
    if (this == &source) {
        throw std::invalid_argument("Self-education...");
    }
    this->hours = source.hours;
    this->minutes = source.minutes;

    return *this;
}

double Time::getTime() const
{
    return (static_cast<double>(this->hours) + static_cast<double>(this->minutes) * 0.01);
}

bool Time::operator==(const Time& rhs) const
{
    return this->hours == rhs.hours && this->minutes == rhs.minutes;
}

bool Time::operator<(const Time& rhs) const
{
    return this->hours < rhs.hours || this->minutes < rhs.minutes;  
}

bool Time::operator>(const Time& rhs) const
{
    return !(*this < rhs) && !(*this == rhs);
}

std::ostream& operator<<(std::ostream& out, const Time& source) 
{
    out << (source.hours < 10 ? std::format("0{}", source.hours) : std::to_string(source.hours)) << ":" << (source.minutes < 10 ? std::format("0{}", source.minutes) : std::to_string(source.minutes));
    return out;
}

std::istream& operator>>(std::istream& in, Time& source)
{
    std::string stringTime;
    in >> stringTime;
    std::regex delim(":");
    std::regex timeTemplate("[0-2]{0,1}[0-9]:\\d{1,2}");
    if(!std::regex_match(stringTime, timeTemplate)) {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    std::sregex_token_iterator numbers(stringTime.begin(), stringTime.end(), delim, -1);
    uint8_t hours = std::stoi(*numbers);
    ++numbers;
    uint8_t minutes = std::stoi(*numbers);

    if(hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59) {
        source.hours = hours;
        source.minutes = minutes;
        return in;
    }
    else {
        in.setstate(std::ios_base::failbit);
        return in;
    }
}
