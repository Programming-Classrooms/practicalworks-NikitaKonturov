#include<map>
#include<set>
#include<iterator>
#include<algorithm>
#include "../bus/bus.hpp"
#include "../funcs/funcs.hpp"



int main()
{
    try {
        std::vector<Bus> buss;
        readFile("src/data/buses.txt", buss);
        std::cout << "Список автобусов" << std::endl;
        std::copy(buss.begin(), buss.end(), std::ostream_iterator<Bus>(std::cout, "\n"));

        std::sort(buss.begin(), buss.end(), [](const Bus& first, const Bus& second){
            if(first.getBusNumber() == second.getBusNumber()) {
                return first.getBusRoute() < second.getBusRoute();
            }

            return first.getBusNumber() < second.getBusNumber();
        });

        std::cout << "Отсортированный список автобусов" << std::endl;
        std::copy(buss.begin(), buss.end(), std::ostream_iterator<Bus>(std::cout, "\n"));

        std::map<uint8_t, Bus> busMap; 
        fillingMap(buss, busMap);

        std::set<uint16_t> listRoute;
        for(const auto bus : busMap) {
            listRoute.insert(bus.second.getBusRoute());
        }

        std::cout << "Список различных маршрутов: ";
        std::copy(listRoute.begin(), listRoute.end(), std::ostream_iterator<uint16_t>(std::cout, " "));
        std::cout << std::endl;

        std::cout << "Введите маршрут: ";
        uint16_t numberRoute;
        std::cin >> numberRoute;
        std::cout << std::endl; 

        bool noRoute = true;
        std::cout << "Список автобусов с указанным маршрутом: " << std::endl;
        for(const auto bus : busMap) {
            if(bus.second.getBusRoute() == numberRoute) {
                std::cout << bus.second << std::endl;
                noRoute = false;
            }
        }

        if(noRoute) {
            std::cout << "Маршрут не найден!" << std::endl;
        }        

        std::cout << "Введите номер автоббуса который хотите удалить: ";
        uint16_t busNumber;
        std::cin >> busNumber;
        std::cout << std::endl; 
        
        busMap.erase(busNumber);

        std::cout << "Cписок автобусов после удаления" << std::endl;

        for(const auto bus : busMap) {
            std::cout << bus.second << std::endl;
        }

        std::multimap<uint8_t, Bus> routeMap;

        for(const auto bus : busMap) {
            routeMap.insert(std::pair<uint8_t, Bus>(bus.second.getBusRoute(), bus.second));
        }
        




    }
    catch(std::invalid_argument &err) {
        std::cerr << "Invalid argument: " << err.what() << std::endl;
    }
    return 0;
}
