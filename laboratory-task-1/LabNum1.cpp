/*Определить к какому интерввалу принадлежит х,
границы интерваллов задаёт пользователь.*/

#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>


void main() {
	try {
		SetConsoleCP(1225);
		SetConsoleOutputCP(1225);
		std::cout << "Enter borders valeus = ";
		double leftBoard, rightBoard;
		std::string aStr, bStr;
		std::cin >> aStr >> bStr;
		leftBoard = std::stod(aStr);
		rightBoard = std::stod(bStr);
		if (rightBoard < leftBoard) {
			std::swap(leftBoard, rightBoard);
		}
		double x;
		std::string xStr;
		std::cout << "Enter x = ";
		std::cin >> xStr;
		x = std::stod(xStr);
		if (leftBoard < x && rightBoard > x) {
			std::cout << "x find in interval (" << leftBoard << ',' << rightBoard << ')';
		}
		else if (x < leftBoard) {
			std::cout << "x find in interval ( " << x << ',' << "<" << leftBoard << ')';
		}
		else if (x > rightBoard) {
			std::cout << "x find in interval ( " << x << ',' << ">" << rightBoard << ')';
		}
	}
	catch (std::invalid_argument) {
		std::cout << "Error invalid value";
	}
}
