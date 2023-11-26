#include <ctime>
#include <iostream>

void del(int* arr0){
	delete[] arr0;
}

void swap(int & a, int & b){
	int help = b;
	b = a;
	a = help;
}

int input_from_keyboard (int *arr, const int & lenArr){
	for (int i = 0; i < lenArr; ++i){
		int num = 0;
		while (num <= 0){
			std::cout << "Enter element = ";
			std::cin >> num;
			arr[i] = num;
		}
	}
return 0;
}

int input_random(int *arr, const int & lenArr){
	int a = 0, b = 0;
	while (a == b || a <= 0 || b <= 0){
		std::cout << "Enter board valuse = ";
		std::cin >> a >> b;
		if (a > b){
			swap(a, b);
		}
	}
	for (int i = 0; i < lenArr; ++i){
		arr[i] = a + ((rand() % b) + 1);
	}
return 0;
}

void out_arr(int* arr, const int & lenArr){
	for (int i = 0; i < lenArr; ++i){
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
int input_lenArr(){
	int lenArr = 0;
	while (lenArr <= 0){
		std::cout << "Enter lenght array = ";
		std::cin >> lenArr;
	}
return lenArr;
}

void filling_arr(int *arr0, const int & lenArr0){
int condition = 0;
        while (condition != 1 && condition != 2){
                std::cout << "Enter codition 1 - input keyboard, 2 - random values = ";
                std::cin >> condition;
        }

        switch (condition) {
                case 1:
                        input_from_keyboard(arr0, lenArr0);
			break;
                case 2:
                        input_random(arr0, lenArr0);
                        std::cout << "Array generared " << '\n'; 
                        out_arr(arr0, lenArr0);
			break;
        }
}

uint64_t get_min_max(int *arr, int & lenArr){
	int maxNum = arr[0];
	int MinEll = arr[0];
	for (int i = 1; i < lenArr; ++i){
		if (maxNum < arr[i]){
			maxNum = arr[i];
		}
		if (MinEll > arr[i]){
			MinEll = arr[i];

		}
	}
	uint32_t UminEll = (uint32_t)(MinEll);
	uint32_t UmaxEll = (uint32_t)(maxNum);
	uint64_t min_max = 0;
	
	min_max |= ((uint64_t)(UmaxEll)) ;
	min_max |= ((((uint64_t)(UminEll)) << 32) & 0xffffffff00000000);
	return min_max;
}
void read_print_min_max (const uint64_t &  min_max,const int& lenArr, int* arr){
	uint32_t min = (uint32_t)(min_max >> 32);
	uint32_t max = (uint32_t)(min_max & 0x00000000ffffffff);
	int Min = (int)(min);
	int Max = (int)(max);

	for (int i = 0; i < lenArr; ++i){
		if (Max == arr[i]){
			std::cout << "Max element has index = " << i << '\n';
		
		}
	}
	if (Min == 1){
		Min++;
		for(int i = 0; i < lenArr; ++i){
			if(Min == arr[i]){
			Min++;
			}
		}
	}
	std::cout << "Min element not contained in array = " << Min - 1 << '\n';
}




int main(){
	srand(time(0));

	int lenArr = input_lenArr();

	int* arr = new int[lenArr];	
	filling_arr(arr, lenArr);
	read_print_min_max(get_min_max(arr, lenArr), lenArr, arr);
	int* new_arr = new int[lenArr];
	int number_sort = 0;
	while (number_sort <= 0){
		std::cout << "Enter sort number = ";
		std::cin >> number_sort;
	}
	int quvontity = 0;
	for (int i = 0; i < lenArr; ++i){
		if (arr[i] < number_sort){
			new_arr[quvontity] = arr[i];
			quvontity++;
			}
	
	}	
	for (int i = 0; i < lenArr; ++i){
		if (arr[i] >= number_sort){
			new_arr[quvontity] = arr[i];
			quvontity++;
		}

	}
	out_arr(new_arr, lenArr);
	del(arr);
	del(new_arr);

	return 0;

}
	
