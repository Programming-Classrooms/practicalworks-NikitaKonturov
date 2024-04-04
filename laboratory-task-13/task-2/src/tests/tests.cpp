
#include <stdexcept>
#include <sstream>
#include <gtest/gtest.h>
#include "src/funcs/funcs.hpp"
#include "src/class/StudentAfterSecondSesion/StudentAfterSecondSesion.hpp"


TEST(StudentConstructorTest, ConstructorWithParameters) {
    std::string name = "John Doe";
    size_t recordNumber = 12345;
    size_t course = 3;
    size_t group = 101;

    Student student(name, recordNumber, course, group);

    EXPECT_EQ(student.getName(), name);
    EXPECT_EQ(student.getRecordNumber(), recordNumber);
    EXPECT_EQ(student.getCource(), course);
    EXPECT_EQ(student.getGroup(), group);
    EXPECT_EQ(student.getID(), 1);
}

TEST(StudentSettersGettersTest, SettersGetters) {
    Student student("No name" , 45 , 4, 1);
    std::string name = "Alice Smith";
    size_t recordNumber = 54321;
    size_t course = 2;
    size_t group = 102;

    student.setName(name);
    student.setGroup(group);
    student.setCource(course);

    EXPECT_EQ(student.getName(), name);
    EXPECT_EQ(student.getRecordNumber(), 45); 
    EXPECT_EQ(student.getCource(), course);
    EXPECT_EQ(student.getGroup(), group);
    EXPECT_EQ(student.getID(), 2); 

    EXPECT_THROW(student.setGroup(-1), std::invalid_argument);
    EXPECT_THROW(student.setCource(7), std::invalid_argument);
}

TEST(StudentOutputOperatorTest, OutputOperator) {
    std::string expectedOutput = "ID: 3\nRecord number: 45\nName: No name\nGroup: 1\nCource: 4\n";
    Student student("No name" , 45 , 4, 1);
    std::stringstream streamForCheck;
    std::cout.clear();
    std::streambuf* oldStream = std::cout.rdbuf(streamForCheck.rdbuf());

    std::cout << student;

    std::cout.rdbuf(oldStream);

    std::cout.clear();

    EXPECT_EQ(streamForCheck.str(), expectedOutput);
}

TEST(StudentAfterFirstSesionTest, ConstructorValidArguments) {
    size_t marks[4] = {5, 6, 7, 8};
    StudentAfterFirstSesion student("Alice Smith", 12345, 2, 102, marks, 4);

    EXPECT_EQ(student.getName(), "Alice Smith");
    EXPECT_EQ(student.getRecordNumber(), 12345);
    EXPECT_EQ(student.getCource(), 2);
    EXPECT_EQ(student.getGroup(), 102);

    for (size_t i = 0; i < 4; ++i) {
        EXPECT_EQ(student.getMarkToFirstSesion(i), marks[i]);
    }
}

TEST(StudentAfterFirstSesionTest, ConstructorInvalidMarks) {
    size_t invalidMarks[4] = {5, 6, 11, 8};
    EXPECT_THROW(StudentAfterFirstSesion("Bob", 12345, 2, 102, invalidMarks, 4), std::invalid_argument);
}

TEST(StudentAfterFirstSesionTest, SetterGetterMarks) {
    size_t marks[4] = {5, 6, 7, 8};
    StudentAfterFirstSesion student("Alice Smith", 12345, 2, 102, marks, 4);

    student.setMarkToFirstSesion(1, 9);

    EXPECT_EQ(student.getMarkToFirstSesion(1), 9);
}

TEST(StudentAfterFirstSesionTest, MiddleMark) {
    size_t marks[4] = {5, 6, 7, 8};
    StudentAfterFirstSesion student("Alice Smith", 12345, 2, 102, marks, 4);

    EXPECT_DOUBLE_EQ(student.middleMark(), 6.5);
}


