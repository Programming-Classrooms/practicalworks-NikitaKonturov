#pragma once
#include <string>


bool checkFile(std::ifstream& file);
std::string getMainTextFromFile(const std::string path);
std::string seekLinnesWithMaxNumberWords(std::string textWithAllLines);
size_t countWords(std::string line);
