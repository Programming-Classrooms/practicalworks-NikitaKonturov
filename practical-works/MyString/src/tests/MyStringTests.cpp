#include <stdexcept>
#include <gtest/gtest.h>
#include "../funcs/myString.hpp"


TEST(testCaseConstructors, testDefultConstructor)
{
    myString str;
    EXPECT_EQ(str.getSize(), 0);
}

TEST(testCaseConstructors, testSizeConstructor)
{
    myString str(5);
    EXPECT_EQ(5, str.getSize());
    EXPECT_THROW(myString errStr(-5), std::invalid_argument);
}

TEST(testCaseConstructors, testCopyConstructor)
{
    myString str1 = "Hello";
    myString str2(str1);
    EXPECT_EQ(str1.getSize(), str2.getSize());
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], str2[i]);
    }
}

TEST(testCasePushBack, testPushBack)
{
    myString str = "Hello";
    str.push_back('!');
    EXPECT_EQ(str[str.getSize() - 1], '!');
}

TEST(testCaseAppend, testAppendChar)
{
    myString str = "Hello";
    str.append(" world");
    char checkStr[] = "Hello world";
    for (size_t i = 0; i < str.getSize(); ++i) {
        EXPECT_EQ(str[i], checkStr[i]);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
