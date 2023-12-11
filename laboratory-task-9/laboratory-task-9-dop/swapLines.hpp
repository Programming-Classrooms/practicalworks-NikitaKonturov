#pragma once
#include <string>
#include <vector>


bool checkFile(std::ifstream& file);

std::pair<std::string, std::string> getSearchWordsFromFile(const char* path);

std::vector<std::string> getMainTextFromFile(const char* path);

void swapLinesInText(std::vector<std::string> &vectorWithAllLines, std::pair<std::string, std::string> words);

int32_t searchLineInText(std::vector<std::string> vectorWithAllLines, std::string word);

bool lineItHasWord(std::string line, std::string word);

void writingTextInFile(std::vector<std::string> mainText, std::pair<std::string, std::string> searchWords, const char* path);
