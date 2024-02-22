#include "../funcs/myString.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(testCaseConstructors, testDefultConstructor) {
  myString str;
  EXPECT_EQ(str.getSize(), 0);
}

TEST(testCaseConstructors, testSizeConstructor) {
  myString str(5);
  EXPECT_EQ(5, str.getSize());
  EXPECT_THROW(myString errStr(-5), std::invalid_argument);
}

TEST(testCaseConstructors, testCopyConstructor) {
  myString str1 = "Hello";
  myString str2(str1);
  EXPECT_EQ(str1.getSize(), str2.getSize());
  for (size_t i = 0; i < str1.getSize(); ++i) {
    EXPECT_EQ(str1[i], str2[i]);
  }
}

TEST(testCasePushBack, testPushBack) {
  myString str = "Hello";
  str.push_back('!');
  EXPECT_EQ(str[str.getSize() - 1], '!');
}

TEST(testCaseAppend, testAppendChar) {
  myString str = "Hello";
  str.append(" world");
  char checkStr[] = "Hello world";
  for (size_t i = 0; i < str.getSize(); ++i) {
    EXPECT_EQ(str[i], checkStr[i]);
  }
}

TEST(testCaseApped, testAppendMyStirng) {
  myString str1 = "Hello";
  myString str2 = " world";
  char checkStr[] = "Hello world";
  str1.append(str2);
  for (size_t i = 0; i < str1.getSize(); ++i) {
    EXPECT_EQ(str1[i], checkStr[i]);
  }
}

TEST(testCaseInsert, testInsertMyString) {
  myString str1 = "Heo";
  myString str2 = "ll";
  str1.insert(str2, 2);
  char checkStr[] = "Hello";
  for (size_t i = 0; i < str1.getSize(); ++i) {
    EXPECT_EQ(str1[i], checkStr[i]);
  }
}

TEST(testCaseInsert, testInsertChar) {
  myString str1 = "Heo";
  str1.insert("ll", 2);
  char checkStr[] = "Hello";
  for (size_t i = 0; i < str1.getSize(); ++i) {
    EXPECT_EQ(str1[i], checkStr[i]);
  }
}

TEST(testCaseSubStr, goodTestSubStr) {
  myString str1 = "Hello";
  myString str2 = str1.substr(2, 2);
  char checkStr[] = "ll";
  for (size_t i = 0; i < str2.getSize(); ++i) {
    EXPECT_EQ(str2[i], checkStr[i]);
  }
}

TEST(testCaseSubStr, badTestSubStr) {
  myString str1 = "dsfaef";
  EXPECT_THROW(str1.substr(-5, 4), std::out_of_range);
}

TEST(testCaseOperators, testEqOperator) {
  myString str;
  str = "g";
  EXPECT_EQ(str[0], 'g');
}

TEST(testCaseOperators, testPlusOperator) {
  myString str1 = "Hel";
  myString str2 = "lo";
  myString str3 = str1 + str2;
  char testStr[] = "Hello";
  for (size_t i = 0; i < str3.getSize(); ++i) {
    EXPECT_EQ(testStr[i], str3[i]);
  }
}

TEST(testCaseOperators, testcomparisonOperator) {
  myString str1 = "Hello";
  myString str2 = "Hello";
  EXPECT_TRUE(str1 == str2);
  str2 = "word";
  EXPECT_FALSE(str1 == str2);
}

TEST(testCaseEmpty, testEmty) {
  myString str = "dfdfdssdfsd";
  EXPECT_FALSE(str.empty());
}

TEST(testCaseClear, goodTestClear) {
  myString str = "zfdsfsdf";
  EXPECT_NO_THROW(str.clear());
}

TEST(testCaseClear, badTestClear) {
  myString str;
  EXPECT_NO_THROW(str.clear());
}

TEST(testCaseReplace, testReplace) {
  myString str1 = "Hello   ";
  myString str2 = "world!";
  str1.replace(str2, 6, 2);
  char checkStr[] = "Hello world!";
  for (size_t i = 0; i < str1.getSize(); ++i) {
    EXPECT_EQ(str1[i], checkStr[i]);
  }
}

TEST(testCaseC_str, testC_str) {
  myString str = "Hello";
  char *charStr = str.c_str();
  for (size_t i = 0; i < str.getSize(); ++i) {
    EXPECT_EQ(charStr[i], str[i]);
  }
  delete[] charStr;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
