/*
    Вариаант 4 
    Строки текстового файла input.txt состоят из слов, разделенных одним  или несколькими пробелами.
    Перед первым, а также после последнего слова  строки пробелы могут отсутствовать.
    Требуется определить строки,  содержащие максимальное количество слов.
    Если таких строк несколько,  найти первые 10.
    Результат вывести на консоль в форме, удобной для чтения.
*/

#include <iostream>
#include "workWithFiles.hpp"
#include <Windows.h>


int main()
{ 
    try { 
        SetConsoleCP(1225);
        SetConsoleOutputCP(1225);
        const std::string path = "input.txt";
        std::string mainText = getMainTextFromFile(path);
        std::string linesWithMaxNumberOfWords = seekLinnesWithMaxNumberWords(mainText);
        std::cout << linesWithMaxNumberOfWords << std::endl;
    }
    catch (std::exception &err) { 
        std::cerr << err.what() << std::endl;
    }
    return 0;
}
