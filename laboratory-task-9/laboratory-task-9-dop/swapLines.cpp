#include "swapLines.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <exception>
#include <regex>
#include <string>


bool checkFile(std::ifstream& file) 
{ 
    if (!file.good()) {  
        throw std::exception("File not founded...");
    }
    if (!file) { 
        file.close();
        throw std::exception("File unopened...");
    }
    if (file.peek() == EOF) { 
        file.close();
        throw std::exception("File is epmty...");
    }
    return true;
}

std::pair<std::string, std::string> getSearchWordsFromFile(const char* path) 
{ 
    std::ifstream fin(path);
    std::string textWords;
    if (checkFile(fin)) { 
        std::getline(fin, textWords);
    }
    fin.close();
    std::regex delimiters("\\W+");
    std::sregex_token_iterator word(textWords.begin(), textWords.end(), delimiters, -1);
    std::pair<std::string, std::string> searchWords;
    searchWords.first = *word;
    ++word;
    searchWords.second = *word;
    return searchWords;
}

std::vector<std::string> getMainTextFromFile(const char* path) 
{ 
    std::ifstream fin(path);
    std::string line;
    std::getline(fin, line);
    std::vector<std::string>vectorWithAllLines;
    if (checkFile(fin)) { 
        for (size_t i = 0; std::getline(fin, line); i++){
            vectorWithAllLines.push_back(line);
        }
        fin.close();
        return vectorWithAllLines;
    }
}

bool lineItHasWord(std::string line, std::string word) 
{  
    std::regex delimiters("\\W+");
    for (std::sregex_token_iterator words(line.begin(), line.end(), delimiters, -1), control; words != control; ++words) { 
        if (word == static_cast<std::string>(*words)) { 
            return true;
        }
    }
    return false;
}

int32_t searchLineInText(std::vector<std::string> vectorWithAllLines, std::string word) 
{ 
    size_t vectorSize = vectorWithAllLines.size();
    for (size_t i = 0; i < vectorSize; ++i) {
        if (lineItHasWord(vectorWithAllLines[i], word)) { 
            return i;
        }
    }
    return -1;
}

void swapLinesInText(std::vector<std::string> &vectorWithAllLines, std::pair<std::string, std::string> words) 
{ 
    size_t sizeVectror = vectorWithAllLines.size();
    size_t firstLine = searchLineInText(vectorWithAllLines, words.first);
    size_t secondLine = searchLineInText(vectorWithAllLines, words.second);
    if (firstLine != -1 || secondLine != -1) {
        std::swap(vectorWithAllLines[firstLine], vectorWithAllLines[secondLine]);
    }
}

void writingTextInFile(std::vector<std::string> mainText, std::pair<std::string, std::string> searchWords,const char* path) 
{ 
    std::ofstream fout(path, std::ios::out);
    if (fout.is_open()) { 
        fout << searchWords.first << " " << searchWords.second << '\n';
        size_t sizeVector = mainText.size();
        for (size_t i = 0; i < sizeVector; i++) { 
            fout << mainText[i] << '\n';
        }
        fout.close();
    }
    else { 
        throw std::exception("Error file was not opened...");
    }
}
