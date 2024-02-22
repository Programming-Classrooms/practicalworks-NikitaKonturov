#include "../funcs/myString.hpp"

int main() {
  try {
    myString str1 = "Heo";
    myString str2 = "ll";
    str1.insert(str2, 2);
    str1.clear();
    std::cout << str1;
  } catch (std::exception &err) {
    std::cerr << err.what() << std::endl;
  }
  return 0;
}