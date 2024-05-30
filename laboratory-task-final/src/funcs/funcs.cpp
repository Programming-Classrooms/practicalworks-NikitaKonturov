#include "funcs.hpp"

// Проверка файла
void checkFile(std::ifstream &fin, std::string path)
{
    if(!fin) { 
        throw std::invalid_argument(std::string("File was not exist! Path: ") + path);
    }
    if(!fin.is_open()) {
        throw std::invalid_argument(std::string("File was not opened! Path: ") + path);
    }
    if(fin.peek() == EOF) {
        throw std::invalid_argument(std::string("File is empty! Path: ") + path);
    }
}

// Чтение файла
void readFile(std::string path, std::vector<Bus>& source)
{
    std::ifstream fin(path);
    checkFile(fin, path);

    Bus temp;
    while (fin >> temp) {
        source.push_back(temp);
    }
}