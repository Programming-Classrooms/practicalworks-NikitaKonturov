#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <regex>
#include <string>

template<typename T>
void universalQsort(T*, size_t, size_t, bool (*comp)(T, T));

struct Employee {
	std::string surename;
	size_t children;
	~Employee();
};

void printArr(Employee* , int32_t);
void printArr(std::string*, int32_t);
void printArr(int32_t*, int32_t);
std::string toUpper(std::string );
bool checkFile(std::ifstream&, std::string);
std::string getMainText(std::string );
void copySortArrays(int32_t*, int32_t*, int32_t);
std::string getDelimiters(std::string);
bool isWord(std::string);
bool compForStructToUpper(Employee, Employee);
size_t getSizeForArrSurenames(std::string, std::string);
size_t getSizeForArrNumbers(std::string, std::string);
void fillingArr(std::string*, std::string, std::string);
bool compairStrings(std::string, std::string);
void qsortString(std::string*, size_t, size_t);
size_t inputChildren(std::string);
void fillingArrOfStruct(Employee*, int32_t*, std::string*, int64_t, int64_t);
bool compForStructToLower(Employee, Employee);
void writeArrOfStruct(std::ofstream&, Employee*, int64_t);
void writeArrOfStructToBin(std::ofstream&, Employee*, int64_t);
size_t getPointerLast(std::ifstream&, struct Employee&, struct Employee&);

void swapLinesInBinaryFile(std::ofstream&, size_t, struct Employee, struct Employee);


bool isDigit(std::string);

void fillingArr(int32_t*, std::string, std::string);


void menu(Employee*, size_t);


#endif // FUNCS_HPP
