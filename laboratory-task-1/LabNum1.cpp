#include <iostream>
void main() {
	try {
		setlocale(0, "");
		std::cout << "введите границы интервалов = ";
		double a, b;// help;
		std::cin >> a >> b;
		if (b < a) {
			/*help = a;
			a = b;
			b = help;
			*/
			std::swap(a, b);
		}
		double x;
		std::cout << "введите х = ";
		std::cin >> x;
		if (a < x && b > x) {
			std::cout << "принадлежит интервалу (" << a << ',' << b << ')';
		}
		else if (x < a) {
			std::cout << "принадлежит интервалу ( " << x << ',' << "<" << a << ')';
		}
		else if (x > b) {
			std::cout << "принадлежит интервалу ( " << x << ',' << ">" << b << ')';
		}
	}
	catch (...) {
		std::cout << "Ошибка ввода";
	}
}