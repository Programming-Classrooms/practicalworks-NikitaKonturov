#include <iostream>
void main() {
	try {
		setlocale(0, "");
		std::cout << "������� ������� ���������� = ";
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
		std::cout << "������� � = ";
		std::cin >> x;
		if (a < x && b > x) {
			std::cout << "����������� ��������� (" << a << ',' << b << ')';
		}
		else if (x < a) {
			std::cout << "����������� ��������� ( " << x << ',' << "<" << a << ')';
		}
		else if (x > b) {
			std::cout << "����������� ��������� ( " << x << ',' << ">" << b << ')';
		}
	}
	catch (...) {
		std::cout << "������ �����";
	}
}