#include "fstream"
#include "../library/library.hpp"


int main()
{
    try {
         Library library;

         // Создание книг
         Book book1("The C++ Programming Language", {"Bjarne Stroustrup"}, 100, 10);
         Book book2("Effective Modern C++", {"Scott Meyers"}, 150, 5);
         Book book3("Design Patterns: Elements of Reusable Object-Oriented Software",{"Erich Gamma", "Richard Helm", "Ralph Johnson", "John Vlissides"}, 200, 7);

         // Добавление книг в библиотеку
         library.insert(book1);
         library.insert(book2);
         library.insert(book3);

     
        // Вывод всей библиотеки
        std::cout << "Library Contents:" << std::endl;
        std::cout << library << std::endl;

        // Поиск книги по ISBN
        std::string searchISBN = book1.getISBN();
        std::shared_ptr<Book> foundBook = library.find(searchISBN);
        if (foundBook != nullptr) {
            std::cout << "Book with ISBN " << searchISBN << " found: " << *foundBook << std::endl;
        } else {
            std::cout << "Book with ISBN " << searchISBN << " not found." << std::endl;
        }

        // Удаление книги по ISBN
        std::string deleteISBN = book2.getISBN();
        library.ereas(deleteISBN);
        std::cout << "Deleted book with ISBN " << deleteISBN << "." << std::endl;

        // Вывод библиотеки после удаления
        std::cout << "Library Contents After Deletion:" << std::endl;
        std::cout << library << std::endl;

        // Добавление и удаление автора
        std::string authorToAdd = "John Doe";
        std::string authorToRemove = "Bjarne Stroustrup";
        std::string isbnToModify = book1.getISBN();
        
        library.addAuthor(isbnToModify, authorToAdd);
        library.eraseAuthor(isbnToModify, authorToRemove);

        // Вывод библиотеки после изменений
        std::cout << "Library Contents After Adding and Removing Author:" << std::endl;
        std::cout << library << std::endl;

        // Сортировка по названию
        std::multimap<std::string, Book> sortedBooks = library.sortAboutTitle();

        // Вывод отсортированных книг
        std::cout << "Sorted Books by Title:" << std::endl;
        for (const auto& entry : sortedBooks) {
            std::cout << entry.second << std::endl;
        }
    }
    catch(std::invalid_argument &err) {
        std::cerr << "Invalid argument: " << err.what() << std::endl;
    }
    catch(std::exception &err) {
        std::cerr << "Any exeptiom: " << err.what() << std::endl;
    }
    return 0;
}
