#include <iostream>


int factorial(int factor) {
	int res = 1;
	for (int i = 1; i <= factor; i++) {
		res *= i;
	}
	//std::cout << res << '\n';
	return res;
}




void main() {
	int num = 0;
	while (num <= 0) {
		std::cout << "Enter num = ";
		std::cin >> num;}
	int denominator = factorial(num);
	for (int j = denominator - 1; j > 1; --j) {
		int numerator = denominator - j;
		int temp_denominator = denominator;
		for (int i = denominator; i > 0; --i){
			if (temp_denominator % i == 0 && numerator % i == 0){
				numerator /= i;
				temp_denominator /= i;
			}
		}
		if (temp_denominator <= num) {
			std::cout << numerator << '/' << temp_denominator << '\t';
		}
	}
} 




