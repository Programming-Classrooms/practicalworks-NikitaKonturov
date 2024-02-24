#include "myString.hpp"


/*========================================================*/
/*======================Конструкторы======================*/
/*========================================================*/

// Конструктор по умолчанию
myString::myString() : 
    size(0), 
    capacity(0), 
    pStr(new char[0]) 
{}

// Конструктор задания размера myString
myString::myString(int64_t sizeToMyString) 
{
    if (sizeToMyString <= 0) {
        throw std::invalid_argument("Bad size...");
    }

    this->capacity = sizeToMyString * 2;
    this->size = sizeToMyString;
    this->pStr = new char[capacity];
    this->pStr[size] = '/0';
}

// Конструктор копирования[пергрузка для myString]
myString::myString(const myString &origin) 
{
    if (this->pStr == origin.pStr || origin.pStr == nullptr) {
        throw std::invalid_argument("Origin have a bad pointer...");
    }

    this->capacity = origin.capacity;
    this->size = origin.size;
    this->pStr = new char[this->capacity];
    for (size_t i = 0; i < size; ++i) {
        this->pStr[i] = origin.pStr[i];
    }

    this->pStr[size] = '/0';
}

// Конструктор копирования[пергрузка для const char*]
myString::myString(const char *origin) 
{
    if (this->pStr == origin || origin == nullptr) {
        throw std::invalid_argument("Origin have a bad pointer...");
    }

    size_t sourceSize = std::strlen(origin);
    this->size = sourceSize;
    this->capacity = this->size * 2;
    this->pStr = new char[this->capacity];

    for (size_t i = 0; i < size; ++i) {
        this->pStr[i] = origin[i];
    }
    this->pStr[this->size] = '/0';
}

// Конструктор перемещения[переприсваивает значение из origin в this(без копирования данных)]
myString::myString(myString &&origin) 
{
    this->size = origin.size;
    this->capacity = origin.capacity;
    origin.pStr = nullptr;
}

// Деструктор[проверка на nullptr для того чтобы избежать ошибки, удаления отсутсвующей строки] 
myString::~myString() 
{
    if (this->pStr != nullptr) {
      delete[] this->pStr;
    }
}


/*========================================================*/
/*================Методы изменения строки=================*/
/*========================================================*/


/*========Метод добавления символа в конец строки=========*/
void myString::push_back(char letter) 
{
// Случай при котором строка заполнила всю предоставленную ей память 
    if (this->size == this->capacity) {
// Если строка пустая и ей размер 0
        if (this->size == 0) {
            this->capacity = 1 * 2;
            this->pStr = new char[this->capacity];
            this->pStr[this->size++] = letter;
            this->pStr[this->size] = '/0';
        } 
        else {
            char *tmp = new char[this->size * 2];
            for (size_t i = 0; i < this->size; ++i) {
                tmp[i] = this->pStr[i];
            }
            tmp[this->size++] = letter;
            tmp[this->size] = '/0';
            this->capacity = this->size * 2;
            delete[] this->pStr;
            this->pStr = tmp;
        }
      } 
// Случай при котором ещё есть место для добавления нового символа
      else {
          this->pStr[this->size++] = letter;
          this->pStr[size] = '/0';
    }
}


/*=======Метод добавления поодстроки в конец строки=======*/

// Метод добавления подстроки в конец[перегрузка для myString] 
void myString::append(const myString &source) 
{
    if (this->pStr == nullptr || source.pStr == nullptr || source.pStr == this->pStr) {
        throw std::logic_error("Bad pointers...");
    }

// Если добавление строки не переведёт к переполнению выделенной памяти
    if (this->capacity > (this->size + source.size)) {
        for (size_t i = 0, j = this->size; i < source.size; ++i, ++j) {
            this->pStr[j] = source.pStr[i];
        }

        this->size += source.size;
        this->pStr[size] = '/0';
    } 
    else {
// Если добавление строки переведёт к переполнению выделенной памяти 
        char *tmp = new char[(this->size + source.size) * 2];
        size_t j = 0;
        for (size_t i = 0; i < this->size; ++i, ++j) {
            tmp[j] = this->pStr[i];
        }
        
        for (size_t i = 0; i < source.size; ++i, ++j) {
            tmp[j] = source.pStr[i];
        }
        this->size += source.size;
        delete[] this->pStr;
        this->pStr = tmp;
        this->pStr[this->size] = '/0';
    }
}

