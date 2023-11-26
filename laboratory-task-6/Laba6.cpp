#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <string>
#include <execution>

std::string get_path() {
	std::string path;
	std::string cut;
	std::cout << "Please enter path to file";
	std::cin >> path;
	for (size_t i = 0; i < path.size(); i++) {
		if (path[i] == '\\') path[i] = '/';
	}
	return cut;
}

template<typename typeArr> 
void fillingArrFromKeyboard(typeArr* arr, size_t lenArr) {  // заполнение массива
	std::cout << "Please enter ellemen: \n";
	for (size_t i = 0; i < lenArr; ++i) {
		std::cin >> arr[i];
	}
}

template<typename typeArr>
int input_random(typeArr* arr, const size_t& lenArr) { // для int и char
	int32_t a = 0, b = 0;
	std::cout << "Enter board valuse = ";
	std::cin >> a >> b;
	if (a > b) {
		std::swap(a, b);
	}
	for (size_t i = 0; i < lenArr; ++i) {
		arr[i] = static_cast<typeArr>(rand() % (a+b));
	}
	return 0;
}


template<>
int input_random(double* arr, const size_t& lenArr) { // для double
	double a = 0, b = 0;
	std::cout << "Enter board valuse = ";
	std::cin >> a >> b;
	if (a > b) {
		std::swap(a, b);
	}
	int cellA = static_cast<int>(a);  // генерация случайного вещественного числа
	int deviseA = static_cast<int>((a - cellA) * 10000);
	int cellB = static_cast<int>(b);
	int deviseB = static_cast<int>((b - cellB) * 10000);
	int devise = 0; 
	int cell = 0; 
	for (size_t i = 0; i < lenArr; ++i) {
		cell = cellA + rand() % (cellB - cellA + 1);
		if (cell == cellA && cell == cellB) {
			devise = deviseA + rand() % (deviseB - deviseA + 1);
		}
		else if (cell == cellA) {
			devise = deviseA + rand() % (10000 - deviseA + 1);
		}
		else if (cell == cellB) {
			devise = rand() % (deviseB - 10000 + 1);
		}
		if (cell != cellA && cell != cellB) {
			devise = rand() % (10001);
		}
		arr[i] = static_cast<double>(cell) + static_cast<double>(devise) / 10000;
	}
	return 0;
}


template <typename typeArr>
void out_arr(typeArr* arr, const size_t& lenArr) {
	for (size_t i = 0; i < lenArr; ++i) {
		std::cout <<std::setprecision(10)<< arr[i] << ' ';
	}
	std::cout << '\n';
}

