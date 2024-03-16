#include"matrix.hpp"


/*==========================================================*/
/*==================Приватные методы========================*/
/*==========================================================*/


// Перемножение строки и столбца
int64_t Matrix::multiplicateRowsColumns(size_t indexRow, size_t indexColumn, const Matrix& source) const
{
    int64_t res = 0;

    for (size_t i = 0; i < rows; ++i) {
        res += (mtrx[indexRow][i] * source.mtrx[i][indexColumn]);
    }
    
    return res;
}

/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/


//Конструктор по умолчанию 
Matrix::Matrix(size_t initRows, size_t initColums) : rows(initRows), columns(initColums)
{
    if(this->rows == 0 || this->columns == 0) {
        throw std::invalid_argument("Arrguments must be natural numbers...");
    }
    
    this->mtrx = new Row[this->rows];
    
    for (size_t i = 0; i < this->rows; ++i) {
        mtrx[i].setSize(this->columns);
    }
    
}

//Конструктор копирования
Matrix::Matrix(const Matrix& source) : columns(source.columns), rows(source.rows)
{
    if(this == &source) {
        throw std::logic_error("Self-assignment is not possible...");
    }
    
    this->mtrx = new Row[this->rows];
    for (size_t i = 0; i < this->rows; ++i) {
        this->mtrx[i] = source.mtrx[i];
    }
}

//Деструктор 
Matrix::~Matrix()
{
    delete[] this->mtrx;
}

/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/


 // Получение колличества столбцов
size_t Matrix::getColumns() const
{
    return this->columns;
}

 // Получение колличества строк
size_t Matrix::getRows() const
{
    return this->rows;
}


/*==========================================================*/
/*=====================Операторы============================*/
/*==========================================================*/

// Итератор 
Row& Matrix::operator[](size_t index)
{
    if (index >= this->rows) {
        throw std::out_of_range("Out of range...");
    }

    return this->mtrx[index];
}


/*==========================================================*/
/*==============Алгебраические операторы====================*/
/*==========================================================*/


// Оператор присваивания
Matrix& Matrix::operator=(const Matrix& source)
{
     if(this == &source) {
        throw std::logic_error("Self-assignment is not possible...");
    }
    
    delete[] this->mtrx;
    this->rows = source.rows;
    this->columns = source.columns;
    this->mtrx = new Row[rows];

    for (size_t i = 0; i < this->rows; ++i) {
        this->mtrx[i] = source.mtrx[i];
    }

    return *this;
}

// Перегрузка оператора присваивания для костатнты(так как ы условии не указанно как итепретировать костанту, то представляем её ввиде скалярной матрицы)
Matrix& Matrix::operator=(int64_t source)
{
    delete[] this->mtrx;
    this->columns = this->rows;

    this->mtrx = new Row[this->rows];
    for (size_t i = 0; i < this->rows; ++i) {
        mtrx[i].setSize(this->rows);
        for (size_t j = 0; j < this->columns; ++j) {
            mtrx[i][j] = 0;
        }
    }

    for (size_t i = 0; i < this->rows; ++i) {
        this->mtrx[i][i] = source; 
    }
    
    return *this;
}

// Оператор домножения на констант справа
Matrix Matrix::operator*(int64_t source) const
{
    Matrix res(*this);

    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->columns; ++j) {
            res[i][j] *= source;    
        }
    }
    
    return res;
}

//Оператор домножения на костанту слева
Matrix operator*(int64_t source, const Matrix& origin) 
{
    return origin * source;
}

// Оператор деления на константу
Matrix Matrix::operator/(int64_t source) const
{
    Matrix res(*this);

    if (source == 0) {
        throw std::invalid_argument("Division by zero...");
    }

    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->columns; ++j) {
            res[i][j] /= source;    
        }
    }
    
    return res;
}

//Оператор сложения матриц
Matrix Matrix::operator+(const Matrix& source) const
{
    if (this->rows != source.rows || this->columns != source.columns) {
        throw std::invalid_argument("Dimentions matrix must be equal...");
    }
    
    Matrix res(*this);


    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->columns; ++j) {
            res[i][j] += source.mtrx[i][j];    
        }
    }
    
    return res;
}

//Оператор разности матрцы
Matrix Matrix::operator-(const Matrix& source) const
{

    if (this->rows != source.rows || this->columns != source.columns) {
        throw std::invalid_argument("Dimentions matrix must be equal...");
    }

    Matrix res(*this);
    
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->columns; ++j) {
            res[i][j] -= source.mtrx[i][j];    
        }
    }
    
    return res;
}

//Оператор перемножения матриц
Matrix Matrix::operator*(const Matrix& source) const
{
    if(this->columns != source.rows) {
        throw std::invalid_argument("Not equal columns and rows...");
    }

    Matrix res(this->rows, source.columns);
    
    for (size_t i = 0; i < res.rows; ++i) {
        for (size_t j = 0; j < res.columns; ++j) {
            res[i][j] = multiplicateRowsColumns(i, j, source);
        }
    }

    return res;
}


/*==========================================================*/
/*================Логические операторы======================*/
/*==========================================================*/


//Оператор сравнения матриц
bool Matrix::operator==(const Matrix& source) const
{
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->columns; ++j) {
            if(mtrx[i][j] != source.mtrx[i][j]) {
                return false;
            }        
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& source) const
{
    return !(*this == source);
}


/*==========================================================*/
/*==================Поточные операторы======================*/
/*==========================================================*/

// Оператор вывода 
std::ostream& operator<<(std::ostream& out, const Matrix& source)
{
    for (size_t i = 0; i < source.rows; ++i) {
        for (size_t j = 0; j < source.columns; ++j) {
            out << std::setw(3) << source.mtrx[i][j];
        }
        out << std::endl;
    }

    return out;
} 

// Оператор ввода
std::istream& operator>>(std::istream& in, Matrix& source)
{
    for (size_t i = 0; i < source.rows; ++i) {
        for (size_t j = 0; j < source.columns; ++j) {
            in >> source.mtrx[i][j];   
        }
    }

    return in;
}