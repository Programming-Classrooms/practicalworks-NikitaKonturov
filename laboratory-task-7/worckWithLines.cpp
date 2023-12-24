#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "worckWithLines.hpp"
#include <exception>
 

 bool checkAllSpace(char* text)
{ 
    for (; *text != '\0'; ++text) { 
        if(*text != ' ') { 
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

size_t seekMaxLenPolindrom(char* text, char* delimiters) 
{ 
    if (!checkAllSpace(text)) { 
        char saveText[300];
        std::strcpy(saveText, text);
        char* word = strtok(saveText, delimiters);
        size_t maxLen = 0;
        while (word != NULL) { 
            if (maxLen < std::strlen(word) && isPalindrom(word)) { 
                 maxLen = std::strlen(word);
            }
            word = strtok(NULL, delimiters);
        }
    return maxLen;
    }
}

void printMaxPolindroms(char* text, char* delimiters, char* newLine) { 
    size_t maxLenPolindrom = seekMaxLenPolindrom(text, delimiters);
    char* word = strtok(text, delimiters);
    while (word != NULL) { 
        if (isPalindrom(word) && maxLenPolindrom == std::strlen(word)) { 
            strcat(newLine, word);
            strcat(newLine, ";");
        }
        word = strtok(NULL, delimiters);
    }
    strcat(newLine, "\0");
}
