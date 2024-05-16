#include "../funcs/funcs.hpp"
#include <fstream>
#include <algorithm>
#include <iterator>


int main()
{
    std::set<std::string> firstFisher;
    std::set<std::string> secondFisher;
    std::set<std::string> thirdFisher;
    std::set<std::string> lake;

    fillingLake(lake);

    fillingFisher(firstFisher, lake, 1);
    std::cin.clear();
    std::cin.ignore();
    fillingFisher(secondFisher, lake, 2);
    std::cin.clear();
    std::cin.ignore();
    fillingFisher(thirdFisher, lake, 3);

    std::ofstream fout("src/files/info.txt");

    fout << "Первый рыбак поймал: ";
    std::copy(firstFisher.begin(), firstFisher.end(), std::ostream_iterator<std::string>(fout, " "));
    fout << std::endl;

    fout << "Второй рыбак поймал: ";
    std::copy(secondFisher.begin(), secondFisher.end(), std::ostream_iterator<std::string>(fout, " "));
    fout << std::endl;
    
    fout << "Третий рыбак поймал: ";
    std::copy(thirdFisher.begin(), thirdFisher.end(), std::ostream_iterator<std::string>(fout, " "));
    fout << std::endl;
    

    std::set<std::string> intersectionFisrtAndSecond;
    std::set<std::string> intersectionFirstSecondThird;
    std::set_intersection(firstFisher.begin(), firstFisher.end(), secondFisher.begin(), secondFisher.end(), std::inserter(intersectionFisrtAndSecond, intersectionFisrtAndSecond.begin()));
    std::set_intersection(intersectionFisrtAndSecond.begin(), intersectionFisrtAndSecond.end(), thirdFisher.begin(), thirdFisher.end(), std::inserter(intersectionFirstSecondThird, intersectionFirstSecondThird.begin()));
    
    fout << "Рыбы присутствующие у каждого рыбака: ";
    std::copy(intersectionFirstSecondThird.begin(), intersectionFirstSecondThird.end(), std::ostream_iterator<std::string>(fout, " "));   
    fout << std::endl;

    std::set<std::string> unionFirstSecond;
    std::set<std::string> unionFirstSecondThird;
    std::set_union(firstFisher.begin(), firstFisher.end(), secondFisher.begin(), secondFisher.end(), std::inserter(unionFirstSecond, unionFirstSecond.begin()));
    std::set_union(unionFirstSecond.begin(), unionFirstSecond.end(), thirdFisher.begin(), thirdFisher.end(), std::inserter(unionFirstSecondThird, unionFirstSecondThird.begin()));
    
    fout << "Рыбы присутствующие хотябы у одного рыбка: ";
    std::copy(unionFirstSecondThird.begin(), unionFirstSecondThird.end(), std::ostream_iterator<std::string>(fout, " "));
    fout << std::endl;

    std::set<std::string> difference;
    std::set_difference(lake.begin(), lake.end(), unionFirstSecondThird.begin(), unionFirstSecondThird.end(), std::inserter(difference, difference.begin()));
    fout << "Рыбы не пойманные хотя бы одним рыбаком: ";
    std::copy(difference.begin(), difference.end(), std::ostream_iterator<std::string>(fout, " "));
    fout << std::endl;

    
    return 0;   
}
