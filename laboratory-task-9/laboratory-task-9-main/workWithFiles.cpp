#include <iostream>
#include "workWithFiles.hpp"
#include <fstream>
#include <regex>


bool checkFile(std::ifstream &file) 
{  
    if (!file.good()) { 
        throw std::exception("File not founded...");
    }
    if (!file) { 
        throw std::exception("File unopened...");
    }
    if (file.peek() == EOF) { 
        file.close();
        throw std::exception("File is epmty...");
    }
    return true;
}

std::string getMainTextFromFile(const std::string path) 
{ 
    std::ifstream fin(path);
    std::string textWithAllLines, line;
    if (checkFile(fin)){
        for (size_t i = 0; std::getline(fin, line); ++i) { 
            textWithAllLines.append(line);
            textWithAllLines.push_back('\n');
        }
        fin.close();
        return textWithAllLines;
    }
}

size_t countWords(std::string line) { 
    std::regex wordsDelimiters("\\s+");
    size_t count = 0;
    for (std::sregex_token_iterator words(line.begin(), line.end(), wordsDelimiters, -1), control; words != control; ++words) { 
        ++count;
    }
    return count;
}

std::string seekLinnesWithMaxNumberWords(std::string textWithAllLines) 
{  
    size_t maxNumberWordsInLine = 0;
    std::regex linesDelimiter("\n");
    std::string linesWithMaxWords, line;
    size_t numberLinesWithMaxWords = 1, numberOfWords;
    for (std::sregex_token_iterator lines(textWithAllLines.begin(), textWithAllLines.end(), linesDelimiter, -1), control; lines != control && numberLinesWithMaxWords <= 10; ++lines) { 
        line = *lines;
        numberOfWords = countWords(line);
        if (maxNumberWordsInLine < numberOfWords) { 
            maxNumberWordsInLine = numberOfWords;
            linesWithMaxWords.clear();
            linesWithMaxWords.append(line);
            linesWithMaxWords.push_back('\n');
            numberLinesWithMaxWords = 1;
        }
        else if (maxNumberWordsInLine == numberOfWords){ 
            linesWithMaxWords.append(line);
            linesWithMaxWords.push_back('\n');
            ++numberLinesWithMaxWords;
        }
    }
    return linesWithMaxWords;
}
