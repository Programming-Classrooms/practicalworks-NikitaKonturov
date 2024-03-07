#include "../class/myString.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

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
    str1.clear();
}

TEST(testCasePushBack, testPushBack) 
{
    myString str = "Hello";
    str.push_back('!');
    EXPECT_EQ(str[str.getSize() - 1], '!');
    EXPECT_NO_THROW(str.push_back(5));
    EXPECT_THROW(str.push_back(-5), std::out_of_range);
}

TEST(testCaseAppend, testAppendChar) 
{
    myString str = "Hello";
    str.append(" world");
    char checkStr[] = "Hello world";
    for (size_t i = 0; i < str.getSize(); ++i) {
        EXPECT_EQ(str[i], checkStr[i]);
    }
    EXPECT_NO_THROW(str.append(""));
}

TEST(testCaseApped, testAppendMyStirng) 
{
    myString str1 = "Hello";
    myString str2 = " world";
    char checkStr[] = "Hello world";
    str1.append(str2);
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStr[i]);
    }
    str2.clear();
    myString str3;
    EXPECT_NO_THROW(str1.append(str3));
}

TEST(testCaseInsert, testInsertMyString) 
{
    myString str1 = "Heo";
    myString str2 = "ll";
    str1.insert(str2, 2);
    char checkStr[] = "Hello";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStr[i]);
    }

    str1.insert(str2, 0);
    char checkStrFront[] = "llHello";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStrFront[i]);
    }
    
    str1.insert(str2, (str1.getSize()));
    char checkStrEnd[] = "llHelloll";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStrEnd[i]);
    }
}

TEST(testCaseInsert, testInsertChar) 
{
    myString str1 = "Heo";
    str1.insert("ll", 2);
    char checkStr[] = "Hello";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStr[i]);
    }

    str1.insert("ll", 0);
    char checkStrFront[] = "llHello";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStrFront[i]);
    }
    str1.insert("ll", (str1.getSize()));
    char checkStrEnd[] = "llHelloll";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStrEnd[i]);
    }
}

TEST(testCaseReplace, testReplaceMyString) 
{
    myString str1 = "Hello   ";
    myString str2 = "world!";
    str1.replace(str2, 6, 2);
    char checkStr[] = "Hello world!";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStr[i]);
    }
    
    myString str3 = "1";
    str1.replace(str3, (str1.getSize() - 1), 1);
    char checkStrEnd[] = "Hello world1";
    for (size_t i = 0; i < str1.getSize(); ++i) {
         EXPECT_EQ(str1[i], checkStrEnd[i]);
    }

    char checkStrFront[] = "1ello world1";
    str1.replace(str3, 0, 1);
    for (size_t i = 0; i < str1.getSize(); ++i) {
         EXPECT_EQ(str1[i], checkStrFront[i]);
    }
}

TEST(testCaseReplace, testReplaceChar) 
{
    myString str1 = "Hello   ";
    char str2[] = "world!";
    str1.replace(str2, 6, 2);
    char checkStr[] = "Hello world!";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStr[i]);
    }
    
    char str3[] = "1";
    str1.replace(str3, (str1.getSize() - 1), 1);
    char checkStrEnd[] = "Hello world1";
    for (size_t i = 0; i < str1.getSize(); ++i) {
         EXPECT_EQ(str1[i], checkStrEnd[i]);
    }

    char checkStrFront[] = "1ello world1";
    str1.replace(str3, 0, 1);
    for (size_t i = 0; i < str1.getSize(); ++i) {
         EXPECT_EQ(str1[i], checkStrFront[i]);
    }
}

TEST(testCaseClear, goodTestClear) 
{
    myString str = "zfdsfsdf";
    EXPECT_NO_THROW(str.clear());
    EXPECT_TRUE(str.empty());
}

TEST(testCaseClear, badTestClear) 
{
    myString str;
    EXPECT_NO_THROW(str.clear());
    EXPECT_TRUE(str.empty());
}

TEST(testCaseSubStr, goodTestSubStr) 
{
    myString str1 = "Hello";
    myString str2 = str1.substr(2, 2);
    char checkStr[] = "ll";
    for (size_t i = 0; i < str2.getSize(); ++i) {
        EXPECT_EQ(str2[i], checkStr[i]);
    }
    myString str3 = str1.substr(0, 1);
    EXPECT_EQ(str3[0], 'H');
}

TEST(testCaseSubStr, badTestSubStr) 
{
    myString str1 = "dsfaef";
    EXPECT_THROW(str1.substr(-5, 4), std::out_of_range);
    myString str2;
    EXPECT_ANY_THROW(str2.substr(0, 0));
}

