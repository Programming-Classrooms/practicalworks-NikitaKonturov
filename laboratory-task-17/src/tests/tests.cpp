
#include <stdexcept>
#include <gtest/gtest.h>
#include "../book/book.hpp"
#include "../library/library.hpp"


class BookTest : public ::testing::Test {
protected:
    void SetUp() override {
        book1 = Book("The C++ Programming Language", {"Bjarne Stroustrup"}, 100, 10);
        book2 = Book("Effective Modern C++", {"Scott Meyers"}, 150, 5);
        book3 = Book("Design Patterns: Elements of Reusable Object-Oriented Software", 
                     {"Erich Gamma", "Richard Helm", "Ralph Johnson", "John Vlissides"}, 200, 7);
    }

    // Объекты, которые будут использоваться в тестах
    Book book1;
    Book book2;
    Book book3;
};

class LibraryTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Инициализация некоторых книг для тестов
        book1 = Book("The C++ Programming Language", {"Bjarne Stroustrup"}, 100, 10);
        book2 = Book("Effective Modern C++", {"Scott Meyers"}, 150, 5);
        book3 = Book("Design Patterns: Elements of Reusable Object-Oriented Software", 
                     {"Erich Gamma", "Richard Helm", "Ralph Johnson", "John Vlissides"}, 200, 7);
        
        library.insert(book1);
        library.insert(book2);
        library.insert(book3);
    }

    // Объекты, которые будут использоваться в тестах
    Library library;
    Book book1;
    Book book2;
    Book book3;
};

// Тест конструктора по умолчанию
TEST_F(BookTest, DefaultConstructor) {
    Book book;
    EXPECT_EQ(book.getTitle(), "");
    EXPECT_TRUE(book.getAuthors().empty());
    EXPECT_EQ(book.getPrice(), 0);
    EXPECT_EQ(book.getCount(), 0);
    EXPECT_FALSE(book.getISBN().empty());
}

// Тест конструктора с параметрами
TEST_F(BookTest, ParameterizedConstructor) {
    EXPECT_EQ(book1.getTitle(), "The C++ Programming Language");
    EXPECT_EQ(book1.getAuthors().size(), 1);
    EXPECT_EQ(book1.getPrice(), 100);
    EXPECT_EQ(book1.getCount(), 10);
    EXPECT_FALSE(book1.getISBN().empty());
}

// Тест конструктора с инициализацией списка
TEST_F(BookTest, InitializerListConstructor) {
    Book book("Some Book", {"Author1", "Author2"}, 50, 3);
    EXPECT_EQ(book.getTitle(), "Some Book");
    EXPECT_EQ(book.getAuthors().size(), 2);
    EXPECT_EQ(book.getPrice(), 50);
    EXPECT_EQ(book.getCount(), 3);
    EXPECT_FALSE(book.getISBN().empty());
}

// Тест метода addAuthor
TEST_F(BookTest, AddAuthor) {
    book1.addAuthor("New Author");
    EXPECT_EQ(book1.getAuthors().size(), 2);
    EXPECT_TRUE(book1.getAuthors().count("New Author") > 0);
}

// Тест метода deleteAuthor
TEST_F(BookTest, DeleteAuthor) {
    book1.deleteAuthor("Bjarne Stroustrup");
    EXPECT_EQ(book1.getAuthors().size(), 0);
}

// Тест оператора присваивания
TEST_F(BookTest, AssignmentOperator) {
    Book book;
    book = book2;
    EXPECT_EQ(book.getTitle(), "Effective Modern C++");
    EXPECT_EQ(book.getAuthors().size(), 1);
    EXPECT_EQ(book.getPrice(), 150);
    EXPECT_EQ(book.getCount(), 5);
    EXPECT_FALSE(book.getISBN().empty());
    EXPECT_EQ(book.getISBN(), book2.getISBN()); // ISBN должен быть уникальным
}

// Тест оператора сравнения
TEST_F(BookTest, EqualityOperator) {
    Book bookCopy = book1;
    EXPECT_EQ(book1, bookCopy); }

