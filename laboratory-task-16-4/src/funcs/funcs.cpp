#include "funcs.hpp"


void fillingFisher(std::set<std::string>& fisher, std::set<std::string>& lake, size_t fisherNuber)
{
    std::string fish = "";
    std::cout << "В озере водяться следующие виды рыб:" << std::endl;
    std::copy(lake.begin(), lake.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Введите рыбу которую поймал "<< fisherNuber <<"-й рыбак: "; 
    std::cin >> fish;
    std::cout << std::endl;
    while (lake.find(fish) != lake.end()) {
        fisher.insert(fish);
        std::cout << "Введите рыбу которую поймал "<< fisherNuber <<"-й рыбак: "; 
        std::cin >> fish;
        std::cout << std::endl;
    }
}

void fillingLake(std::set<std::string>& lake)
{
    std::string fish = "";
    std::cout << "Заполните озеро рыбой!!!(для окончания ввода введите end)" << std::endl;
    std::cin >> fish;
    std::cout << std::endl;
    while(fish != "end") {
        lake.insert(fish);
        std::cin >> fish;
        std::cout << std::endl;
    }
}
