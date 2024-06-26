#include"task-6.hpp"


void readFile(std::vector<Train>& vectorWithTrain, std::ifstream& fin) 
{
    Train source;
    while(fin >> source) {
        vectorWithTrain.push_back(source);    
    }
}

void sixTask(std::string& path)
{
    std::ifstream fin(path);

    std::vector<Train> trainVector;
    checkFile(fin, path);

    readFile(trainVector, fin);
    std::cout << "Файл считан..." << std::endl;

    fin.close();

    std::sort(trainVector.begin(), trainVector.end(), [](const Train& first, const Train& second){return first.getDepartureTime() < second.getDepartureTime();});

    // Вывод вектора в одну строчку
    std::cout << "Вектор отсортированный по дате отправления:" << std::endl;
    std::copy(trainVector.begin(), trainVector.end(), std::ostream_iterator<Train>(std::cout, "###########################################\n"));

    Time first =  {0, 0};
    Time second = {0, 0};
    std::cout << "Введите нижнию и верхнюю границы времени отправления: ";
    std::cin >> first >> second;
    if(first > second) {
        std::swap(first, second);
    }

    std::cout << "Поезда отпраляющиеся в этот промежуток времени: " << std::endl;
    std::copy_if(trainVector.begin(), trainVector.end(), std::ostream_iterator<Train>(std::cout, "###########################################\n"), [first, second](const Train& item){
        double departureTime = item.getDepartureTime();
        return departureTime > first.getTime() && departureTime < second.getTime();
    });

    std::cout << std::endl;
    std::string destination = "";  
    std::cout << "Введите пункт назначения: ";
    std::cin >> destination;
    std::cout << std::endl << "Поезда идущие в " << destination << ":" << std::endl;
    std::copy_if(trainVector.begin(), trainVector.end(), std::ostream_iterator<Train>(std::cout, "###########################################\n"), [destination](const Train& item){
        return destination == item.getDestination();
    });
    
    std::cout << std::endl;
    std::cout << "Все скорые поезда напрвляющиеся в заданный пункт назначения: " << std::endl;
    std::copy_if(trainVector.begin(), trainVector.end(), std::ostream_iterator<Train>(std::cout, "###########################################\n"), [destination](const Train& item){
        return destination == item.getDestination() && item.getTypeOfTrain() == trainType::Express;
    });
    std::cout << std::endl;


    std::cout << "Самый быстрый поезд следующий в " << destination << std::endl;
    std::cout << *std::min_element(trainVector.begin(), trainVector.end(), [destination](const Train& first, const Train& second){
        std::string firstDestination = first.getDestination();
        std::string secondDestination = second.getDestination();
        if (firstDestination == destination && secondDestination == destination) {
            return first.getTravelTime() < second.getTravelTime();
        }
        else if(firstDestination == destination)
        {
            return true;
        }
        else {
            return false;
        }
    }) << std::endl;
}
