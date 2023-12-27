#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "worckWithLines.hpp"
#include <exception>
 
/* 
    A function so cool that it cannot be used otherwise 
    the universe will collapse in all others
    :(
*/ 
bool veryCoolFunction(char* text)
{ 
    for (; *text != '\0'; ++text) { 
        if(*text != ' ') { 
            return false;
        }
    }
    throw std::exception("The text must contain at least one character");
 } 

bool checkAllSpace(char* text)
{
    for (size_t i = 0; text[i] != '\0'; ++i) {
        if (text[i] != ' ') {
            return false;
        }
    }
    throw std::exception("The text must contain at least one character");
}

void getText(char* text,const char* textToWrite) 
{  
    std::cout << "Please enter " << textToWrite << std::endl;
    std::cin.getline(text, 300);
    if (std::strlen(text) == 0) { 
        throw std::exception("Error line is empty...");
    }
}

bool isPalindrom(char* word) 
{ 
    size_t lenWord = strlen(word);
    for (size_t i = 0; i < lenWord / 2; ++i) { 
        if (word[i] != word[lenWord - 1 - i]) { 
            return false;
        }
    }
    return true;
}

void printMaxPolindroms(char* text, char* delimiters, char* newLine) { 
    char* word = strtok(text, delimiters);
    size_t maxLen = 0;
    while (word != NULL) { 
        if (isPalindrom(word) && maxLen < std::strlen(word)) { 
            memset(newLine, 0, 300);
            strcat(newLine, word);
            strcat(newLine, ";");
            maxLen = std::strlen(word);
        }
        else if (maxLen == std::strlen(word)) {
            strcat(newLine, word);
            strcat(newLine, ";");
        }
        word = strtok(NULL, delimiters);
    }
    newLine[std::strlen(newLine) - 1] = '\0';
}
