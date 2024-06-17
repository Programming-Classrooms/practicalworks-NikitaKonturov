
#include "../class/Professor/Professor.hpp"
#include "../class/Student/Student.hpp"
#include "../funcs/menu.hpp"
#include <gtest/gtest.h>
#include <stdexcept>


TEST(PersonTest, DefaultConstructor) {
    Person person("John Doe");
    EXPECT_STREQ(person.getFullName(), "John Doe");
}

TEST(PersonTest, CopyConstructor) {
    Person original("Jane Smith");
    Person copy(original);
    EXPECT_STREQ(copy.getFullName(), "Jane Smith");
}

TEST(PersonTest, SetAndGetFullName) {
    Person person("Mary Johnson");
    person.setFullName("Alice Brown");
    EXPECT_STREQ(person.getFullName(), "Alice Brown");
}


TEST(PersonTest, Destructor) {
    Person* person = new Person("David Wilson");
    delete person;
    SUCCEED();
}


TEST(PersonTest, Print) {
    Person person("Robert Green");
    testing::internal::CaptureStdout();
    person.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Full name: Robert Green\n");
}

TEST(StudentTest, ConstructorWithValidParameters) {
    ASSERT_NO_THROW({
        Student student("John Doe", 3, 101);
        EXPECT_STREQ(student.getFullName(), "John Doe");
        EXPECT_EQ(student.getCource(), 3);
        EXPECT_EQ(student.getGroup(), 101);
    });
}

TEST(StudentTest, ConstructorWithInvalidCource) {
    EXPECT_THROW(Student("Alice Smith", -1, 101), std::invalid_argument);
}

TEST(StudentTest, ConstructorWithInvalidGroup) {
    EXPECT_THROW(Student("Bob Johnson", 3, -1), std::invalid_argument);
}

TEST(StudentTest, SetCource) {
    Student student("Mary Johnson", 3, 103);
    student.setCource(4);
    EXPECT_EQ(student.getCource(), 4);
}

TEST(StudentTest, SetInvalidCource) {
    Student student("Alice Brown", 3, 104);
    EXPECT_THROW(student.setCource(-1), std::invalid_argument);
    EXPECT_THROW(student.setCource(7), std::invalid_argument);
}

TEST(StudentTest, SetGroup) {
    Student student("David Wilson", 3, 105);
    student.setGroup(106);
    EXPECT_EQ(student.getGroup(), 106);
}

TEST(StudentTest, SetInvalidGroup) {
    Student student("Robert Green", 3, 107);
    EXPECT_THROW(student.setGroup(-1), std::invalid_argument);
}

TEST(StudentTest, Print) {
    Student student("Sam Taylor", 3, 108);
    testing::internal::CaptureStdout();
    student.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Full name: Sam Taylor\nCource: 3\nGroup: 108\n");
}

TEST(ProfessorTest, ConstructorWithValidParameters) {
    ASSERT_NO_THROW(Professor professor("John Doe", "Computer Science"));
    Professor professor("John Doe", "Computer Science");
    EXPECT_STREQ(professor.getFullName(), "John Doe");
    EXPECT_STREQ(professor.getDepartmen(), "Computer Science");
}

TEST(ProfessorTest, CopyConstructor) {
    Professor professor1("Jane Smith", "Mathematics");
    Professor professor2(professor1);
    EXPECT_STREQ(professor2.getFullName(), "Jane Smith");
    EXPECT_STREQ(professor2.getDepartmen(), "Mathematics");
}

TEST(ProfessorTest, SetDepartment) {
    Professor professor("Mary Johnson", "Physics");
    professor.setDepartment("Chemistry");
    EXPECT_STREQ(professor.getDepartmen(), "Chemistry");
}

TEST(ProfessorTest, Print) {
    Professor professor("Sam Taylor", "Biology");
    testing::internal::CaptureStdout();
    professor.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Full name: Sam Taylor\nDepartment: Biology\n");
}

TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