TEST(testCaseEmpty, testEmty) 
{
  myString str1 = "dfdfdssdfsd";
  EXPECT_FALSE(str1.empty());
  str1.clear();
  EXPECT_TRUE(str1.empty());
  myString str2;
  EXPECT_TRUE(str2.empty());
}

TEST(testCaseC_str, testC_str) 
{
    myString str = "Hello";
    char *charStr = str.c_str();
    for (size_t i = 0; i < str.getSize(); ++i) {
        EXPECT_EQ(charStr[i], str[i]);
    }
    delete[] charStr;
    myString str1;
    
    EXPECT_NO_THROW(str1.c_str());
}

TEST(testCaseOperators, testEqOperator) 
{
    myString str1 = "g";
    myString str2 = "h";
    str1 = str2;
    EXPECT_EQ(str1[0], str2[0]);
}

TEST(testCaseOperators, testIterator)
{
    myString str1 = "H";
    EXPECT_EQ(str1[0], 'H');
    EXPECT_THROW(str1[4], std::out_of_range);
    str1.clear();
    EXPECT_THROW(str1[0], std::out_of_range);
}

TEST(testCaseOperators, testPluss)
{
    myString str1 = "Hello ";
    myString str2 = "world!!!";

    str1 = str1 + str2;

    char checkStr[] = "Hello world!!!";
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], checkStr[i]);   
    }
}

TEST(testCaseOperators, testPlusOperator) 
{
    myString str1 = "Hel";
    myString str2 = "lo";
    myString str3 = str1 + str2;
    char testStr[] = "Hello";
    for (size_t i = 0; i < str3.getSize(); ++i) {
        EXPECT_EQ(testStr[i], str3[i]);
    }
}

TEST(testCaseOperators, testComparisonOperator) 
{
    myString str1 = "Hello";
    myString str2 = "Hello";
    EXPECT_TRUE(str1 == str2);
    str2 = "word";
    EXPECT_FALSE(str1 == str2);
}

TEST(testCaseOperators, testUnComparisonOperator) 
{
    myString str1 = "Hello";
    myString str2 = "Hello";
    EXPECT_FALSE(str1 != str2);
    str2 = "word";
    EXPECT_TRUE(str1 != str2);
}

TEST(testCaseOperators, testLess) 
{
    myString str1 = "Hello";
    myString str2 = "Absolute";

    EXPECT_TRUE(str2 < str1);
    EXPECT_FALSE(str1 < str2);

    myString str3 = "Hello!!!";
    EXPECT_TRUE(str1 < str3);
}

TEST(testCaseOperators, testMore)
{
    myString str1 = "Hello";
    myString str2 = "Absolute";

    EXPECT_FALSE(str2 > str1);
    EXPECT_TRUE(str1 > str2);

    myString str3 = "Hello!!!";
    EXPECT_FALSE(str1 > str3);
}

TEST(testCaseOperators, testAdductionToString)
{
    myString str1 = "Hello";
    std::string testStr = static_cast<std::string>(str1); 
    for (size_t i = 0; i < str1.getSize(); ++i) {
        EXPECT_EQ(str1[i], testStr[i]);
    }

    myString str2;
    EXPECT_NO_THROW(static_cast<std::string>(str2));
}

TEST(testCaseOperators, testAdductionToInt64_t)
{
    myString str1 = "111";
    int64_t controlNumber = static_cast<int64_t>(str1);
    EXPECT_EQ(111, controlNumber);
    myString str2 = "0";
    controlNumber = static_cast<int64_t>(str2);
    EXPECT_EQ(0, controlNumber);
    myString str3 = "45sffdfdfa87";
    controlNumber = static_cast<int64_t>(str3);
    EXPECT_EQ(45, controlNumber);
    myString str4 = "sAESRAF";
    EXPECT_THROW(static_cast<int64_t>(str4), std::invalid_argument);
}

TEST(testCaseOperators, testAdductionToDouble)
{
    myString str1 = "1111.1";
    double number = static_cast<double>(str1);
    EXPECT_DOUBLE_EQ(number, 1111.1);
    myString str2 = "125";
    number = static_cast<double>(str2);
    EXPECT_DOUBLE_EQ(number, 125);
    myString str3 = "125.";
    number = static_cast<double>(str3);
    EXPECT_DOUBLE_EQ(125, number);
    myString str4 = "125s.94srerferfs";
    EXPECT_DOUBLE_EQ(125, 125);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
