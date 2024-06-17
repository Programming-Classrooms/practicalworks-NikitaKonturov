#ifndef GEN_ISBN_HPP
#define GEN_ISBN_HPP
#include <iostream>
#include <stdint.h>
#include <vector>

// Генерация всех перстановок просто для эллементов
void generatePermutation(std::vector<uint8_t>&, std::vector<int8_t>&);
int64_t findIndexOfMaxMobileElement(const std::vector<uint8_t>&, const std::vector<int8_t>&);
void swapEllement(std::vector<uint8_t>&, std::vector<int8_t>& , size_t, size_t);
void changeDerection(const std::vector<uint8_t>&, std::vector<int8_t>&, size_t);

#endif //GEN_ISBN_HPP