// Метод добавления подстроки в конец[перегрузка для const char*] 
void myString::append(const char *source) 
{
    if (this->pStr == nullptr || source == nullptr || this->pStr == source) {
        throw std::logic_error("Bad pointers...");
    }

    size_t sourceSize = std::strlen(source);
    if (this->capacity > (this->size + sourceSize)) {
        for (size_t i = 0, j = this->size; i < sourceSize; ++i, ++j) {
            this->pStr[j] = source[i];
        }
        this->size += sourceSize;
        this->pStr[this->size] = '/0';
    }  
    else {
        char *tmp = new char[(this->size + sourceSize) * 2];
        size_t j = 0;
        for (size_t i = 0; i < this->size; ++i, ++j) {
            tmp[j] = this->pStr[i];
        }
        for (size_t i = 0; i < sourceSize; ++i, ++j) {
            tmp[j] = source[i];
        }
        this->size += sourceSize;
        delete[] this->pStr;
        this->pStr = tmp;
        this->capacity = this->size * 2;
        this->pStr[this->size] = '/0';
    }
}


/*================Метод вставки поодстроки================*/

// Метод вставки подстроки[перегрузка для const char*]
void myString::insert(const char *source, size_t pos) 
{
    if (this->pStr == nullptr || source == nullptr || this->pStr == source) {
        throw std::logic_error("Bad pointers...");
    }
    if (pos > size) {
        throw std::out_of_range("Bad position...");
    }

    size_t sourceSize = std::strlen(source);

// Случай при котором вставка не приведёт к переполнению выделенной памяти
    if (this->capacity > (this->size + sourceSize)) {
        char *tmp = new char[this->size - pos];
        for (size_t i = pos, j = 0; i < this->size; ++i, ++j) {
            tmp[j] = this->pStr[i];
        }
        for (size_t i = 0, j = pos; i < sourceSize; ++i, ++j) {
            this->pStr[j] = source[i];
        }
        for (size_t i = 0, j = pos + sourceSize; i < this->size - pos; ++i, ++j) {
            this->pStr[j] = tmp[i];
        }
        delete[] tmp;
        this->size += sourceSize;
        this->pStr[this->size] = '/0';
    } 
    else {

// Случай при котором вставка приведёт к переполнению выделенной памяти
        char *result = new char[(this->size + sourceSize) * 2];
        size_t j = 0;
        for (size_t i = 0; i < pos; ++i, ++j) {
            result[j] = this->pStr[i];
        }
        for (size_t i = 0; i < sourceSize; ++i, ++j) {
            result[j] = source[i];
        }
        for (size_t i = pos; i < this->size; ++i, ++j) {
            result[j] = this->pStr[i];
        }
        delete[] this->pStr;
        this->pStr = result;
        this->pStr[size] = '/0';
    }
}

// Метод вставки подстроки[перегрузка для mySource]
void myString::insert(const myString &source, size_t pos) 
{
    if (this->pStr == nullptr || source.pStr == nullptr ||this->pStr == source.pStr) {
        throw std::logic_error("Bad pointers...");
    }
    
    if (pos >= this->size) {
        throw std::out_of_range("Bad position...");
    }

    if (this->capacity > this->size + source.size) {
        char *tmp = new char[this->size - pos];
        for (size_t i = 0, j = pos; j < this->size; ++i, ++j) {
            tmp[i] = this->pStr[j];
        }
        for (size_t i = 0, j = pos; i < source.size; ++i, ++j) {
            this->pStr[j] = source.pStr[i];
        }
        for (size_t i = 0, j = pos + source.size; i < this->size - pos; ++i, ++j) {
            this->pStr[j] = tmp[i];
        }
        this->size += source.size;
        this->capacity = this->size * 2;
        delete[] tmp;
        this->pStr[this->size] = '/0';
    } 
    else {
        char *tmp = new char[(this->size + source.size) * 2];
        for (size_t i = 0; i < pos; ++i) {
            tmp[i] = this->pStr[i];
        }
        for (size_t i = 0, j = pos; i < source.size; ++i) {
            tmp[j] = source.pStr[i];
        }
        for (size_t i = pos, j = pos + source.size; i < this->size; ++i, ++j) {
            tmp[j] = this->pStr[i];
        }
        this->pStr = tmp;
        this->pStr[this->size] = '/0';
    }
}


/*================Метод замены подстроки================*/

