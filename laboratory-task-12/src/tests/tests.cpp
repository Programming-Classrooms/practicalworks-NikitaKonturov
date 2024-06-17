
#include <stdexcept>
#include <gtest/gtest.h>
#include "../class/fraction.hpp"
#include "../class/matrix.hpp"
#include "../class/list.hpp"


/*==================================================*/
/*==============Тесты класса Fraction===============*/
/*==================================================*/


TEST(testFraction, testDefultConstructor)
{
    Fraction obj1;
    EXPECT_EQ(obj1.getNumerator(), 0);
    EXPECT_EQ(obj1.getDenumerator(), 1);
    Fraction obj2(-5, 4);
    EXPECT_EQ(obj2.getNumerator(), -5);
    EXPECT_EQ(obj2.getDenumerator(), 4);
    Fraction obj3(5, -4);
    EXPECT_EQ(obj3.getNumerator(), -5);
    EXPECT_EQ(obj3.getDenumerator(), 4);
    EXPECT_THROW(Fraction obj4(5, 0), std::invalid_argument);
}

TEST(testFraction, testCopyConstructor)
{
    Fraction obj1;
    Fraction obj2(obj1);
    EXPECT_EQ(obj2.getNumerator(), 0);
    EXPECT_EQ(obj2.getDenumerator(), 1);
}

TEST(testFraction, testGetNumerator)
{
    Fraction obj1;
    EXPECT_EQ(obj1.getNumerator(), 0);
    Fraction obj2(-5, 4);
    EXPECT_EQ(obj2.getNumerator(), -5);
    Fraction obj3(5, -4);
    EXPECT_EQ(obj3.getNumerator(), -5);
}

TEST(testFraction, testGetDenumerator)
{
    Fraction obj1;
    EXPECT_EQ(obj1.getDenumerator(), 1);
    Fraction obj2(-5, 4);
    EXPECT_EQ(obj2.getDenumerator(), 4);
    Fraction obj3(5, -4);
    EXPECT_EQ(obj3.getDenumerator(), 4);
}

TEST(testFraction, testSetNumerator)
{
    Fraction obj;
    obj.setNumerator(5);
    EXPECT_EQ(obj.getNumerator(), 5);
    obj.setNumerator(-5);
    EXPECT_EQ(obj.getNumerator(), -5);
    obj.setNumerator(0);
    EXPECT_EQ(obj.getNumerator(), 0);
}

TEST(testFraction, testSetDenumerator)
{
    Fraction obj(1, 5);
    obj.setDenumerator(5);
    EXPECT_EQ(obj.getDenumerator(), 5);
    obj.setDenumerator(-5);
    EXPECT_EQ(obj.getDenumerator(), 5);
    EXPECT_THROW(obj.setDenumerator(0), std::invalid_argument);
}

TEST(testFraction, testReduction)
{
    Fraction obj(2, 4);
    EXPECT_EQ(obj.getNumerator(), 1);
    EXPECT_EQ(obj.getDenumerator(), 2);
    Fraction obj1(2, -8);
    EXPECT_EQ(obj1.getNumerator(), -1);
    EXPECT_EQ(obj1.getDenumerator(), 4);
}

TEST(testFraction, testPlusOperator) 
{
    Fraction obj1(4, 5);
    Fraction obj2(7, 5);
    Fraction res1 = obj1 + obj2;
    EXPECT_EQ(res1.getNumerator(), 11);
    EXPECT_EQ(res1.getDenumerator(), 5);
    Fraction obj3(8, 5);
    Fraction obj4(7, 5);
    Fraction res2 = obj3 + obj4;
    EXPECT_EQ(res2.getNumerator(), 3);
    EXPECT_EQ(res2.getDenumerator(), 1);
}

TEST(testFraction, testMinesOperator) 
{
    Fraction obj1(4, 5);
    Fraction obj2(7, 5);
    Fraction res1 = obj2 - obj1;
    EXPECT_EQ(res1.getNumerator(), 3);
    EXPECT_EQ(res1.getDenumerator(), 5);
    Fraction obj3(8, 5);
    Fraction obj4(7, 5);
    Fraction res2 = obj3 - obj4;
    EXPECT_EQ(res2.getNumerator(), 1);
    EXPECT_EQ(res2.getDenumerator(), 5);
}

TEST(testFraction, testMultiplicateOperator) 
{
    Fraction obj1(4, 5);
    Fraction obj2(7, 5);
    Fraction res1 = obj2 * obj1;
    EXPECT_EQ(res1.getNumerator(), 28);
    EXPECT_EQ(res1.getDenumerator(), 25);
    Fraction obj3(-1, 5);
    Fraction obj4(7, 5);
    Fraction res2 = obj3 * obj4;
    EXPECT_EQ(res2.getNumerator(), -7);
    EXPECT_EQ(res2.getDenumerator(), 25);
}

