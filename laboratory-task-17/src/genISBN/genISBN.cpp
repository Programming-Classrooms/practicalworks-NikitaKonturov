#include"genISBN.hpp"


int64_t findIndexOfMaxMobileElement(std::vector<uint8_t>& permutation,const std::vector<int8_t>& direction)
{
    int64_t index = -1;
    for (size_t i = 0; i < permutation.size(); ++i) {
        if(((i + direction[i]) >= 0) && ((i + direction[i]) < permutation.size())) {
            if(permutation[i] > permutation[i + direction[i]]) {
                if(index == -1) {
                    index = i;
                }
                else if(permutation[i] > permutation[index]) {
                    index = i;
                }
            }
        }    
    }

    return index;
}

// можно передавать и один указатель на максимально мобильный эллемнт но оставим два для более наглядного представления алгоритма в главнной функции 
void swapEllements(std::vector<uint8_t>& permutation, std::vector<int8_t>& direction, size_t indexToMaxMobileEllement, size_t indexToIndicatedEllement)
{
    std::swap(permutation[indexToMaxMobileEllement], permutation[indexToIndicatedEllement]);
    std::swap(direction[indexToMaxMobileEllement], direction[indexToIndicatedEllement]);
}

void changeDerection(const std::vector<uint8_t>& permutation , std::vector<int8_t>& direction, size_t maxMobileEllement)
{
    for (size_t i = 0; i < permutation.size(); ++i) {
        if(permutation[i] > maxMobileEllement) {
            direction[i] *= -1;
        }
    }
}

void generatePermutation(std::vector<uint8_t>& permutation, std::vector<int8_t>& direction)
{
    int64_t indexToMaxMobileEllem = findIndexOfMaxMobileElement(permutation, direction);
    size_t maxMobileEllem = 0;
    size_t j = 0;
    if (indexToMaxMobileEllem != -1) {
        maxMobileEllem = permutation[indexToMaxMobileEllem];
        swapEllements(permutation, direction, indexToMaxMobileEllem, direction[indexToMaxMobileEllem] + indexToMaxMobileEllem);
        changeDerection(permutation, direction, maxMobileEllem);
    }
    else {
        throw std::invalid_argument("Not have permutation...");
    }
}
