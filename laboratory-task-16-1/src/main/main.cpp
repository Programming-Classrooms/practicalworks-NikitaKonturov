
#include "../funcs/funcs.hpp"
#include <map>
#include <iostream>

int main() {
    // Пример работы с контейнером map
    std::map<int, std::string> myMap;

    // Вставка элементов в map
    myMap.insert({1, "one"});
    myMap.insert({2, "two"});
    myMap.insert({3, "three"});

    // Использование lower_bound и upper_bound
    auto it_lower = myMap.lower_bound(2); // Находим первый элемент с ключом, не меньшим 2
    auto it_upper = myMap.upper_bound(2); // Находим первый элемент с ключом, большим 2

    // Выводим элементы между lower_bound и upper_bound
    std::cout << "Elements between lower_bound and upper_bound:" << std::endl;
    for (auto it = it_lower; it != it_upper; ++it) {
        std::cout << it->second << std::endl;
    }

    // Пример работы с контейнером multimap
    std::multimap<int, std::string> myMultimap;

    // Вставка элементов в multimap
    myMultimap.insert({1, "apple"});
    myMultimap.insert({2, "banana"});
    myMultimap.insert({1, "orange"});

    // Использование lower_bound и upper_bound в multimap
    auto range = myMultimap.equal_range(1); // Находим диапазон элементов с ключом 1

    // Выводим элементы в диапазоне
    std::cout << "Elements with key 1:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << std::endl;
    }

    return 0;
}