TEST(testFraction, testDivisorOperator) 
{
    Fraction obj1(7, 5);
    Fraction obj2(7, 5);
    Fraction res1 = obj2 / obj1;
    EXPECT_EQ(res1.getNumerator(), 1);
    EXPECT_EQ(res1.getDenumerator(), 1);
    Fraction obj3(-1, 5);
    Fraction obj4(7, 5);
    Fraction res2 = obj3 / obj4;
    EXPECT_EQ(res2.getNumerator(), -1);
    EXPECT_EQ(res2.getDenumerator(), 7);
}

TEST(testFraction, testAssignmentOperator) 
{
    Fraction obj1(7, 5);
    Fraction obj2(9, 5);
    obj2 = obj1;
    EXPECT_EQ(obj2.getNumerator(), 7);
    EXPECT_EQ(obj2.getDenumerator(), 5);
    obj2 = Fraction(8, -7);
    EXPECT_EQ(obj2.getNumerator(), -8);
    EXPECT_EQ(obj2.getDenumerator(), 7);
    obj2 = -5;
    EXPECT_EQ(obj2.getNumerator(), -5);
    EXPECT_EQ(obj2.getDenumerator(), 1);
}

TEST(testFraction, testEqualOperator)
{
    Fraction obj1(5, 6);
    Fraction obj2(5, 6);
    EXPECT_TRUE(obj1 == obj2);
    obj2 = Fraction(8, 9);    
    EXPECT_TRUE(obj1 != obj2);
}

TEST(testFraction, testLessOperator)
{
    Fraction obj1(5, 6);
    Fraction obj2(4, 6);
    EXPECT_TRUE(obj2 < obj1);
    obj2 = Fraction(-4, 6);    
    EXPECT_TRUE(obj2 < obj1);
    obj2 = Fraction(5, 6);
    EXPECT_TRUE(obj2 <= obj1);
}

TEST(testFraction, testUnlessOperator)
{
    Fraction obj1(5, 6);
    Fraction obj2(4, 6);
    EXPECT_TRUE(obj1 > obj2);
    obj2 = Fraction(-4, 6);    
    EXPECT_TRUE(obj1 > obj2);
    obj2 = Fraction(5, 6);
    EXPECT_TRUE(obj1 >= obj2);
}

TEST(testFraction, testUnaryMinesOperator)
{
    Fraction obj1(8, 9);
    Fraction obj2 = -obj1;
    EXPECT_EQ(obj2.getNumerator(), -8);
    EXPECT_EQ(obj2.getDenumerator(), 9);
    obj2 = -obj2;
    EXPECT_EQ(obj2.getNumerator(), 8);
    EXPECT_EQ(obj2.getDenumerator(), 9);
}

TEST(testFraction, testDoublePlussOperator)
{
    Fraction obj1(8, 9);
    obj1++;
    EXPECT_EQ(obj1.getNumerator(), 17);
    EXPECT_EQ(obj1.getDenumerator(), 9);
    ++obj1;
    EXPECT_EQ(obj1.getNumerator(), 26);
    EXPECT_EQ(obj1.getDenumerator(), 9);
}

TEST(testFraction, testDoubleMinesOperator)
{
    Fraction obj1(8, 9);
    obj1--;
    EXPECT_EQ(obj1.getNumerator(), -1);
    EXPECT_EQ(obj1.getDenumerator(), 9);
    --obj1;
    EXPECT_EQ(obj1.getNumerator(), -10);
    EXPECT_EQ(obj1.getDenumerator(), 9);
}

TEST(testFraction, testBackFractionOperator)
{
    Fraction obj1(8, 9);
    Fraction obj2 = !obj1;
    EXPECT_EQ(obj2.getNumerator(), 9);
    EXPECT_EQ(obj2.getDenumerator(), 8);
    Fraction obj3(-8, 9);
    Fraction obj4 = !obj3;
    EXPECT_EQ(obj4.getNumerator(), -9);
    EXPECT_EQ(obj4.getDenumerator(), 8);
}

TEST(testFraction, testDoubleCastOperator)
{
    double res = static_cast<double>(Fraction(1, 2));
    EXPECT_DOUBLE_EQ(res, 0.5);
    res = static_cast<double>(Fraction(-1, 2));
    EXPECT_DOUBLE_EQ(res, -0.5);
}


/*==================================================*/
/*===============Тесты класса Matrix================*/
/*==================================================*/


