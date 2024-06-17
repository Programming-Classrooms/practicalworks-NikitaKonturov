
#include <stdexcept>
#include <gtest/gtest.h>
#include "../Library/Library.hpp"


class BookTest : public ::testing::Test {
protected:
    void SetUp() override {
        author1 = Author("John", "Doe", "Smith");
        author2 = Author("Jane", "Smith", "Doe");
        authorsList = AuthorsList();
        authorsList.insert(author1);
        authorsList.insert(author2);
    }

    void TearDown() override {}

    Book book;
    AuthorsList authorsList;
    Author author1;
    Author author2;
};

class AuthorsListTest : public ::testing::Test {
protected:
    void SetUp() override {
        author1 = Author("John", "Doe", "Smith");
        author2 = Author("Jane", "Smith", "Doe");
        author3 = Author("Alice", "Johnson", "Brown");
    }

    void TearDown() override {}

    AuthorsList list;
    Author author1;
    Author author2;
    Author author3;
};

class AuthorTest : public ::testing::Test {
protected:
    void SetUp() override {
        author1 = Author("John", "Doe", "Smith");
        author2 = Author("Jane", "Smith", "Doe");
        author3 = Author("John", "Doe", "Smith");
    }

    void TearDown() override {}

    Author author1;
    Author author2;
    Author author3;
};

TEST_F(AuthorTest, Getters) {
    EXPECT_EQ(author1.getName(), "John");
    EXPECT_EQ(author1.getSurenaem(), "Doe");
    EXPECT_EQ(author1.getFathername(), "Smith");
}

TEST_F(AuthorTest, OutputOperator) {
    std::ostringstream oss;
    oss << author1;
    EXPECT_EQ(oss.str(), "John Doe Smith");
}

TEST_F(AuthorTest, InputOperator) {
    std::istringstream iss("Alex Johnson");
    iss >> author1;
    EXPECT_EQ(author1.getName(), "Alex");
    EXPECT_EQ(author1.getSurenaem(), "Johnson");
    EXPECT_EQ(author1.getFathername(), "");
}

TEST_F(AuthorTest, AssignmentOperator) {
    author1 = author2;
    EXPECT_EQ(author1, author2);
}

TEST_F(AuthorTest, EqualityOperator) {
    EXPECT_EQ(author1 == author2, false);
    EXPECT_EQ(author1 == author3, true);
}

TEST_F(AuthorTest, LessThanOperator) {
    EXPECT_EQ(author1 < author2, false);
    EXPECT_EQ(author2 < author1, true);
}

TEST_F(AuthorTest, GreaterThanOperator) {
    EXPECT_EQ(author1 > author2, true);
    EXPECT_EQ(author2 > author1, false);
}


TEST_F(AuthorsListTest, Insertion) {
    list.insert(author1);
    list.insert(author2);
    list.insert(author3);

    EXPECT_EQ(list.size(), 3);
}

TEST_F(AuthorsListTest, Emplacement) {
    list.emplace("John", "Doe", "Smith");
    list.emplace("Jane", "Smith", "Doe");
    list.emplace("Alice", "Johnson", "Brown");

    EXPECT_EQ(list.size(), 3);
}

TEST_F(AuthorsListTest, Erase) {
    list.insert(author1);
    list.insert(author2);
    list.insert(author3);

    list.erase("John", "Doe", "Smith");
    EXPECT_EQ(list.size(), 2);

    list.erase("Jane", "Smith", "Doe");
    EXPECT_EQ(list.size(), 1);

    list.erase("Alice", "Johnson", "Brown");
    EXPECT_EQ(list.size(), 0);
}

TEST_F(AuthorsListTest, Find) {
    list.insert(author1);
    list.insert(author2);
    list.insert(author3);

    EXPECT_TRUE(list.find(author1));
    EXPECT_TRUE(list.find(author2));
    EXPECT_TRUE(list.find(author3));

    Author nonExistentAuthor("Bob", "Johnson", "Smith");
    EXPECT_FALSE(list.find(nonExistentAuthor));
}

TEST_F(AuthorsListTest, EqualityOperator) {
    AuthorsList list2;

    list.insert(author1);
    list.insert(author2);
    list.insert(author3);

    list2.insert(author1);
    list2.insert(author2);
    list2.insert(author3);

    EXPECT_TRUE(list == list2);

    list2.erase("Jane", "Smith", "Doe");

    EXPECT_FALSE(list == list2);
}

TEST_F(AuthorsListTest, AssignmentOperator) {
    AuthorsList list2;

    list.insert(author1);
    list.insert(author2);
    list.insert(author3);

    list2 = list;

    EXPECT_EQ(list, list2);
}

TEST_F(BookTest, DefaultConstructor) {
    EXPECT_EQ(book.getDDC(), 0);
    EXPECT_EQ(book.getAuthors().size(), 0);
    EXPECT_EQ(book.getTitle(), "");
    EXPECT_EQ(book.getYear(), 0);
}

TEST_F(BookTest, ParametrizedConstructor) {
    Book bookWithParams(100, authorsList, "Sample Book", 2022);

    EXPECT_EQ(bookWithParams.getDDC(), 100);
    EXPECT_EQ(bookWithParams.getAuthors().size(), 2);
    EXPECT_EQ(bookWithParams.getTitle(), "Sample Book");
    EXPECT_EQ(bookWithParams.getYear(), 2022);
}

TEST_F(BookTest, AddAndDeleteAuthor) {
    book.addAuthor("John", "Doe", "Smith");
    EXPECT_EQ(book.getAuthors().size(), 1);

    book.deleteAuthor("John", "Doe", "Smith");
    EXPECT_EQ(book.getAuthors().size(), 0);
}

TEST_F(BookTest, AssignmentOperator) {
    Book bookWithParams(100, authorsList, "Sample Book", 2022);
    book = bookWithParams;

    EXPECT_EQ(book, bookWithParams);
}

TEST_F(BookTest, EqualityOperator) {
    Book book1(100, authorsList, "Sample Book", 2022);
    Book book2(100, authorsList, "Sample Book", 2022);

    EXPECT_EQ(book1, book2);

    Book book3(200, authorsList, "Another Book", 2022);

    EXPECT_NE(book1, book3);
}

TEST_F(BookTest, LessThanOperator) {
    Book book1(100, authorsList, "Sample Book", 2021);
    Book book2(100, authorsList, "Sample Book", 2022);

    EXPECT_FALSE(book2 < book1);

    Book book3(200, authorsList, "Another Book", 2022);

    EXPECT_TRUE(book3 < book1);
}

TEST_F(BookTest, OutputOperator) {
    std::ostringstream oss;
    oss << book;

    std::string expectedOutput = "УДК: 0\nСписок авторов: \nНазвание: \nГод: 0\n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST_F(BookTest, InputOperator) {
    std::istringstream iss("100;John Doe Smith, Jane Smith Doe;Sample Book;2022");
    iss >> book;

    EXPECT_EQ(book.getDDC(), 100);
    EXPECT_EQ(book.getAuthors().size(), 2);
    EXPECT_EQ(book.getTitle(), "Sample Book");
    EXPECT_EQ(book.getYear(), 2022);
}

TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