TEST(StudentAfterSecondSesionTest, ConstructorAndGetters) {
    size_t firstSessionMarks[] = {5, 6, 7, 8};
    size_t secondSessionMarks[] = {6, 7, 8, 9, 10};
    StudentAfterSecondSesion student("John Doe", 12345, 3, 2, firstSessionMarks, 4, secondSessionMarks, 5);

    EXPECT_EQ(student.getName(), "John Doe");
    EXPECT_EQ(student.getRecordNumber(), 12345);
    EXPECT_EQ(student.getCource(), 3);
    EXPECT_EQ(student.getGroup(), 2);
    
    size_t* retrievedFirstSessionMarks = student.getMarksOnFirstSesion();
    for (size_t i = 0; i < 4; ++i) {
        EXPECT_EQ(retrievedFirstSessionMarks[i], firstSessionMarks[i]);
    }

    size_t* retrievedSecondSessionMarks = student.getMarksToSecondSesion();
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(retrievedSecondSessionMarks[i], secondSessionMarks[i]);
    }
}

TEST(StudentAfterSecondSesionTest, Setters) {
    size_t firstSessionMarks[] = {5, 6, 7, 8};
    size_t secondSessionMarks[] = {6, 7, 8, 9, 10};
    StudentAfterSecondSesion student("John Doe", 12345, 3, 2, firstSessionMarks, 4, secondSessionMarks, 5);

    student.setName("Jane Doe");
    EXPECT_EQ(student.getName(), "Jane Doe");

    student.setGroup(3);
    EXPECT_EQ(student.getGroup(), 3);

    student.setCource(4);
    EXPECT_EQ(student.getCource(), 4);

    student.setMarkToSecondSesion(0, 8);
    EXPECT_EQ(student.getMarkToSecondSesion(0), 8);
}

TEST(StudentAfterSecondSesionTest, MiddleMark) {
    size_t firstSessionMarks[] = {5, 6, 7, 8};
    size_t secondSessionMarks[] = {6, 7, 8, 9, 10};
    StudentAfterSecondSesion student("John Doe", 12345, 3, 2, firstSessionMarks, 4, secondSessionMarks, 5);

    double expectedMiddleMark = (5 + 6 + 7 + 8 + 6 + 7 + 8 + 9 + 10) / 9.0;
    EXPECT_EQ(student.middleMark(), expectedMiddleMark);
}

TEST(FuncsTest, MidlleMarkOfGroupOnFirstSession) {
    Student* emptyArr[0];
    EXPECT_EQ(midlleMarkOfGroupOnFirstSession(emptyArr, 0, 1), 0.0);

    size_t marks[] = {5, 6, 7, 8};
    StudentAfterFirstSesion student("John Doe", 12345, 3, 1, marks, 4);
    Student* oneStudentArr[] = {&student};
    EXPECT_DOUBLE_EQ(midlleMarkOfGroupOnFirstSession(oneStudentArr, 1, 1), student.middleMark());

    size_t marks1[] = {5, 6, 7, 8};
    size_t marks2[] = {6, 7, 8, 9};
    StudentAfterFirstSesion student1("John Doe", 12345, 3, 1, marks1, 4);
    StudentAfterFirstSesion student2("Jane Smith", 12346, 3, 1, marks2, 4);
    Student* multipleStudentsArr[] = {&student1, &student2};
    double expectedAverage = (student1.middleMark() + student2.middleMark()) / 2.0;
    EXPECT_DOUBLE_EQ(midlleMarkOfGroupOnFirstSession(multipleStudentsArr, 2, 1), expectedAverage);
}

TEST(FuncsTest, MidlleMarkOfGroupOnSecondSession) {

    Student* emptyArr[0];
    EXPECT_EQ(midlleMarkOfGroupOnSecondSession(emptyArr, 0, 1), 0.0);

    size_t marks1[] = {5, 6, 7, 8};
    size_t marks2[] = {6, 7, 8, 9, 10};
    StudentAfterSecondSesion student("John Doe", 12345, 3, 1, marks1, 4, marks2, 5);
    Student* oneStudentArr[] = {&student};
    EXPECT_DOUBLE_EQ(midlleMarkOfGroupOnSecondSession(oneStudentArr, 1, 1), student.middleMark());

    StudentAfterSecondSesion student1("John Doe", 12345, 3, 1, marks1, 4, marks2, 5);
    StudentAfterSecondSesion student2("Jane Smith", 12346, 3, 1, marks1, 4, marks2, 5);
    Student* multipleStudentsArr[] = {&student1, &student2};
    double expectedAverage = (student1.middleMark() + student2.middleMark()) / 2.0;
    EXPECT_DOUBLE_EQ(midlleMarkOfGroupOnSecondSession(multipleStudentsArr, 2, 1), expectedAverage);
}

TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