// Тест оператора меньше
TEST_F(BookTest, LessThanOperator) {
    EXPECT_FALSE(book1 < book1); // Один и тот же объект не меньше самого себя
    EXPECT_TRUE(book1 < book2 || book2 < book1); // Порядок должен быть определен для разных ISBN
}

// Тест оператора вывода в поток
TEST_F(BookTest, StreamOutputOperator) {
    std::stringstream ss;
    ss << book1;
    std::string output = ss.str();
    EXPECT_NE(output.find("ISBN:"), std::string::npos);
    EXPECT_NE(output.find("Title: The C++ Programming Language"), std::string::npos);
    EXPECT_NE(output.find("Authors:"), std::string::npos);
    EXPECT_NE(output.find("Price: 100"), std::string::npos);
    EXPECT_NE(output.find("Count: 10"), std::string::npos);
}

// Тест оператора ввода с потока
TEST_F(BookTest, StreamInputOperator) {
    std::stringstream ss("Some Book;Author1, Author2;50;3");
    Book book;
    ss >> book;
    EXPECT_EQ(book.getTitle(), "Some Book");
    EXPECT_EQ(book.getAuthors().size(), 2);
    EXPECT_EQ(book.getPrice(), 50);
    EXPECT_EQ(book.getCount(), 3);
    EXPECT_FALSE(book.getISBN().empty());
}


// Тест конструктора по умолчанию
TEST_F(LibraryTest, DefaultConstructor) {
    Library lib;
    EXPECT_TRUE(lib.find(book1.getISBN()) == nullptr);
}

// Тест метода insert
TEST_F(LibraryTest, InsertBook) {
    Book newBook("Clean Code", {"Robert C. Martin"}, 120, 3);
    library.insert(newBook);
    auto foundBook = library.find(newBook.getISBN());
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getTitle(), "Clean Code");
    EXPECT_EQ(foundBook->getAuthors().size(), 1);
    EXPECT_EQ(foundBook->getPrice(), 120);
    EXPECT_EQ(foundBook->getCount(), 3);
}

// Тест метода erase
TEST_F(LibraryTest, EraseBook) {
    library.ereas(book1.getISBN());
    EXPECT_TRUE(library.find(book1.getISBN()) == nullptr);
}

// Тест метода eraseAuthor
TEST_F(LibraryTest, EraseAuthor) {
    library.eraseAuthor(book3.getISBN(), "Erich Gamma");
    auto foundBook = library.find(book3.getISBN());
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getAuthors().size(), 3);
    EXPECT_TRUE(foundBook->getAuthors().count("Erich Gamma") == 0);
}

// Тест метода addAuthor
TEST_F(LibraryTest, AddAuthor) {
    library.addAuthor(book2.getISBN(), "New Author");
    auto foundBook = library.find(book2.getISBN());
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getAuthors().size(), 2);
    EXPECT_TRUE(foundBook->getAuthors().count("New Author") > 0);
}

// Тест метода find
TEST_F(LibraryTest, FindBook) {
    auto foundBook = library.find(book1.getISBN());
    ASSERT_NE(foundBook, nullptr);
    EXPECT_EQ(foundBook->getTitle(), "The C++ Programming Language");
}

// Тест метода sortAboutTitle
TEST_F(LibraryTest, SortAboutTitle) {
    auto sortedBooks = library.sortAboutTitle();
    EXPECT_EQ(sortedBooks.size(), 3);
    auto it = sortedBooks.begin();
    EXPECT_EQ(it->second.getTitle(), "Design Patterns: Elements of Reusable Object-Oriented Software");
}

// Тест оператора вывода в поток
TEST_F(LibraryTest, StreamOutputOperator) {
    std::stringstream ss;
    ss << library;
    std::string output = ss.str();
    EXPECT_NE(output.find("The C++ Programming Language"), std::string::npos);
    EXPECT_NE(output.find("Effective Modern C++"), std::string::npos);
    EXPECT_NE(output.find("Design Patterns: Elements of Reusable Object-Oriented Software"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
