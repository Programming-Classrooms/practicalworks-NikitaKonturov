#ifndef TIME_HPP
#define TIME_HPP
#include <iostream>
#include <iomanip>
#include <regex>
#include <format>


class Time
{
private:
    uint8_t hours;
    uint8_t minutes;
public:
    Time();
    Time(uint8_t, uint8_t);
    Time(const Time&);
    ~Time() = default;

    Time& operator=(const Time&);
    double getTime() const;

    bool operator==(const Time&) const;
    bool operator<(const Time&) const;
    bool operator>(const Time&) const;

    friend std::ostream& operator<<(std::ostream&, const Time&);
    friend std::istream& operator>>(std::istream&, Time&);
};

#endif // TIME_HPP
