#include<iterator>
#include<algorithm>
#include<map>
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



    }
    catch(std::invalid_argument &err) {
        std::cerr << "Invalid argument: " << err.what() << std::endl;
    }
    return 0;
}
