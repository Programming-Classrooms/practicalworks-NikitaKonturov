/*
	Вычислить значение определенного интеграла с аналитически заданной подынтегральной
	функцией с заданной точностью eps
	Б) по формуле правых прямоугольников;
	Д) по формуле Симпсона (параболических трапеций).
*/

#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>


// first functin
double arctang(double x) 
{ 
	return (x * std::atan(x));
}

// second function
double difference(double x) 
{ 
	return (1 / (1 + sqrt(x)));
}

// third function
double diffirenceToSecond(double x) 
{ 
	return (2 / (1 - 4 * x));
}

// trapezoid metрod  
double trapezoidMethod(const std::function<double(double)>&f, double leftBoardOfInegration, double rightBoardOfInegration, double eps)
{ 
	uint64_t partition = 4;
	double width = 0;
	double x1 = 0, x2 = 0;
	double s1 = 0;
	double s2 = 0.5 * (f(leftBoardOfInegration) + f(rightBoardOfInegration)) * (rightBoardOfInegration - leftBoardOfInegration);
	do {
		s1 = s2;
		partition *= 2;
		width = (rightBoardOfInegration - leftBoardOfInegration) / partition;
		s2 = 0;
		for (int step = 0; step < partition; ++step) {
			x1 = leftBoardOfInegration + step * width;
			x2 = leftBoardOfInegration + (step + 1) * width;
			s2 += 0.5 * (x2 - x1) * (f(x1) + f(x2));
		}
	} while (fabs(s1 - s2) > eps);
	return s2;
}

// right rectangle metрods
double methodRightRectangle(const std::function<double(double)>&f, double leftBoardOfInegration, double rightBoardOfInegration, double eps) 
{ 
	uint64_t partition = 8;
	double width = 0.0;
	double x = 0.0;
	double s1 = 0.0;
	double s2 = f(rightBoardOfInegration) * (rightBoardOfInegration - leftBoardOfInegration);
	while (fabs(s1 - s2) >= eps) {
		s1 = s2;
		s2 = 0.0;
		partition *= 2;
		width = (rightBoardOfInegration - leftBoardOfInegration) / partition;
		for (int step = 0; step <= partition; ++step) {
			x = leftBoardOfInegration + step * width;
			s2 += width * f(x);
		}
	}
	return s2;
}

// sum parabolic trapezoids for Simpson method
double summIntegral(const std::function<double(double)>&f, uint64_t partition, double leftBoardOfInegration, double rightBoardOfInegration) 
{ 
	double width = (rightBoardOfInegration - leftBoardOfInegration) / partition;
	double sumEven = 0;
	double sumUnEven = 0;
	for (uint64_t i = 1; i < partition; ++i) {
		if ((i % 2) == 0) {
			sumEven += (2 * f(leftBoardOfInegration + i * width));
		}
		else {
			sumUnEven += (4 * f(leftBoardOfInegration + i * width));
		}
	}
	double result = width/3 * ((sumEven) + (sumUnEven) + f(partition * width));
	return result;
}

double simpsonMethod(const std::function<double(double)>&f, double leftBoardOfInegration, double rightBoardOfInegration, double eps)
{ 
	uint64_t partition = 4;
	double x = 0;
	double s1 = 0;
	double s2 = summIntegral(f, partition, leftBoardOfInegration, rightBoardOfInegration);
	partition *= 2;
	while (fabs(s2 - s1) > eps) {
		s1 = s2;
		s2 = summIntegral(f, partition, leftBoardOfInegration, rightBoardOfInegration);	
		partition *= 2;
	}
	return s2;
}

void getLeftBoardOfInegrationAndleftBoardOfInegration(double &leftBoardOfInegration, double &rightBoardOfInegration ) 
{ 
	std::cout << "Enter left board of inegration = ";
	std::cin >> leftBoardOfInegration;
	std::cout << "Enter right board of inegration = ";
	std::cin >> rightBoardOfInegration;
	if (leftBoardOfInegration > rightBoardOfInegration)
		std::swap(leftBoardOfInegration, rightBoardOfInegration);
}


double getEps() 
{ 
	double eps = -1;
	while (eps <= 0) {
		std::cout << "Epsselont must be natural: ";
		std::cin >> eps;
	}
	return eps;
}

int main() 
{ 
	double leftBoardOfInegration = 0;
	double rightBoardOfInegration = 0;
	double (*func[3])(double) = {arctang, difference, diffirenceToSecond };
	for (size_t i = 0; i < 3; i++){
		getLeftBoardOfInegrationAndleftBoardOfInegration(leftBoardOfInegration, rightBoardOfInegration);
		double Integral = simpsonMethod(func[i], leftBoardOfInegration, rightBoardOfInegration, getEps());
		std::cout << std::setprecision(10)<< Integral << '\n';
	}
	return 0;
}
