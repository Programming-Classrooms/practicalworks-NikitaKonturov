/*
                                Лабораторная работа №4 задание 3

Описать абстрактный класс Дерево с информацией о названии, возрасте, типе (лиственное/хвойное – тип enum).
Описать производный класс Лесное дерево с доп. информацией о количестве древесины. 
Описать производный класс Плодовое дерево с доп. информацией о массе урожая и средней продолжительности хранения. 
Реализовать класс Контейнер_Деревьев на основе вектора. В контейнере нужно:
        ◦ Реализовать метод вывода информации о деревьях (в классе Дерево определить специальный метод, который будет переопределяться в каждом производном классе).
        ◦ Реализовать методы подсчета количества деревьев определенного типа: лиственное/хвойное и вида: лесное/плодовое.
        ◦ Реализовать метод вывода информации о деревьях с сортировкой по 2-м критериям: по названию (по возрастанию), затем по возрасту (по убыванию).

Контейнер заполняется информацией из файла. В одном файле представлены различные виды деревьев: как лесные, так и плодовые.
*/


#include<fstream>
#include "../class/Forest.hpp"


bool checkFile(std::ifstream& file, std::string path)
{
	if (!file.good()) {
		std::string mes = "File not found... Path: ";
		mes.append(path); 
		throw std::invalid_argument(mes);
	}
	if (!file) {
		std::string mes = "File is bad... Path: ";
		mes.append(path); 
		throw std::ios_base::failure(mes);
	}
	if (file.peek() == EOF) {
		std::string mes = "File is empti... Path: ";
		mes.append(path); 
		throw std::runtime_error(mes);
	}
	return true;
}

int main()
{
    try {
        Forest forest;
        std::ifstream fin("src/files/trees.txt");
        if (checkFile(fin, std::string("src/files/trees.txt"))) {
            fin >> forest;
            forest.sortPrint(std::cout);
            ForestTree* seekForestTree = new ForestTree;
            FruitTree* seekFruitTree = new FruitTree;
            std::cout << "Forest have " << forest.countingType(TreeType::Coniferous) << " coniferous tree" << std::endl;
            std::cout << "Forest have " << forest.countingType(TreeType::Deciduous) << " deciduousv tree"<< std::endl;
            std::cout << "Forest have " << forest.countingView(dynamic_cast<Tree *>(seekForestTree)) << " forest tree" << std::endl;
            std::cout << "Forest have " << forest.countingView(dynamic_cast<Tree *>(seekFruitTree)) << " fruit tree" << std::endl;
            delete seekForestTree;
            delete seekFruitTree;
        }
    }
    catch (std::invalid_argument &err) {
        std::cerr << "Invalid_argument: " << err.what() << std::endl;
    }
    catch (std::ios_base::failure &err) {
        std::cerr << "Ios_base::failure: " << err.what() << std::endl;
    }
    catch (std::runtime_error &err) {
        std::cerr << "Runtime_error: " << err.what() << std::endl;
    }
    return 0;
}
