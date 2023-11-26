#include<iostream>


void main() {
	int number = 0;
	while (number <= 0) {
		std::cout << "Enter num = ";
		std::cin >> number;
	}


	std::cout << '\n';
	int quantity = 0;
	std::string mod = "Unduplicaetid";
	for (int num = 0; num <= 9; num++) {
		
		int temp = number; 
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