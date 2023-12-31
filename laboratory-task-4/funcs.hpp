#ifndef _FUNCS_HPP_
#define _FUNCS_HPP_


int32_t generationRandomNumber(int32_t leftBoard, int32_t rightBoard);
void getRowsAndCollums(size_t & rows, size_t & colums);
void matrixDefine(int32_t**& matrix, size_t rows, size_t colums);
void fillingMatrixFromKeyboard(int32_t** matrix, size_t rows, size_t colums);
void fillingMatrixFromRandom(int32_t** matrix, size_t rows, size_t colums);
void printMatrix(int32_t** matrix, size_t rows, size_t colums);
void sumEllementInColumsWithNull(int32_t** matrix, size_t rows, size_t colums);
void bubleSortRight(int32_t* line, size_t colums);
void bubleSortLeft(int32_t* line, size_t colums);
void sortLines(int32_t** matrix, size_t rows, size_t colums);
void fillingMatrixWithVariants(int32_t** matrix, size_t rows, size_t colums);
void mtrxMemClear(int32_t**& matrix, size_t rows);

#endif
