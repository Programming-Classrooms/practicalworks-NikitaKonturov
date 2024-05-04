
#include "../deque/deque.hpp"
#include "../cyclicQueue/cQueue.hpp"
#include "../Trucks/truck.hpp"


int main()
{
    try {
        TDeque<char*> obj1;

        for (size_t i = 0; i < 10; ++i) {
            obj1.InsFront("a");
        }
        TDeque<char*> obj2(obj1);
        
        char* frontElement = 0;
        char* rearElement = 0;

        obj1.DelFront(frontElement);
        obj1.DelRear(rearElement);

        std::cout << "First deque: ";
        obj1.BrowseWithoutModification(std::function<void(char*)>([](char* element){std::cout << element << " ";}));
        std::cout << std::endl;
        std::cout << "Second deque: ";
        obj2.BrowseWithoutModification(std::function<void(char*)>([](char* element){std::cout << element << " ";}));

        CQueue<Truck> queue;

        for (size_t i = 0; i < 10; ++i) {
            queue.push_back(Truck("Man", 150));
        }
        
        std::cout << "\nFirst cyclic queue: " << std::endl;  
        queue.print(std::cout);
        std::cout << "Size: " << queue.size() << std::endl;

        std::cout << queue.pop_front() << std::endl;

        std::cout << "Second cyclic queue: " << std::endl;
        queue.print(std::cout);
        std::cout << "Size: " << queue.size() << std::endl;  

        std::cout << queue[13] << std::endl;

        std::cout << queue.find(Truck("Man", 150)) << std::endl;
    }
    catch (std::invalid_argument &err) {
        std::cerr << "Invalid argument: " << err.what() << std::endl;
    }
    catch (std::out_of_range &err) {
        std::cerr << "Out of range: " << err.what() << std::endl;
    }    
    catch (std::exception &err) {
        std::cerr << "Anny exeption: " << err.what() << std::endl;
    }
    return 0;
}
