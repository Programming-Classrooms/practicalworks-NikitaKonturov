#include <iostream>
#include <random>
#include <Windows.h>
#include "WorckWithMatrix.h"

void main() {
	SetConsoleCP(1225);
	SetConsoleOutputCP(1225);
	srand(time(0));
	int32_t** matrix;
	size_t colums = 0;
	size_t rows = 0;
	getRowsAndCollows(rows, colums);
	MatrixDefine(matrix, rows, colums);
	fillingMatrixWithVatiants(matrix, rows, colums);
	printMatrix(matrix, rows, colums);
	sumEllementInColumsWithNull(matrix, rows, colums);
	SortLines(matrix, rows, colums);
	printMatrix(matrix, rows, colums);
	delMatrix(matrix, rows);
	delete[] matrix;



	
}