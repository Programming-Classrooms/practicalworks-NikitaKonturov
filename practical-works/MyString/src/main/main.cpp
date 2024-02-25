#include "../class/myString.hpp"


int main() 
{
    try {
        myString str = "Hello";
        myString str1;
        myString str2(str);
        myString str3(5);
        myString str4("!!!!");

        std::cout << str << std::endl;
         
        str.push_back(' ');

        std::cout << str << std::endl;

        str.append("world");

        std::cout << str << std::endl;

        str.insert(str4, str.getSize());

        std::cout << str << std::endl;

        str.replace("__my__", 5, 1);

        std::cout << str << std::endl;

        str.clear();

        if(str.empty()) {
            std::cout << "True" << std::endl;
        }

        std::cout << str2.getSize() << std::endl;

        myString str5 = str2 + str4;

        std::cout << str5 << std::endl;

        myString str6(str2);

        if (str6 == str2) {
            std::cout << "true" << std::endl;
        }

        myString testStr("Aaaa");
        myString testStr1("Bbbb");

        if (testStr < testStr1) {
            std::cout << "true" << std::endl; 
        }
        if (testStr1 > testStr) {
            std::cout << "true" << std::endl;
        }

        myString strInt = "45";
        int64_t num = static_cast<int64_t>(strInt);

        std::cout << num << std::endl;

        myString strDouble = "45.56";
        double doubleNum = static_cast<double>(strDouble);

        std::cout << doubleNum << std::endl;

        std::string text = static_cast<std::string>(str2);

        std::cout << text << std::endl;

    } 
    catch (std::exception &err) {
      std::cerr << err.what() << std::endl;
    }
    return 0;
}
