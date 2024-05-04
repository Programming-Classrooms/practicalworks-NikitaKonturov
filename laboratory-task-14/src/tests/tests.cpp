
#include <stdexcept>
#include <gtest/gtest.h>
#include "../deque/deque.hpp"
#include "../cyclicQueue/cQueue.hpp"

class TDequeIntTest : public ::testing::Test {
protected:
    TDeque<int> deque;
};

class CQueueStringTest : public ::testing::Test {
protected:
    CQueue<char*> queue;

    void SetUp() override {
        queue.push_back(strdup("Hello"));
        queue.push_back(strdup("World"));
    }

    void TearDown() override {
        while (queue.size() > 0) {
            char* str = queue.pop_front();
            delete[] str; 
        }
    }
};

// Проверка вставки и извлечения элементов
TEST_F(TDequeIntTest, InsertionAndExtraction) {
    deque.InsFront(1);
    deque.InsFront(2);
    deque.InsRear(3);
    deque.InsRear(4);

    int value;
    ASSERT_TRUE(deque.DelFront(value));
    EXPECT_EQ(value, 2); // Проверяем удаление из головы, ожидаем 2
    ASSERT_TRUE(deque.DelRear(value));
    EXPECT_EQ(value, 4); // Проверяем удаление из хвоста, ожидаем 4
}

// Проверка получения элемента по индексу и изменения элемента
TEST_F(TDequeIntTest, GetByIndexAndSetByIndex) {
    deque.InsFront(1);
    deque.InsFront(2);
    deque.InsRear(3);
    deque.InsRear(4);

    EXPECT_EQ(deque.GetByIndex(0), 4); // Проверяем первый элемент, ожидаем 2
    EXPECT_EQ(deque.GetByIndex(2), 3); // Проверяем третий элемент, ожидаем 3

    deque.SetByIndex(10, 1);
    EXPECT_EQ(deque.GetByIndex(1), 10); // Изменяем второй элемент на 10 и проверяем его
}

// Проверка обработки исключений при попытке удаления из пустого дека
TEST_F(TDequeIntTest, ExceptionHandling) {
    int value;
    EXPECT_FALSE(deque.DelFront(value)); // Попытка удалить из пустого дека из головы
    EXPECT_FALSE(deque.DelRear(value)); // Попытка удалить из пустого дека из хвоста

    EXPECT_THROW(deque.GetByIndex(0), std::out_of_range); // Попытка получить элемент из пустого дека
    EXPECT_THROW(deque.SetByIndex(1, 0), std::out_of_range); // Попытка изменить элемент в пустом деке
}

// Проверка просмотра дека без изменения элементов
TEST_F(TDequeIntTest, BrowseWithoutModification) {
    deque.InsFront(1);
    deque.InsFront(2);
    deque.InsRear(3);
    deque.InsRear(4);

    // Суммируем элементы без изменения
    int sum = 0;
    deque.BrowseWithoutModification(std::function<void(int)>([&sum](int val){sum += val;}));
    EXPECT_EQ(sum, 10); // Ожидаем сумму всех элементов: 2 + 1 + 3 + 4 = 10
}

// Проверка просмотра дека с изменением элементов
TEST_F(TDequeIntTest, BrowseWithModification) {
    deque.InsFront(1);
    deque.InsFront(2);
    deque.InsRear(3);
    deque.InsRear(4);

    // Умножаем элементы на 2
    deque.BrowseWithModification(std::function<void(int&)>([](int& val){val *= 2;}));

    // Проверяем измененные элементы
    int value;
    ASSERT_TRUE(deque.DelFront(value));
    EXPECT_EQ(value, 4); // Первый элемент после изменения, ожидаем 4
    ASSERT_TRUE(deque.DelRear(value));
    EXPECT_EQ(value, 8); // Последний элемент после изменения, ожидаем 8
}

// Тестирование операций добавления и удаления элементов для строк
TEST_F(CQueueStringTest, PushPopOperations) {
    EXPECT_STREQ(queue.pop_front(), "Hello");
    EXPECT_STREQ(queue.pop_front(), "World");
}

// Тестирование операции индексации для строк
TEST_F(CQueueStringTest, IndexingOperation) {
    EXPECT_STREQ(queue[0], "Hello");
    EXPECT_STREQ(queue[1], "World");
}

// Тестирование операции поиска элемента для строк
TEST_F(CQueueStringTest, FindOperation) {
    EXPECT_EQ(queue.find("World"), 1); // Ожидаем индекс 1 для элемента "World"
}

// Тестирование размера очереди после добавления элементов
TEST_F(CQueueStringTest, SizeAfterPush) {
    EXPECT_EQ(queue.size(), 2);
}

// Тестирование размера очереди после извлечения всех элементов
TEST_F(CQueueStringTest, SizeAfterPopAll) {
    queue.pop_front();
    queue.pop_front();
    EXPECT_EQ(queue.size(), 0);
}

// Тестирование операции push_back
TEST_F(CQueueStringTest, PushBackOperation) {
    queue.push_back(strdup("Test"));
    EXPECT_STREQ(queue.pop_front(), "Hello");
    EXPECT_STREQ(queue.pop_front(), "World");
    EXPECT_STREQ(queue.pop_front(), "Test");
}

// Тестирование операции pop_front для пустой очереди
TEST_F(CQueueStringTest, PopFrontEmptyQueue) {
    CQueue<char*> emptyQueue;
    EXPECT_THROW(emptyQueue.pop_front(), std::out_of_range);
}

// Тестирование операции поиска элемента для пустой очереди
TEST_F(CQueueStringTest, FindOperationEmptyQueue) {
    CQueue<char*> emptyQueue;
    EXPECT_THROW(emptyQueue.find("Test"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