TEST(testMatrix, testDefaltConstructor)
{
    Matrix mtrx1;
    EXPECT_EQ(mtrx1.getRows(), 1);
    EXPECT_EQ(mtrx1.getColumns(), 1);
    Matrix mtrx2(3, 2);
    EXPECT_EQ(mtrx2.getRows(), 3);
    EXPECT_EQ(mtrx2.getColumns(), 2);
    EXPECT_THROW(Matrix(0, 0), std::invalid_argument);
}

TEST(testMatrix, testCopyConstructor)
{
    Matrix mtrx1(4, 5);
    EXPECT_NO_THROW(Matrix (mtrx1));
    Matrix mtrx2(mtrx1);
    EXPECT_EQ(mtrx2.getRows(), 4);
    EXPECT_EQ(mtrx2.getColumns(), 5);
}

TEST(testMatrix, testIterator)
{
    Matrix mtrx(3, 3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_NO_THROW(mtrx[i][j] = 3);   
        }
    }
    
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mtrx[i][j], 3);   
        }
    }

    EXPECT_THROW(mtrx[1][3], std::out_of_range);
    EXPECT_THROW(mtrx[3][1], std::out_of_range);
}

TEST(testMatrix, testAsigmentation)
{
    Matrix mtrx(3, 3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            mtrx[i][j] = 3;   
        }
    }

    Matrix mtrx1;

    mtrx1 = mtrx;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mtrx1[i][j], 3);   
        }
    }

    mtrx1 = 5;

    for (size_t i = 0; i < 3; ++i) {
        EXPECT_EQ(mtrx1[i][i], 5);
    }
}

TEST(testMatrix, testMultiplicatWithConstant)
{
    Matrix mtrx(3, 3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            mtrx[i][j] = 3;   
        }
    }

    mtrx = mtrx * 3;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mtrx[i][j], 9);   
        }
    }

    mtrx = 2 * mtrx;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mtrx[i][j], 18);   
        }
    }
}

TEST(testMatrix, testDivisionOnConstant)
{
    Matrix mtrx(3, 3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            mtrx[i][j] = 9;   
        }
    }

    mtrx = mtrx / 3;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mtrx[i][j], 3);   
        }
    }

    EXPECT_THROW(mtrx / 0, std::invalid_argument);
}

TEST(testMatrix, testAdditionMatrix)
{
    Matrix mtrx1(3, 2);
    Matrix mtrx2(3, 2);

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            mtrx1[i][j] = 2;
            mtrx2[i][j] = 1;   
        }
    }

    mtrx1 = mtrx1 + mtrx2;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            EXPECT_EQ(mtrx1[i][j], 3);   
        }
    }
}

TEST(testMatrix, testDifferenceMatrix)
{
    Matrix mtrx1(3, 2);
    Matrix mtrx2(3, 2);

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            mtrx1[i][j] = 2;
            mtrx2[i][j] = 1;   
        }
    }

    mtrx1 = mtrx1 - mtrx2;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            EXPECT_EQ(mtrx1[i][j], 1);   
        }
    }
}

TEST(testMatrix, testMultiplicationMatrix)
{
    Matrix mtrx1(3, 3);
    Matrix mtrx2(3, 3);
    Matrix mtrx3(3, 3);

    mtrx1[0][0] = 1;
    mtrx1[0][1] = 5;
    mtrx1[0][2] = -8;
    mtrx1[1][0] = 7;
    mtrx1[1][1] = 2;
    mtrx1[1][2] = 5;
    mtrx1[2][0] = 5;
    mtrx1[2][1] = -5;
    mtrx1[2][2] = -3;
    
    mtrx2[0][0] = 4;
    mtrx2[0][1] = 5;
    mtrx2[0][2] = 1;
    mtrx2[1][0] = -9;
    mtrx2[1][1] = 4;
    mtrx2[1][2] = 8;
    mtrx2[2][0] = 7;
    mtrx2[2][1] = 4;
    mtrx2[2][2] = -5;

    mtrx3[0][0] = -97;
    mtrx3[0][1] = -7;
    mtrx3[0][2] = 81;
    mtrx3[1][0] = 45;
    mtrx3[1][1] = 63;
    mtrx3[1][2] = -2;
    mtrx3[2][0] = 44;
    mtrx3[2][1] = -7;
    mtrx3[2][2] = -20;

    Matrix res = mtrx1 * mtrx2;

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            EXPECT_EQ(res[i][j], mtrx3[i][j]);   
        }
    }
}