//Метод замены подстроки[перегрузка для myString]
void myString::replace(const myString &source, size_t pos, size_t lenght) 
{
    if (this->pStr == nullptr || source.pStr == nullptr || this->pStr == source.pStr) {
        throw std::logic_error("Bad pointers...");
    }

    if (pos + lenght > this->size) {
        throw std::out_of_range("Out of range...");
    }

// Если после замене итоговая строка не будет привышать объём выделенной памяти 
    if (this->capacity > (this->size + source.size - lenght)) {
        char *tmp = new char[this->size - pos - lenght];

        for (size_t i = 0, j = pos + lenght; j < this->size; ++i, ++j) {
            tmp[i] = source.pStr[j];
        }
        for (size_t i = 0, j = pos; i < source.size; ++i, ++j) {
            this->pStr[j] = source.pStr[i];
        }
        for (size_t i = 0, j = pos + source.size; i < this->size - pos - lenght; ++i, ++j) {
            this->pStr[j] = tmp[i];
      }

        this->size = this->size - lenght + source.size;
        delete[] tmp;
        this->pStr[this->size] = '/0';
    } 
// Если после замене итоговая строка не будет привышать объём выделенной памяти 
    else {
        char *tmp = new char[this->size - lenght + source.size];
        for (size_t i = 0; i < pos; ++i) {
            tmp[i] = this->pStr[i];
        }
        for (size_t i = pos, j = 0; j < source.size; i++) {
            tmp[i] = source.pStr[j];
        }
        for (size_t i = pos + lenght, j = source.size + pos; i < this->size; ++i, ++j) {
            tmp[j] = this->pStr[i];
        }
        this->size = this->size - lenght + source.size;
        this->capacity = this->size * 2;
        delete[] this->pStr;
        this->pStr = tmp;
        this->pStr[this->size] = '/0';
    }
}

//Метод замены подстроки[перегрузка для const char*]
void myString::replace(const char *source, size_t pos, size_t lenght) 
{
  if (pStr == nullptr || source == nullptr || pStr == source) {
    throw std::logic_error("Bad pointers...");
  }
  if (pos + lenght > size) {
    throw std::out_of_range("Out of range...");
  }
  size_t sourceSize = std::strlen(source);
  if (capacity > (size + sourceSize - lenght)) {
    char *tmp = new char[size - pos - lenght];
    for (size_t i = 0, j = pos + lenght; j < size; ++i, ++j) {
      tmp[i] = pStr[j];
    }
    for (size_t i = 0, j = pos; i < sourceSize; ++i, ++j) {
      pStr[j] = source[i];
    }
    for (size_t i = 0, j = pos + sourceSize; i < size - pos - lenght;
         ++i, ++j) {
      pStr[j] = tmp[i];
    }
    size = size - lenght + sourceSize;
    delete[] tmp;
    pStr[size] = '/0';
  } else {
    char *tmp = new char[size - lenght + sourceSize];
    for (size_t i = 0; i < pos; ++i) {
      tmp[i] = pStr[i];
    }
    for (size_t i = pos, j = 0; j < sourceSize; i++) {
      tmp[i] = source[j];
    }
    for (size_t i = pos + lenght, j = sourceSize + pos; i < size; ++i, ++j) {
      tmp[j] = pStr[i];
    }
    size = size - lenght + sourceSize;
    capacity = size * 2;
    delete[] pStr;
    pStr = tmp;
    pStr[size] = '/0';
  }
}

/*==============Метод очистки строки==============*/

void myString::clear() 
{
    if (this->pStr != nullptr) {
        this->size = 0;
        this->capacity = 0;
        delete[] this->pStr;
        this->pStr = new char[0];
    }
}


/*========================================================*/
/*=========================Гетеры=========================*/
/*========================================================*/

// Метод выделение подстроки в строке
myString myString::substr(size_t pos, size_t lenght) const 
{
    if (this->pStr == nullptr) {
        throw std::logic_error("The line was deleted...");
    }
    if (pos + lenght > this->size) {
        throw std::out_of_range("Out of range...");
    }

    myString result(lenght);
    for (size_t i = pos, j = 0; i < pos + lenght; ++i, ++j) {
        result.pStr[j] = this->pStr[i];
    }
    return result;
}

// Метод возвращающий размер строки
size_t myString::getSize() const 
{ 
    return this->size; 
}

// Метод проверки строки на пустоту
bool myString::empty() const 
{ 
    return this->size == 0; 
}

// Метод возвращающий копию строки с типом char*
char *myString::c_str() const 
{
    char *result = new char[this->size];

    for (size_t i = 0; i < this->size; ++i) {
        result[i] = this->pStr[i];
    }

    return result;
}


/*========================================================*/
/*=======================Операторы========================*/
/*========================================================*/

/*===============Операторы работы со строкой==============*/


// Итератор
char& myString::operator[](size_t pos) 
{
    if (this->pStr == nullptr) {
        throw std::logic_error("String is emty...");
    }
    if (pos >= this->size) {
        throw std::out_of_range("Bad index...");
    }
    return this->pStr[pos];
}

