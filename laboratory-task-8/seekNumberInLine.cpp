#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include "seekNumbersInLine.hpp"


void getText(std::string& line, const char* parametr = "") {
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


bool isNaturallNumeric(std::string word) {
    try{
        int32_t num = std::stoi(word);
        if(num <= 0) {
            return false;
        }
        return true;
    }catch(std::invalid_argument){
        return false;
    }
}


bool isArmstrogNumber(std::string word) {
    if (isNaturallNumeric(word)) {
        int32_t number = std::stoi(word);
        uint32_t lenNumber = word.length();
        int32_t sumNumbers = 0;
        int32_t num;
        for (size_t i = 0; i < lenNumber; ++i) {
            num = static_cast<int32_t>(word[i]) - '0';
            sumNumbers += std::pow(num, lenNumber);
        }
        if (number == sumNumbers) { 
            return true; 
        }else { 
            return false; 
        }
    }else{
        return false;
    }
}


void findArmstrongsWords(std::string line, std::string delimiters, std::string& armstrongNumbers) {
    size_t indexFirstCharctar = line.find_first_not_of(delimiters);
    size_t indexFinishCharctar = 0;
    bool lineDontHaveArmstrongNamber = true;
    while (indexFinishCharctar < line.size()) {
        indexFinishCharctar = line.find_first_of(delimiters, indexFirstCharctar);
        if (indexFinishCharctar == line.npos) {
            indexFinishCharctar = line.length();
        }
        std::string word = line.substr(indexFirstCharctar, (indexFinishCharctar - indexFirstCharctar));
        if (isArmstrogNumber(word)) {
            lineDontHaveArmstrongNamber = false;
            armstrongNumbers.append(word);
            armstrongNumbers.append(" ");
        }
        indexFirstCharctar = line.find_first_not_of(delimiters, indexFinishCharctar);
    }
    if (lineDontHaveArmstrongNamber) {
        armstrongNumbers = "Armstrong numbers not founded...";
    }
}
