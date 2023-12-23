/*
 Вариант 8
 Разработать консольное приложение для вычисления приближённого значения функции, используя представление ее в виде ряда Тейлора.
 Вычисления заканчивать, когда очередное слагаемое окажется по модулю меньше заданного числа epsilon,
 где 0<epsilon<= 10-k , k – натуральное число, k>1.
 Сравнить полученный результат со значением, вычисленным с помощью стандартных функций.
 Значение x и k ввести по запросу.
*/

#include <iostream>
#include <cmath>
#include <Windows.h>
#include <iomanip>

void main()
{
	try{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		double x = 1;
		while (x <= -1 || x >= 1){
			std::cout << "Введите числа в диапазоне от (-1; 1): " << std::endl;
			std::cin >> x;
		}
		int32_t k;
		std::cout << "Введите к = ";
		std::cin >> k;
		if (k < 1){
			throw std::exception("k должно быть натуральным и больше 1");
		}
		double epsilon = -1;
		while (epsilon < 0 || epsilon > pow(10, -k)){
			std::cout << "Введите еps в диапазоне  от 0 до " << std::setprecision(9) << pow(10, -k) << ": ";
			std::cin >> epsilon;
		}
		double term = 1;
		double sum = 1;
		int32_t i = 0;
		while (fabs(term) >= epsilon){
			term *= x * (0.5 - i) / (i + 1);
			sum += term;
			i++;
		}
		std::cout << std::setprecision(9) << "корень из (1 + " << x << ") = " << sum << std::endl;
		std::cout << "Контрольное значение = " << std::setprecision(9) << std::sqrt(x + 1);
	}
	catch (std::exception err){
		std::cerr << err.what() << std::endl;
	}
}