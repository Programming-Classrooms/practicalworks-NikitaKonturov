#ifndef FUNCS_HPP
#define FUNCS_HPP
#include<locale>
#include<fstream>
#include<iostream>
#include"../bus/bus.hpp"


void checkFile(std::ifstream& fout, std::string path);
void readFile(std::string path, std::vector<Bus>& source);



#endif //FUNCS_HPP
