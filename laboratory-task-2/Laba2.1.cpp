#include <iostream>


uint64_t quickPow(int a, int b) {
        if (b == 0){
                return 1;
        }
        if (b % 2 == 0){
                return quickPow(a * a, b / 2);
        }else{
                return a * quickPow(a, b - 1);
        }
}


uint64_t getNum(){
	int64_t num = 0;
	while (num <= 0){
		std::cout << "Enter num = ";
		std::cin >> num;
		std::cout << '\n';
	}
	return static_cast<uint64_t>(num);
}


uint64_t getNumOfNumbers(uint64_t  num){
	uint64_t numOfNumbers = 0;
	while(num != 0){
		num /= 10;
		++numOfNumbers;
	}
	return numOfNumbers;
}

int main() {
	uint64_t num =getNum();
	uint64_t numOfNumbers = getNumOfNumbers(num);

	std::cout << "num_of_numbers = " << numOfNumbers << '\n';

	if ((numOfNumbers % 2) != 0) {
		uint64_t central_num = num / quickPow(10, ((numOfNumbers + 1) / 2) - 1) % 10;
		std::cout << "central_num = " << central_num << '\n';
		uint64_t result = central_num * quickPow(10, numOfNumbers + 1) + num * 10 + central_num;
		std::cout << "Result = " << result;
	}
	else {
		std::cout << "It's even...";
	}
	return 0;
}
