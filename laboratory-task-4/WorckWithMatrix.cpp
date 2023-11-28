#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include "WorckWithMatrix.h"

void getRowsAndCollows(size_t& rows, size_t& colums) {
	int rowsI = 0;
	int columsI = 0;
	while (rowsI <= 0 || columsI <= 0) {
		std::cout << "Please inter colums (this value must be pozitev): ";
		std::cin >> columsI;
		std::cout << "Please inter rows (this value must be pozitev): ";
		std::cin >> rowsI;
	}
	rows = static_cast<size_t>(rowsI);
	colums = static_cast<size_t>(columsI);
}

void MatrixDefine(int32_t**& matrix, size_t rows, size_t colums) {
	matrix = new int32_t*[rows];
	for (size_t i = 0; i < rows; ++i){
		matrix[i] = new int32_t[colums];
	}
}

void fillingMatrixFromKeyboard(int32_t** matrix, size_t rows, size_t colums) {
	int temp;
	for (size_t i = 0; i < rows; ++i){
		for (size_t j = 0; j < colums; ++j){
			std::cin >> temp;
			matrix[i][j] = static_cast<int32_t>(temp);
		}
	}
}

void fillingMatrixFromRandom(int32_t** matrix, size_t rows, size_t colums) {
	int32_t a = 0, b = 0;
	std::cout << "Please enter boards: ";
	std::cin >> a >> b;
	if (a > b) {
		std::swap(a, b);
	}
	//int control = 0;
	for (size_t i = 0; i < rows; ++i){
		for (size_t j = 0; j < colums; ++j){
			
			matrix[i][j] = a + (rand() % (b - a + 1));
		}
	}
}

void printMatrix(int32_t** matrix, size_t rows, size_t colums) {
	for (size_t i = 0; i < rows; ++i){
		for (size_t j = 0; j < colums; ++j){
			
			std::cout << std::setw(3) << matrix[i][j];;
			std::cout << std::setw(3) << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void sumEllementInColumsWithNull(int32_t** matrix, size_t rows, size_t colums) {
	int32_t sum = 0;
	bool chekNulls = false;
	bool haveNulls = false;
	for (size_t j = 0; j < colums; ++j){
		for (size_t i = 0; i < colums; ++i){
			sum += matrix[i][j];
			if (matrix[i][j] == 0) { 
				haveNulls = true;
				chekNulls = true;
			}
		}
		if (haveNulls) {
			std::cout << "Sum ellemens in colum " << j << " -- " << sum << std::endl << std::endl;
		}
		sum = 0;
		haveNulls = false;
	}
	if (!chekNulls) {
		std::cout << "Has not colums with null..."<< std::endl << std::endl;
	}
}

void BubleSortRight(int32_t* line, size_t colums) {
	for (size_t i = 0; i < colums; ++i) {
		for (size_t j = i; j < colums; ++j) {
			if (line[i] > line[j]) std::swap(line[i], line[j]);
		}
	}
}

void BubleSortLeft(int32_t* line, size_t colums) {
	for (size_t i = 0; i < colums; ++i) {
		for (size_t j = i; j < colums; ++j) {
			if (line[i] < line[j]) std::swap(line[i], line[j]);
		}
	}
}

void SortLines(int32_t** matrix, size_t rows, size_t colums) {
	for (size_t i = 0; i < rows; ++i){
		if ((i % 2) == 0) {
			BubleSortRight(matrix[i], colums);
		}
		else if ((i % 2) != 0) {
			BubleSortLeft(matrix[i], colums);
		}
	}
}

void fillingMatrixWithVatiants(int32_t** matrix, size_t rows, size_t colums) {
	int32_t variant = 0;
	while (variant != 1 && variant != 2){
		std::cout << "Please select a variant filling matrix |1 - from keyboard|2 - random filling|: ";
		std::cin >> variant;
	}
	switch (variant) {
		case 1:
			fillingMatrixFromKeyboard(matrix, rows, colums);
			break;
		case 2:
			fillingMatrixFromRandom(matrix, rows, colums);
			break;
	}
}

void delMatrix(int32_t**& matrix, size_t rows) {
	for (size_t i = 0; i < rows-1; ++i){
		delete matrix[i];
	}
}












