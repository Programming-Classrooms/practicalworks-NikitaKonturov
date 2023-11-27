#include <iostream>
#include <iomanip>


int32_t factorial(int32_t start, int32_t finish) {
	if (start + 1 == finish) {
          return start * finish;
	}else{
	  return factorial(start, (start + finish) / 2) * factorial(((start + finish) / 2) + 1, finish);
	}
}

int32_t getNum(){
  int32_t num = 0;
  while (num <= 0) {
      std::cout << "Enter num = ";
      std::cin >> num;
    }
  return num;
}


int main() {	
        int32_t num = getNum();
	int32_t denominator = factorial(1, num);
	for (size_t j = denominator - 1; j > 1; --j) {
		int32_t numerator = denominator - j;
		int32_t tempDenominator = denominator;
		for (size_t i = denominator; i > 0; --i){
			if (tempDenominator % i == 0 && numerator % i == 0){
				numerator /= i;
				tempDenominator /= i;
			}
		}
		if (tempDenominator <= num) {
			std::cout <<std::setw(10)<< numerator << '/' << tempDenominator;
		}
      }
      return 0;
} 


