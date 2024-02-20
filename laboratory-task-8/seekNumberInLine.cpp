#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "seekNumbersInLine.hpp"


void getText(std::string& line, const char* parametr = "") 
{ 
    std::cout << "Please enter " << parametr;
    std::getline(std::cin, line);
    if (line.size() == 0) { 
        throw std::exception("Line is empty...");
    }
    bool isFullSpace = true;
    for (size_t i = 0; i < line.size(); ++i) {  
        if (!isspace(line[i])) { 
            isFullSpace = false;
        }
    }
    if (isFullSpace && (strcmp(parametr, "line") == 0)) { 
        throw std::exception("The string should not consist only of spaces");
    }
} 

bool isNaturallNumeric(std::string word) 
{  
    for (size_t i = 0; i < word.size(); ++i) { 
        if (!isdigit(word[i])) { 
            return false;
        }
    }
    return true;
}

bool isArmstrongNumber(std::string word) 
{ 
    if (isNaturallNumeric(word)) { 
        int32_t number = std::stoi(word);
        uint32_t lenNumber = word.length();
        int32_t sumNumbers = 0;
        int32_t num;
        for (size_t i = 0; i < lenNumber; ++i) { 
            num = word[i] - '0';
            sumNumbers += std::pow(num, lenNumber);
        }
        return  number == sumNumbers;
    }
    else {  
        return false;
    }
}

void findArmstrongsWords(std::string line, std::string delimiters, std::string& armstrongNumbers) 
{ 
    size_t indexFirstSymbol = line.find_first_not_of(delimiters);
    size_t indexFinishSymbol = 0;
    bool lineDontHaveArmstrongNamber = true;
    while (indexFinishSymbol < line.size()) { 
        indexFinishSymbol = line.find_first_of(delimiters, indexFirstSymbol);
        if (indexFinishSymbol == line.npos) { 
            indexFinishSymbol = line.length();
        }
        std::string word = line.substr(indexFirstSymbol, (indexFinishSymbol - indexFirstSymbol));
        if (isArmstrongNumber(word)) { 
            lineDontHaveArmstrongNamber = false;
            armstrongNumbers.append(word);
            armstrongNumbers.append(" ");
        }
        indexFirstSymbol = line.find_first_not_of(delimiters, indexFinishSymbol);
    }
    if (lineDontHaveArmstrongNamber) { 
        armstrongNumbers = "Armstrong numbers not founded...";
    }
}
