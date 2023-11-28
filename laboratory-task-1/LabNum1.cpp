#include <iostream>
#include <string>
#include <exception>


void main() {
	try {
		setlocale(0, "");
		std::cout << "Enter borders valeus = ";
		double a, b;
		std::string aStr, bStr;
		std::cin >> aStr >> bStr;
		a = std::stod(aStr);
		b = std::stod(bStr);
		if (b < a) {
			std::swap(a, b);
		}
		double x;
		std::string xStr;
		std::cout << "Enter x = ";
		std::cin >> xStr;
		x = std::stod(xStr);
		if (a < x && b > x) {
			std::cout << "x find in interval (" << a << ',' << b << ')';
		}
		else if (x < a) {
			std::cout << "x find in interval ( " << x << ',' << "<" << a << ')';
		}
		else if (x > b) {
			std::cout << "x find in interval ( " << x << ',' << ">" << b << ')';
		}
	}
	catch (std::invalid_argument) {
		std::cout << "Error invalid value";
	}
}