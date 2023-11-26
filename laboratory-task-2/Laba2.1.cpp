#include <iostream>
uint64_t powMy(const int& a, const int& b) {
	uint64_t res = static_cast<uint64_t>(a);
	for (int i = 1; i < b; ++i) {
		res *= static_cast<uint64_t>(a);
	}
	return res;
}


void main() {
	uint64_t num = 0;
	while (num <= 0){
		std::cout << "Enter num = ";
		std::cin >> num;
		std::cout << '\n';
	}
	uint64_t num_of_numbers = 0;
	int temp = num;
	while (temp != 0) {
		temp /= 10;
		num_of_numbers++;
	}

	std::cout << "num_of_numbers = " << num_of_numbers << '\n';

	if ((num_of_numbers % 2) != 0) {
		uint64_t central_num = num / powMy(10, ((num_of_numbers + 1) / 2) - 1) % 10;
		std::cout << "central_num = " << central_num << '\n';
		uint64_t result = central_num * powMy(10, num_of_numbers + 1) + num * 10 + central_num;
		std::cout << "Result = " << result;
	}
	else {
		std::cout << "It's even...";
	}

}