TEST(testMatrix, testComprasion)
{
    Matrix mtrx1(3, 3);
    Matrix mtrx2(3, 3);

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            mtrx1[i][j] = 2;
            mtrx2[i][j] = 2;   
        }
    }

    EXPECT_TRUE(mtrx1 == mtrx2);

    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            mtrx1[i][j] = 8;   
        }
    }

    EXPECT_TRUE(mtrx1 != mtrx2);
}


/*==================================================*/
/*================Тесты класса List=================*/
/*==================================================*/


TEST(testList, testDefaltConstructor)
{
    List<int> list;
    EXPECT_EQ(list.getSize(), 0);
}

TEST(testList, testCopyConstructor)
{
    List<int> list1;
    List<int> list2(list1);
    EXPECT_EQ(list1.getSize(), list2.getSize());
}

TEST(testList, testPushBack)
{
    List<int> list;
    list.pushBack(5);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list[0], 5);
}

TEST(testList, testPushFront)
{
    List<int> list;
    list.pushFront(5);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list[0], 5);
}

TEST(testList, testDeleteItemOnIndex)
{
    List<int> list;
    for (size_t i = 0; i < 5; ++i) {
        list.pushBack(4);
    }
    list.deleteItem(1);
    EXPECT_EQ(list.getSize(), 4);
}

TEST(testList, testDeleteItemOnValue)
{
    List<int> list;
    for (size_t i = 0; i < 5; ++i) {
        list.pushBack(i+1);
    }
    size_t count = 0;
    list.deleteItem(1, count);
    EXPECT_EQ(list[0], 2);
    EXPECT_THROW(list.deleteItem(9,count), std::out_of_range);

}

TEST(testList, testFind)
{
    List<int> list;
    for (size_t i = 0; i < 5; ++i) {
        list.pushBack(i+1);
    }
    size_t count = 0;
    EXPECT_EQ(list.find(1, count), 0);
    EXPECT_EQ(list.find(9, count), -1);
    list.clear();
    EXPECT_THROW(list.find(9, count), std::logic_error);
}

TEST(testList, testInsert)
{
    List<int> list;
    for (size_t i = 0; i < 5; ++i) {
        list.pushBack(i+1);
    }
    list.insert(2, 45);
    EXPECT_EQ(list[2], 45);
    list.insert(0, 78);
    EXPECT_EQ(list[0], 78);
    EXPECT_THROW(list.insert(list.getSize(), -5), std::out_of_range );
}

TEST(testList, testMerge)
{
    List<int> list1;
    List<int> list2;
    for (size_t i = 0; i < 5; ++i) {
        list1.pushBack(i+1);
        list2.pushBack(9);
    }

    list1.merge(list2, 1);
    EXPECT_EQ(list1[2], 9);
    EXPECT_EQ(list1.getSize(), 10);
}

TEST(testList, testRevers)
{
    List<int> list1;
    for (size_t i = 0; i < 5; ++i) {
        list1.pushBack(i+1);
    }

    list1.revers();
    
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(list1[i], 5 - i);
    }
}

TEST(testList, testClear)
{
    List<int> list1;
    
    EXPECT_NO_THROW(list1.clear());

    for (size_t i = 0; i < 5; ++i) {
        list1.pushBack(i+1);
    }    

    list1.clear();

    EXPECT_EQ(list1.getSize(), 0);
}

TEST(testList, testEmpty)
{
    List<int> list1;
    EXPECT_TRUE(list1.empty());

    for (size_t i = 0; i < 5; ++i) {
        list1.pushBack(i+1);
    } 

    EXPECT_FALSE(list1.empty());
}

TEST(testList, testIteratorOperator)
{
    List<int> list1;
    for (size_t i = 0; i < 5; ++i) {
        list1.pushBack(i+1);
    } 

    for (size_t i = 0; i < 5; ++i) {
        list1[i] = 9;
    }

    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(list1[i], 9);
    }

    EXPECT_THROW(list1[9], std::out_of_range);
}

TEST(testList, tesrEqualOperator)
{
    List<int> list1;
    for (size_t i = 0; i < 5; ++i) {
        list1.pushBack(i+1);
    } 

    List<int> list2;
    list2 = list1;

    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(list1[i], list2[i]);
    } 

    EXPECT_EQ(list1.getSize(), list2.getSize());
}

TEST(testList, tesrPlusOperator) 
{
    List<int> list1;
    for (size_t i = 0; i < 5; ++i) {
        list1.pushBack(i + 1);
    } 

    List<int> list2;
    for (size_t i = 0; i < 5; ++i) {
        list2.pushBack(i + 6);
    } 

    List<int> list3 = list1 + list2;

    for (size_t i = 0; i < list3.getSize(); ++i) {
        EXPECT_EQ(list3[i], (i + 1));
    }
}

TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
