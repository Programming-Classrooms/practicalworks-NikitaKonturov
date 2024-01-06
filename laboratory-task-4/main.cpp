/*
	Вариант 4
	В целочисленной прямоугольной матрице найти:
	- сумму элементов в столбцах, содержащих хотя бы один ноль;
	- расположить элементы четных строк матрицы по возрастанию, а нечетных - по
	убыванию.
*/

#include <iostream>
#include <random>
#include <Windows.h>
#include <exception>
#include "funcs.hpp"


int main() 
{
	try{
		SetConsoleCP(1225);
		SetConsoleOutputCP(1225);
		srand(time(0));
		int32_t** matrix;
		size_t colums = 0;
		size_t rows = 0;
		getRowsAndCollums(rows, colums);
		matrixDefine(matrix, rows, colums);
		fillingMatrixWithVariants(matrix, rows, colums);
		printMatrix(matrix, rows, colums);
		sumEllementInColumsWithNull(matrix, rows, colums);
		sortLines(matrix, rows, colums);
		printMatrix(matrix, rows, colums);
		mtrxMemClear(matrix, rows);
	}
	catch(std::bad_alloc &e) {
		std::cerr << "Hep is full " << e.what() << std::endl;
	}
	return 0;
}
