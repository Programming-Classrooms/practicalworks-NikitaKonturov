#ifndef MENU_HPP
#define MENU_HPP
#include<format>
#include<fstream>
#include<filesystem>
#include "../Library/Library.hpp"


void checkPath(std::filesystem::path);
void checkFile(std::istream&, std::string);
void menu(std::string = "src/resource/books.txt");

#endif //MENU_HPP
