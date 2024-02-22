#include "../funcs/myString.hpp"

int main() {
  try {
    myString str1 = "Heo";
    myString str2 = "ll";
    str1.insert(str2, 2);
    str2.clear();
    if (str2.empty()) {
      std::cout << "Str2 empty" << std::endl;
    }
    std::cout << str1 << std::endl;
    str1.push_back('_');
    std::cout << str1 << std::endl;
    str1.append("word!");
    std::cout << str1 << std::endl;
    str1.replace("_my_", 5, 1);
    std::cout << str1 << std::endl;
    myString str3 = "!!!!";
    myString str4 = str1 + str3;
    std::cout << str4 << std::endl;
    char *cStr = str4.c_str();
    std::cout << cStr << std::endl;

    delete[] cStr;
  } catch (std::exception &err) {
    std::cerr << err.what() << std::endl;
  }
  return 0;
}