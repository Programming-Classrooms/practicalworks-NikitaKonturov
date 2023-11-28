#pragma once

void getRowsAndCollows(size_t & rows, size_t & colums);

void MatrixDefine(int32_t**& matrix, size_t rows, size_t colums);

void fillingMatrixFromKeyboard(int32_t** matrix, size_t rows, size_t colums);

void fillingMatrixFromRandom(int32_t** matrix, size_t rows, size_t colums);

void printMatrix(int32_t** matrix, size_t rows, size_t colums);

void sumEllementInColumsWithNull(int32_t** matrix, size_t rows, size_t colums);

void BubleSortRight(int32_t** line, size_t colums, size_t row);

void BubleSortLeft(int32_t** line, size_t colums, size_t row);

void SortLines(int32_t** matrix, size_t rows, size_t colums);

void fillingMatrixWithVatiants(int32_t** matrix, size_t rows, size_t colums);

void delMatrix(int32_t**& matrix, size_t rows);