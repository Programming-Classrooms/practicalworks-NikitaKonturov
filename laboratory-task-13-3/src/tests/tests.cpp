
#include <stdexcept>
#include <gtest/gtest.h>
#include "../class/Forest.hpp"


TEST(TreeTest, ConstructorAndGetters) 
{
    Tree oak("Oak", TreeType::Deciduous, 50);
    EXPECT_EQ(oak.getName(), "Oak");
    EXPECT_EQ(oak.getType(), TreeType::Deciduous);
    EXPECT_EQ(oak.getAge(), 50);

    Tree pine("Pine", TreeType::Coniferous);
    EXPECT_EQ(pine.getName(), "Pine");
    EXPECT_EQ(pine.getType(), TreeType::Coniferous);
    EXPECT_EQ(pine.getAge(), 1);
}

TEST(TreeTest, PrintMethod) 
{
    Tree oak("Oak", TreeType::Deciduous, 50);
    Tree pine("Pine", TreeType::Coniferous);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    std::cout.clear();
    oak.print(std::cout);
    EXPECT_EQ(buffer.str(), "Name: Oak\nType: Deciduous\nAge: 50\n");

    buffer.str("");
    std::cout.clear();
    pine.print(std::cout);
    EXPECT_EQ(buffer.str(), "Name: Pine\nType: Coniferous\nAge: 1\n");

    std::cout.rdbuf(old);
}

TEST(FruitTreeTest, PrintMethod) 
{
    FruitTree apple("Apple", TreeType::Deciduous, 10, 100, 7);
    FruitTree orange("Orange", TreeType::Deciduous);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    apple.print(std::cout);
    EXPECT_EQ(buffer.str(), "Name: Apple\nType: Deciduous\nAge: 10\nCross mass: 100\nStorage duration: 7\n");

    buffer.str("");
    orange.print(std::cout);
    EXPECT_EQ(buffer.str(), "Name: Orange\nType: Deciduous\nAge: 1\nCross mass: 1\nStorage duration: 1\n");

    std::cout.rdbuf(old);
}

TEST(ForestTreeTest, PrintMethod) 
{
    ForestTree oak("Oak", TreeType::Deciduous, 50, 1000);
    ForestTree pine("Pine", TreeType::Coniferous);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    oak.print(std::cout);
    EXPECT_EQ(buffer.str(), "Name: Oak\nType: Deciduous\nAge: 50\nAmount of wood: 1000\n");

    buffer.str("");
    pine.print(std::cout);
    EXPECT_EQ(buffer.str(), "Name: Pine\nType: Coniferous\nAge: 1\nAmount of wood: 1\n");

    std::cout.rdbuf(old);
}

TEST(ForestTest, ConstructorAndMethods) 
{
    Forest forest(5);
    EXPECT_EQ(forest.size(), 5);

    ForestTree oak("Oak", TreeType::Deciduous, 50, 1000);
    forest.pushBack(&oak);
    EXPECT_EQ(forest.size(), 6);
    EXPECT_EQ(forest.countingType(TreeType::Deciduous), 1);
    EXPECT_EQ(forest.countingType(TreeType::Coniferous), 0);

    EXPECT_EQ(forest.countingView(&oak), 1);
}

TEST(ForestTest, Operators) 
{
    Forest forest;
    std::istringstream input("Coniferous Oak 50 forest 1000");
    input >> forest;
    EXPECT_EQ(forest.size(), 1);
    EXPECT_EQ(forest.countingType(TreeType::Deciduous), 0);
    EXPECT_EQ(forest.countingType(TreeType::Coniferous), 1);

    std::stringstream output;
    forest.print(output);
    std::string expectedOutput = "Name: Oak\nType: Coniferous\nAge: 50\nAmount of wood: 1000\n################################\n";
    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
