#include <fstream>
#include <iostream>
#include <iterator>
#include <exception>
#include <regex>
#include <string>
#include "swapLines.hpp"


bool checkFile(std::ifstream& file)
{
    if (!file.good()) {
        throw std::runtime_error("File not founded...");
    }
    if (!file) {
        file.close();
        throw std::runtime_error("File unopened...");
    }
    if (file.peek() == EOF) {
        file.close();
        throw std::runtime_error("File is epmty...");
    }
    return true;
}

std::string getSearchWordsFromFile(std::string path)
{
    std::ifstream fin(path);
    std::string textWords;
    if (checkFile(fin)) {
        std::getline(fin, textWords);
    }
    fin.close();
    return textWords;
}

std::vector<std::string> getMainTextFromFile(std::string path)
{
    std::ifstream fin(path);
    std::string line;
    std::getline(fin, line);
    std::vector<std::string>vectorWithAllLines;
    if (checkFile(fin)) {
        for (size_t i = 0; std::getline(fin, line); ++i) {
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

void swapLinesInText(std::vector<std::string>& vectorWithAllLines, std::string words)
{
    size_t sizeVectror = vectorWithAllLines.size();
    std::regex delimiters("\\W+");
    std::sregex_token_iterator word(words.begin(), words.end(), delimiters, -1);
    size_t firstLine = searchLineInText(vectorWithAllLines, static_cast<std::string>(*word));
    ++word;
    size_t secondLine = searchLineInText(vectorWithAllLines, static_cast<std::string>(*word));
    if (firstLine != -1 || secondLine != -1) {
        std::swap(vectorWithAllLines[firstLine], vectorWithAllLines[secondLine]);
    }
}

void writingTextInFile(std::vector<std::string> mainText, std::string searchWords, std::string path)
{
    std::ofstream fout(path);
    if (fout.is_open()) {
        fout.clear();
        fout << searchWords << '\n';
        size_t sizeVector = mainText.size();
        for (size_t i = 0; i < sizeVector; i++) {
            fout << mainText[i] << '\n';
        }
        fout.close();
    }
    else {
        throw std::runtime_error("Error file was not opened...");
    }
}
