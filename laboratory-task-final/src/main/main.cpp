#include<iterator>
#include<algorithm>
#include "../funcs/funcs.hpp"
#include "../bus/bus.hpp"



int main()
{
    try {
        std::vector<Bus> buss;
        readFile("src/data/buses.txt", buss);
        std::copy(buss.begin(), buss.end(), std::ostream_iterator<Bus>(std::cout, "\n"));

    }
    catch(std::invalid_argument &err) {
        std::cerr << "Invalid argument: " << err.what() << std::endl;
    }
    return 0;
}