// Оператор присваивания
void myString::operator=(const myString &source) 
{
    if (this->pStr == source.pStr || this->pStr == nullptr || source.pStr == nullptr) {
        throw std::invalid_argument("Bad pointers...");
    }

    this->size = source.size;
    this->capacity = source.capacity;
    delete[] this->pStr;
    this->pStr = new char[this->capacity];
    for (size_t i = 0; i < this->size; ++i) {
        this->pStr[i] = source.pStr[i];
    }

    this->pStr[size] = '/0';
}

// Опрератор канкатинации
myString myString::operator+(const myString &source) const 
{
    myString result = *this;
    result.append(source);
    return result;
}


/*================Операторы сравнение строк===============*/


// Оператор сравнения строк
bool myString::operator==(const myString &compared) const 
{
    if (compared.pStr == nullptr || this->pStr == compared.pStr || this->pStr == nullptr) {
        throw std::logic_error("Bad pointers...");
    }

    if (this->size != compared.size) {
        return false;
    }

    for (size_t i = 0; i < this->size; ++i) {
        if (this->pStr[i] != compared.pStr[i]) {
            return false;
        }
    }   
    return true;
}

// Оператор меньше
bool myString::operator<(const myString &compared) const 
{
    if (compared.pStr == nullptr || this->pStr == compared.pStr || this->pStr == nullptr) {
        throw std::logic_error("Bad pointers...");
    }

    for (size_t i = 0; i < this->size && i < compared.size; ++i) {
        if (this->pStr[i] != compared.pStr[i]) {
            return this->pStr[i] < compared.pStr[i];
        }
    }
    return this->size < compared.size;
}


// Оператор неравенства
bool myString::operator!=(const myString &compared) const
{
    return !(*this == compared);
}

// Оператор больше
bool myString::operator>(const myString& compared) const
{
    return !(*this < compared) && *this != compared;
}

// Оператор меньше или равно
bool myString::operator<=(const myString& compared) const
{
    return *this < compared || *this == compared;
}

// Оператор больше или равно
bool myString::operator>=(const myString& compared) const
{
    return !(*this < compared);
}


/*=============Операторы приобразвания типов==============*/

// Преобразование к std::string
myString::operator std::string() const 
{
    if (this->pStr == nullptr) {
        throw std::logic_error("Bad pointer...");
    }

    std::string result(this->pStr);
    return result; 
}

// Преобразование к int64_t(велосипед потому что сама задумка не использовать std::string(а то по такой логике мы можем просто сделать наследование от оригинального string))
myString::operator int64_t() const
{
    if(this->pStr == nullptr) {
        throw std::invalid_argument("String was not exest...");
    }
    int64_t result = 0;
    bool isNegative = false;

    if(this->pStr[0] == '-') {
        isNegative = true;
    }
    else if(!isdigit(this->pStr[0])) {
        throw std::invalid_argument("String not have digits...");
    }

    for (size_t i = static_cast<size_t>(isNegative); isdigit(this->pStr[i]); ++i) {
        result = (10 * result) + (static_cast<int>(this->pStr[i]) - '0');
    }
    if(isNegative) {
        return -1 * result;
    }
    else {
        return result;
    }
}

// Преобразование к double
myString::operator double() const
{
    if(this->pStr == nullptr) {
        throw std::invalid_argument("String was not exest...");
    }
    
    double result = 0;
    double rightValue = 0;

    bool isNegative = false;

    if(this->pStr[0] == '-') {
        isNegative = true;
    }
    else if(!isdigit(this->pStr[0])) {
        throw std::invalid_argument("String not have digits...");
    }

    size_t i = static_cast<size_t>(isNegative);
    for (;isdigit(this->pStr[i]); ++i) {
        result = (10 * result) + (static_cast<int>(this->pStr[i]) - '0'); 
    }
    size_t bitDepth = 1;
    if (this->pStr[i++] == '.') {
        for (;isdigit(pStr[i]); ++i, ++bitDepth) {
            rightValue = (10 * rightValue) + (static_cast<int>(this->pStr[i]) - '0'); 
        }
        rightValue /= std::pow(10, bitDepth); 
    }
    
    result += rightValue;
    return result;
}


/*================Операторы ввода вывода==================*/

//Оператор вывода
std::ostream &operator<<(std::ostream &out, myString &source) 
{
    if (source.pStr == nullptr) {
      throw std::logic_error("The line was deleted...");
    }

    for (size_t i = 0; i < source.size; ++i) {
      out << source.pStr[i];
    }

    return out;
}

//Оператор ввода
std::istream &operator>>(std::istream &in, myString &source) {
    if (source.pStr == nullptr) {
        throw std::logic_error("The line was deleted...");
    }

    delete[] source.pStr;
    source.pStr = new char[0];
    source.size = 0;
    source.capacity = 0;
    char liter;
    while (in.get(liter) && (liter != ' ' && liter != '\n')) {
        source.push_back(liter);
    }
    return in;
}
