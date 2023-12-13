#pragma once
#include <string>

void getText(std::string& line, const char* parametr);
bool isNaturallNumeric(std::string word);
bool isArmstrogNumber(std::string word);
void findArmstrongsWords(std::string line, std::string delimiters, std::string& armstrongNumbers);
