#ifndef SWAPLINES_HPP
#define SWAPLINES_HPP
#include <string>
#include <vector>


bool checkFile(std::ifstream& file);
std::string getSearchWordsFromFile(std::string path);
std::vector<std::string> getMainTextFromFile(std::string path);
void swapLinesInText(std::vector<std::string>& vectorWithAllLines, std::string words);
int32_t searchLineInText(std::vector<std::string> vectorWithAllLines, std::string word);
bool lineItHasWord(std::string line, std::string word);
void writeTextInFile(std::vector<std::string> mainText, std::string searchWords, std::string path);

#endif //  SWAPLINES_HPP
