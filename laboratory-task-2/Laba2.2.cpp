#include<iostream>


int32_t getNum(){
  int32_t number = 0;
      while (number <= 0) {
    	std::cout << "Enter num = ";
      	std::cin >> number;
  }
  return number;
}

void main() {
	int32_t number = getNum();
	std::cout << '\n';
	int32_t quantity = 0;
	std::string mod = "Unduplicaetid";
	for (size_t num = 0; num <= 9; num++) {
		int32_t temp = number; 
		if (quantity >= 2) {
			mod = "Duplicated...";
			break;
		}
		quantity = 0;	
		while (temp != 0) {
			if ((temp % 10) == num) {
				quantity++;
			}
		temp /= 10;	
		}
			
	}
	std::cout << mod;
}
