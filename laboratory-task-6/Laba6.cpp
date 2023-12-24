/*
    Разработать шаблон функции для обработки массивов с элементами простого арифметического типа и массивов,
    элементы которых – строки типа char*.
    Продемонстрировать использование этого шаблона для конкретных динамических массивов типа int, double, char*.
    Для получения входных данных иметь три варианта:
    - непосредственный ввод и запись в текстовый файл;
    - генерирование с помощью датчика случайных чисел и запись в текстовый файл;
    - ввод из текстового файла, а вывод - в консоль.

    Вариант 4.
    Разработать шаблон функции для выполнения бинарного поискав упорядоченном одномерном массиве
    – итерационный вариант.
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <execution>


bool checkFile(std::ifstream& file, std::string path) {
    if (!file) {
        throw std::exception("File not founded. Path " + path);
    }
    if (!file.is_open()) {
        throw std::exception("File unopened. Path " + path);
    }
    if (file.peek() == EOF){ 
        throw std::exception("File is epmty. Path " + path);
        file.close();
    }
    return true;
}


std::string getPath() {
    std::string path;
    std::cout << "Please enter path to file";
    std::cin >> path;
    for (size_t i = 0; i < path.size(); i++) {
        if (path[i] == '\\'){ path[i] = '/';}
    }
    return path;
}


// filling an array from the keyboard
template<typename T>
void fillingArrFromKeyboard(T* arr, size_t lenArr) {  
    std::cout << "Please enter element: \n";
    for (size_t i = 0; i < lenArr; ++i) {
        std::cin >> arr[i];
    }
}


//  for int 
void inputRandom(int32_t* arr, const size_t lenArr) { 
    int32_t leftBoard = 0, rightBoard = 0;
    std::cout << "Enter board valuse = ";
    std::cin >> leftBoard >> rightBoard;
    if (leftBoard > rightBoard) {
        std::swap(leftBoard, rightBoard);
    }
    for (size_t i = 0; i < lenArr; ++i) {
        arr[i] = rand() % (rightBoard - leftBoard + 1) + leftBoard;
    }
}


//  for double
void inputRandom(double* arr, const size_t lenArr) { 
    double leftBoard = 0, rightBoard = 0;
    std::cout << "Enter board valuse = ";
    std::cin >> leftBoard >> rightBoard;
    if (leftBoard > rightBoard) {
        std::swap(leftBoard, rightBoard);
    }
    for (size_t i = 0; i < lenArr; ++i) {
        arr[i] = static_cast<double>(rand()) / RAND_MAX * (rightBoard-leftBoard) + leftBoard;
    }
}


//  for char
void inputRandom(char* arr, const size_t lenArr) { 
    std::cout << "Enter board values in table ASCII code";
    int32_t leftBoard, rightBoard;
    std::cin >> leftBoard >> rightBoard;
    if (leftBoard < 0 || leftBoard > 255 || rightBoard < 0 || rightBoard > 255) throw std::exception("Invalid borders...");
    if (rightBoard < leftBoard) std::swap(leftBoard, rightBoard);
    for (size_t i = 0; i < lenArr; ++i) {
        arr[i] = static_cast<char>(rand() % (rightBoard - leftBoard + 1) + leftBoard);
    }
}


template <typename T>
void outArr(T* arr, const size_t lenArr, const size_t prescision) {
    for (size_t i = 0; i < lenArr; ++i) {
        std::cout << std::setprecision(prescision) << arr[i] << ' ';
    }
}


template <typename T>
void quickSort(T* array, size_t leftBoard, size_t rightBoard) {
    size_t start = leftBoard;
    size_t finish = rightBoard;
    T pivot = array[(start + finish) / 2];
    while (start <= finish){
        while (array[start] < pivot)
            start++;
        while (array[finish] > pivot)
            finish--;
        if (start <= finish)
        {
            std::swap(array[start], array[finish]);
            start++;
            finish--;
        }
    }
    if (finish > leftBoard)
        quickSort(array, leftBoard, finish);
    if (start < rightBoard)
        quickSort(array, start, rightBoard);
}


// temlate for int,char
template<typename T> 
int32_t binareSearch(T* arr, size_t lenArr, T ell) {
    size_t leftBoard = 0;
    size_t rightBoard = lenArr - 1;
    size_t mid = 0;
    bool isEll = false;
    while (leftBoard <= rightBoard && IsEll != true) {
        mid = (leftBoard + rightBoard) / 2;
        if (arr[mid] == ell)  {
            isEll = true;
            break;
        }
        if (arr[mid] < ell) {
            leftBoard = mid + 1;
        }
        if (arr[mid] > ell) {
            rightBoard = mid - 1;
        }
    }
    if (isEll) {
        return mid;
    }
    else {
        return -1;
    }
}


//specialization for double
template<>
int32_t binareSearch(double* arr, size_t lenArr, double ell) {
    size_t leftBoard = 0;
    size_t rightBoard = lenArr - 1;
    size_t mid = 0;
    bool isEll = false;
    double eps = 0.1;
    std::cout << "Please enter eps: ";
    std::string epsText;
    std::cin >> epsText;
    eps = std::stod(epsText); // this method is it check value to doble type
    while (leftBoard <= rightBoard && IsEll != true) {
        mid = (leftBoard + rightBoard) / 2;
        if (std::fabs(arr[mid] - ell) < eps) {
            isEll = true;
            break;
        }
        if (arr[mid] < ell) {
            leftBoard = mid + 1;
        }
        if (arr[mid] > ell) {
            rightBoard = mid - 1;
        }
    }
    if (isEll) {
        return mid;
    }
    else {
        return -1;
    }
}


size_t inputLenArr() {
    std::string lenArr = "0";
    int32_t lenArrControl = std::stoi(lenArr);
    while (lenArrControl <= 0) {
        std::cout << "Enter lenght array = ";
        std::cin >> lenArr;
        lenArrControl = std::stoi(lenArr);
    }
    return static_cast<size_t>(lenArrControl);
}


template<typename T>
void deleteArr(T* arr) {
    delete[] arr;
}


void inputFromFileAndOutputToConsole() {
    std::string wayToFile = getPath();
    std::string line = "", text = "";
    std::ifstream fin(wayToFile);
    if (checkFile(fin, wayToFile)) {
        while (std::getline(fin, line)) {
            text += line;
        }
    }
    fin.close();
    size_t lenArr = text.size();
    char* arr = new char[lenArr];
    for (size_t i = 0; i < lenArr; ++i) {
        arr[i] = text[i];
    }

    outArr(arr, lenArr, 10);
    quickSort(arr, 0, lenArr - 1);
    outArr(arr, lenArr, 10);
    char ell = ' ';
    std::cin >> ell;
    std::cout << binareSearch(arr, lenArr, ell);
    deleteArr(arr);
}


template<typename T>
void writingInFile(T* arr, size_t lenArr) {
    std::cout << "Please enter searhing ellement: ";
    T searchingEll;
    std::cin >> searchingEll;
    std::ofstream out("result.txt");
    out.imbue(std::locale(""));
    int32_t indexSearhingEll = binareSearch(arr, lenArr, searchingEll);

    if (out.is_open()) {
        if (indexSearhingEll == -1){
            out << "Ellement was not founded";
        }else{
            out << "In array \n|";
            for (size_t i = 0; i < lenArr; ++i) {
                out << arr[i] << '|';
             }
            out << "\nEllement " << searchingEll << " has index " << indexSearhingEll;
        }
    }
    out.close();
}


void inputFromConsoleAndOutputToFile() {
    size_t lenArr = inputLenArr();
    std::cout << "PLease select type of array: |int -- 1|double -- 2|char -- 3|: ";
    std::string typeArrText;
    std::cin >> typeArrText;
    size_t typeArr = static_cast<size_t>(std::stoi(typeArrText));
    size_t indexSearhingEll = 0;
    if (typeArr == 1) {
        int32_t* arr = new int32_t[lenArr];
        fillingArrFromKeyboard(arr, lenArr);
        quickSort(arr, 0, lenArr - 1);
        outArr(arr, lenArr, 10);
        writingInFile(arr, lenArr);
    }
    else if (typeArr == 2) {
        double* arr = new double[lenArr];
        fillingArrFromKeyboard(arr, lenArr);
        quickSort(arr, 0, lenArr - 1);
        outArr(arr, lenArr, 10);
        writingInFile(arr, lenArr);
    }
    else {
        char* arr = new char[lenArr];
        fillingArrFromKeyboard(arr, lenArr);
        quickSort(arr, 0, lenArr - 1);
        outArr(arr, lenArr, 10);
        writingInFile(arr, lenArr);
    }
}


void inputFromRandomAndOutToFile() {
    size_t lenArr = inputLenArr();
    std::cout << "PLease select type of array: |int -- 1|double -- 2|char -- 3|: ";
    std::string typeArrText;
    std::cin >> typeArrText;
    size_t typeArr = static_cast<size_t>(std::stoi(typeArrText));
    size_t indexSearhingEll = 0;
    if (typeArr == 1) {
        int32_t* arr = new int32_t[lenArr];
        inputRandom(arr, lenArr);
        outArr(arr, lenArr, 10);
        quickSort(arr, 0, lenArr - 1);
        outArr(arr, lenArr, 10);
        writingInFile(arr, lenArr);
    }
    else if (typeArr == 2) {
        double* arr = new double[lenArr];
        inputRandom(arr, lenArr);
        outArr(arr, lenArr, 10);
        quickSort(arr, 0, lenArr - 1);
        outArr(arr, lenArr, 10);
        writingInFile(arr, lenArr);
    }
    else {
        char* arr = new char[lenArr];
        inputRandom(arr, lenArr);
        outArr(arr, lenArr, 10);
        quickSort(arr, 0, lenArr - 1);
        outArr(arr, lenArr, 10);
        writingInFile(arr, lenArr);
    }
}


int main() {
    try {
        system("chcp 1251");
        SetConsoleCP(1225);
        SetConsoleOutputCP(1225);
        srand(time(0));
        void (*funcTypeOfWorcking[3])() = { inputFromConsoleAndOutputToFile, inputFromRandomAndOutToFile, inputFromFileAndOutputToConsole };
        std::cout << "Please select a type of of worcking |Input from console and output to file -> 0|Random generation and out to file -> 1|Input from file and output to console -> 2|\n";
        uint32_t typeOfWorking = 3;
        std::string typeOfWorkingText;
        std::cin >> typeOfWorkingText;
        typeOfWorking = static_cast<uint32_t>(std::stoi(typeOfWorkingText));
        if (typeOfWorking > 2) { throw "This type not exist..."; }
        funcTypeOfWorcking[typeOfWorking]();
    }
    catch (std::invalid_argument) {
        std::cout << "Error invalid value...";
    }
    catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
    }
    catch (std::system_error) {
        std::cout << "Problem with file...";
    }
    return 0;
}