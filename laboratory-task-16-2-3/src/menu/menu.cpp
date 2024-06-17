#include"menu.hpp"


// Проверка пути
void checkPath(std::filesystem::path pathToFile)
{
    pathToFile = std::filesystem::absolute(pathToFile);
    if (!std::filesystem::exists(pathToFile)) {
        throw std::invalid_argument(std::string("Filesysteam object not exist! Path:").append(pathToFile.string()));
    }
    if (!std::filesystem::is_regular_file(pathToFile)) {
        throw  std::invalid_argument(std::string("Filesysteam object is not regular file! Path: ").append(pathToFile.string()));
    }
    if (!pathToFile.has_extension() || pathToFile.extension() != std::filesystem::path(".txt")) {
        throw std::invalid_argument(std::string("File must has extension .txt! ").append(pathToFile.string()));
   }
}

void checkFile(std::ifstream& fin, std::string path)
{
    if(!fin) {
        throw std::invalid_argument(std::string("File is bad. Path: ").append(path));
    }
    if(!fin.is_open()) {
        throw std::invalid_argument(std::string("File was not opened. Path").append(path));
    }
    if(fin.peek() == EOF) {
        throw std::invalid_argument(std::string("File is empty. Path ").append(path));
    }
}

void menu(std::string path) 
{
    checkPath(path);
    std::ifstream fin(path);
    checkFile(fin, path);

    Library lib;
    std::string inputLabelForTitle;
    Author inputLabelForAuthor;
    Book inputLabelForBook;
    while (fin >> inputLabelForBook) {
        lib.insert(inputLabelForBook);
    }


    uint16_t action = 1;
    while (action != 0) {
        std::cout << "================= Меню =================" << std::endl;
        std::cout << "0) Завершить работу;" << std::endl; 
        std::cout << "1) Вывести все книги хранящиеся в библиотеке;" << std::endl;
        std::cout << "2) Добавить книгу;" << std::endl;
        std::cout << "3) Удалить книгу;" << std::endl;
        std::cout << "4) Удалить автора книги в библиотеке;" << std::endl;
        std::cout << "5) Добавить автора в книгу в библиотеке;" << std::endl;
        std::cout << "6) Выборка книг по названию;" << std::endl;
        std::cout << "7) Выборка книг по автору;" << std::endl;
        std::cin >> action;

            if (action == 1) {
            std::cout <<  "Текущее состояние библиотеки: " << std::endl;
            std::cout << lib << std::endl;
            std::cout << "######################################" << std::endl;
        }
        if (action == 2) {
            std::cout << "Введите книгу которую хотите добавить: ";
            std::cin >> inputLabelForBook;
            if (std::cin.fail()) {
                std::cout << "Не верный формат ввода!" << std::endl;
                std::cout << "######################################" << std::endl;
                continue;    
            }
            else {
                lib.insert(inputLabelForBook);
                std::cout << "######################################" << std::endl;
            }
        }
        if (action == 3) {
            std::cout << "Введите книгу которую хотите удалить: ";
            std::cin >> inputLabelForBook;
            if (std::cin.fail()) {
                std::cout << "Не верный формат ввода!" << std::endl;
                std::cout << "######################################" << std::endl;
                continue;
            }
            else {
                lib.ereas(inputLabelForBook);
                std::cout << "######################################" << std::endl;
            }
        }
        if (action == 4) {
            std::cout << "Введите книгу в которой хотите удалить автора: ";
            std::cin >> inputLabelForBook;
            if (std::cin.fail()) {
                std::cout << "Не верный формат ввода!" << std::endl;
                std::cout << "######################################" << std::endl;
                continue;
            }
            std::cout << "Введите автора которого хотите удалить из этой книги: ";
            std::cin >> inputLabelForAuthor;
            std::cout << std::endl;
            if(std::cin.fail()) {
                 std::cout << "Не верный формат ввода!" << std::endl;
                 std::cout << "######################################" << std::endl;
                continue;
            }
            lib.eraseAuthor(inputLabelForBook, inputLabelForAuthor);
            std::cout << "######################################" << std::endl; 
        }
        if (action == 5) {
            std::cout << "Введите книгу в которую хотите добавить автора: ";
            std::cin >> inputLabelForBook;
            if (std::cin.fail()) {
                std::cout << "Не верный формат ввода!" << std::endl;
                std::cout << "######################################" << std::endl;
                continue;
            }
            std::cout << "Введите автора которого хотите добавить в эту книгу: ";
            std::cin >> inputLabelForAuthor;
            std::cout << std::endl;
            if(std::cin.fail()) {
                 std::cout << "Не верный формат ввода!" << std::endl;
                 std::cout << "######################################" << std::endl;
                continue;
            }
            lib.addAuthor(inputLabelForBook, inputLabelForAuthor);
            std::cout << "######################################" << std::endl; 
        }
        if (action == 6) {
            std::cout << "Введите название кникиги по которой хотите сделать выборку: ";
            std::getline(std::cin, inputLabelForTitle);
            std::cout << std::endl;

            std::multimap<size_t, Book> booksWithSeakTitle = lib.find(inputLabelForTitle);

            if(booksWithSeakTitle.empty()) {
                std::cout << "Книг с названием " << inputLabelForTitle << " не существует!" << std::endl;
                std::cout << "######################################" << std::endl;
                continue;
            }

            std::cout << "Книги с названием " << inputLabelForTitle << std::endl;
            for (const auto& book : booksWithSeakTitle) {
                std::cout << book.second << std::endl;
            }

            std::cout << "######################################" << std::endl;
        }

        if (action == 7) {
            std::cout << "Введите автора которого по которому хотите сделать выборку: ";
            std::cin >> inputLabelForAuthor;
            std::cout << std::endl;
            if(std::cin.fail()) {
                 std::cout << "Не верный формат ввода!" << std::endl;
                 std::cout << "######################################" << std::endl;
                continue;
            }

            std::multimap<std::string, Book> booksWithSeakAuthor = lib.find(inputLabelForAuthor);

            if(booksWithSeakAuthor.empty()) {
                std::cout << "Книг с автором " << inputLabelForAuthor << " не существует!" << std::endl;
                std::cout << "######################################" << std::endl;
                continue;
            }

            std::cout << "Книги с автором " << inputLabelForTitle << std::endl;
            for (const auto& book : booksWithSeakAuthor) {
                std::cout << book.second << std::endl;
            }

            std::cout << "######################################" << std::endl;
        }
    }
}
