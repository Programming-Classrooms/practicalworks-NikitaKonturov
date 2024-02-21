#ifndef WORKWITHFILES_HPP
#define WORKWITHFILES_HPP
#include <string>


bool checkFile(std::ifstream& file);
std::string getMainTextFromFile(const std::string path);
std::string seekLinesWithMaxNumberWords(std::string textWithAllLines);
size_t countWords(std::string line);

#endif