template <typename typeArr>
void quickSort(typeArr* array, size_t leftBoard, size_t rightBoard) {
	size_t start = leftBoard;
	size_t finish = rightBoard;
	typeArr pivot = array[(start + finish) / 2];
	while (start <= finish)
	{
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
	
template<typename TypeArr> // для int и double и char
size_t BinareSearch(TypeArr* arr, size_t lenArr, TypeArr ell) { 
	size_t left_board = 0;
	size_t right_board = lenArr - 1;  
	size_t mid = 0;
	bool IsEll = false;	
	double eps = 0.1;
	if (typeid(TypeArr) == typeid(double)) {
		std::cout << "Please enter eps: ";
		std::string epsText;
		std::cin >> epsText;
		eps = std::stod(epsText);
	}
	while (left_board <= right_board && IsEll != true) {
		mid = (left_board + right_board) / 2;
		if (std::fabs(arr[mid] - ell) < eps) {
			IsEll = true;
			break;
		}
		if (static_cast<TypeArr>(arr[mid]) < ell) {																																																																																																																																																																									
			left_board = mid + 1;
		}
		if (static_cast<TypeArr>(arr[mid]) > ell) {
			right_board = mid - 1;
		}
	}
	if (IsEll) { 
		return mid; 
	}
	else { 
		throw "Error element not founded..."; 
	}
}

size_t input_lenArr() {
	std::string lenArr = "0";
	int32_t lenArrControl = std::stoi(lenArr);
	while (lenArrControl <= 0) {
		std::cout << "Enter lenght array = ";
		std::cin >> lenArr;
		lenArrControl = std::stoi(lenArr);
	}
	return static_cast<size_t>(lenArrControl);
}

template<typename typeArr>
void del(typeArr* arr) {
	delete[] arr;
}

void InputFromFileAndOutputToConsole() {
	std::string wayToFile = get_path();
	std::string line = "", text = "";
	std::ifstream file(wayToFile);
	if (file.is_open()) {
		while (std::getline(file, line)) {
			text += line;
		}
	}
	else {
		throw "No such file exists";
	}
	file.close();
	size_t lenArr = text.size();
	char* arr = new char[lenArr];
	for (size_t i = 0; i < lenArr; ++i){
		arr[i] = text[i];
	}

	out_arr(arr, lenArr);
	quickSort(arr, 0, lenArr - 1);
	out_arr(arr, lenArr);
	char ell = ' ';
	std::cin >> ell;
	std::cout << BinareSearch(arr, lenArr, ell);
	del(arr);
}

template<typename typeArr>
void writingInFile(typeArr* arr, size_t lenArr) {
	
	std::cout << "Please enter searhing ellement: ";
	typeArr searchingEll;
	std::cin >> searchingEll;
	std::ofstream out;
	out.open("result.txt");
	out.imbue(std::locale(""));
	size_t indexSearhingEll = BinareSearch(arr, lenArr, searchingEll);

		if (out.is_open()) {
			out << "In array \n|";
			for (size_t i = 0; i < lenArr; ++i) {
				out << arr[i] << '|';
			}
			out << "\nEllement " << searchingEll << " has index " << indexSearhingEll;
		}
	out.close();
}
void InputFromConsoleAndOutputToFile() { // нужно както поменять кодировку чтобы записывалась кирилица в файл
	size_t lenArr = input_lenArr();
	std::cout << "PLease select type of array: |int -- 1|double -- 2|char -- 3|: ";
	std::string typeArrText;
	std::cin >> typeArrText;
	size_t typeArr = static_cast<size_t>(std::stoi(typeArrText));
	size_t indexSearhingEll = 0;
	if (typeArr == 1) {
		int* arr = new int[lenArr];
		fillingArrFromKeyboard(arr, lenArr);
		quickSort(arr, 0, lenArr - 1);
		out_arr(arr, lenArr);
		writingInFile(arr, lenArr);
	}
	else if (typeArr == 2) {
		double* arr = new double[lenArr];
		fillingArrFromKeyboard(arr, lenArr); 
		quickSort(arr, 0, lenArr - 1);
		out_arr(arr, lenArr); 
		writingInFile(arr, lenArr);
	}
	else {
		char* arr = new char[lenArr];
		fillingArrFromKeyboard(arr, lenArr); 
		quickSort(arr, 0, lenArr - 1);
		out_arr(arr, lenArr); 
		writingInFile(arr, lenArr);
	}
}

void InputFromRandomAndOutToFile() {
	size_t lenArr = input_lenArr();
	std::cout << "PLease select type of array: |int -- 1|double -- 2|char -- 3|: ";
	std::string typeArrText;
	std::cin >> typeArrText;
	size_t typeArr = static_cast<size_t>(std::stoi(typeArrText));
	size_t indexSearhingEll = 0;
	if (typeArr == 1) {
		int* arr = new int[lenArr];
		input_random(arr, lenArr);
		out_arr(arr, lenArr);
		quickSort(arr, 0, lenArr - 1);
		out_arr(arr, lenArr);
		writingInFile(arr, lenArr);
	}
	else if (typeArr == 2) {
		double* arr = new double[lenArr];
		input_random(arr, lenArr);
		out_arr(arr, lenArr);
		quickSort(arr, 0, lenArr - 1);
		out_arr(arr, lenArr);
		writingInFile(arr, lenArr);
	}
	else {
		char* arr = new char[lenArr];
		input_random(arr, lenArr);
		out_arr(arr, lenArr);
		quickSort(arr, 0, lenArr - 1);
		out_arr(arr, lenArr);
		writingInFile(arr, lenArr);
	}
}

void main() {
	try {
		system("chcp 1251");
		SetConsoleCP(1225);
		SetConsoleOutputCP(1225);
		srand(time(0));
		void (*funcTypeOfWorcking[3])() = { InputFromConsoleAndOutputToFile, InputFromRandomAndOutToFile, InputFromFileAndOutputToConsole };
		std::cout << "Please select a type of of worcking |Input from console and output to file -> 0|Random generation and out to file -> 1|Input from file and output to console -> 2|\n";
		uint32_t TypeOfWorking = 3;
		std::string TypeOfWorkingText;
		std::cin >> TypeOfWorkingText;
		TypeOfWorking = static_cast<uint32_t>(std::stoi(TypeOfWorkingText));
		if (TypeOfWorking > 2) { throw "This type not exist..."; }
		funcTypeOfWorcking[TypeOfWorking]();
	}
	catch (std::invalid_argument) {
		std::cout << "Error invalid value...";
	}
	catch(const char*err) {
		std::cout << err;
	}
	catch (std::system_error) {
		std::cout << "Problem with file...";
	}
}