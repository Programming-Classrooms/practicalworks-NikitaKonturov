#include<fstream>
#include "../Library/Library.hpp"
#include "../menu/menu.hpp"


int main(int args, char** argv)
{
    try { 
        if (args == 2) {
            menu(argv[1]);
        }
        else {
            menu();
        }
    }
    catch(std::invalid_argument& err) {
        std::cerr << "Invalid argument: " << err.what() << std::endl;
    }
    catch(std::exception &err) {
        std::cerr << "Anny exeption: " << err.what() << std::endl;
    }

    return 0;
}
