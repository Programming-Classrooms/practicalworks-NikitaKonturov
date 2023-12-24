#ifndef SEEKNUMBERINLINE_HPP
#define SEEKNUMBERINLINE_HPP
#include <string>


void getText(std::string& line, const char* parametr);
bool isNaturallNumeric(std::string word);
bool isArmstrongNumber(std::string word);
void findArmstrongsWords(std::string line, std::string delimiters, std::string& armstrongNumbers);

#endif
