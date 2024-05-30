#ifndef FUNCS_HPP
#define FUNCS_HPP
#include<map>
#include<locale>
#include<fstream>
#include<iostream>
#include"../bus/bus.hpp"

// Проверка файла
void checkFile(std::ifstream& fout, std::string path);
// Чтение из файла в вектор
void readFile(std::string path, std::vector<Bus>& source);
// Заполнение map из vector
void fillingMap(const std::vector<Bus>& resource, std::map<uint8_t, Bus>& source);


#endif //FUNCS_HPP
