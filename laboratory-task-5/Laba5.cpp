#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>

double arctang(double x) { // первая подинтегральная функция
	return (x * std::atan(x));
}

double difference(double x) { // вторая подинтегральная функция
	return (1 / (1 + sqrt(x)));
}

double diffirenceToSecond(double x) { // третяя подинтегральная функция
	return (2 / (1 - 4 * x));
}



double InegrTrapecia(const std::function<double(double)>&f, double a, double b, double eps) { // формула трапеций
	uint64_t n = 4;
	double weight = 0;
	double x1 = 0, x2 = 0;
	double s1 = 0;
	double s2 = 0.5 * (f(a) + f(b)) * (b - a);
	do {
		s1 = s2;
		n *= 2;
		weight = (b - a) / n;
		s2 = 0;
		for (int step = 0; step < n; ++step) {
			x1 = a + step * weight;
			x2 = a + (step + 1) * weight;
			s2 += 0.5 * (x2 - x1) * (f(x1) + f(x2));
		}
	} while (fabs(s1 - s2) > eps);
	return s2;
}

double rightIntegral(const std::function<double(double)>&f, double a, double b, double eps) { // метод правых прямоугольников
	uint64_t n = 8;
	double weight = 0.0;
	double x = 0.0;
	double s1 = 0.0;
	double s2 = f(b) * (b - a);
	while (fabs(s1 - s2) >= eps) {
		s1 = s2;
		s2 = 0.0;
		n *= 2;
		weight = (b - a) / n;
		for (int step = 0; step <= n; ++step) {
			x = a + step * weight;
			s2 += weight * f(x);
		}
	}
	return s2;
}

double summIntegral(const std::function<double(double)>&f, uint64_t n, double a, double b) { // вычисление интеграла по методу Симпсона
	double weight = (b - a) / n;
	double sumEven = 0;
	double sumUnEven = 0;
	for (uint64_t i = 1; i < n; ++i) {
		if ((i % 2) == 0) {
			sumEven += (2 * f(a + i * weight));
		}
		else {
			sumUnEven += (4 * f(a + i * weight));
		}
	}
	double result = weight/3 * ((sumEven) + (sumUnEven) + f(n * weight));
	return result;
}




double simpsonMethod(const std::function<double(double)>&f, double a, double b, double eps) {
	uint64_t n = 4;
	double x = 0;
	double s1 = 0;
	double s2 = summIntegral(f, n, a, b);
	n *= 2;
	while (fabs(s2 - s1) > eps) {
		s1 = s2;
		s2 = summIntegral(f, n, a, b);	
		n *= 2;
	}
	return s2;
}

void getAandB(double &a, double &b ) {
	std::cout << "Enter a = ";
	std::cin >> a;
	std::cout << "Enter b = ";
	std::cin >> b;
	if (a > b)
		std::swap(a, b);
}
double getEps() {
	double eps = -1;
	while (eps <= 0) {
		std::cout << "Epsselont must be natural: ";
		std::cin >> eps;
	}
	return eps;
}




void main() {
	
	double a = 0;
	double b = 0;
	double (*func[3])(double) = {arctang, difference, diffirenceToSecond };
	for (size_t i = 0; i < 3; i++){
		getAandB(a, b);
		double Integral = simpsonMethod(func[i], a, b, getEps());
		std::cout << std::setprecision(10)<< Integral << '\n';
	}
}
