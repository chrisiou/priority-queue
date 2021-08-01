#include <gtest/gtest.h>
#include "../priority_queue.h"
#include "../priority_queue.cpp"

class TestObj {
public:
    int id = 0;
    TestObj() = default;
    TestObj(int n) : id(n){};
    friend bool operator<(const TestObj& q1, const TestObj& q2);
    friend bool operator>(const TestObj& q1, const TestObj& q2);
    friend bool operator==(const TestObj& q1, const TestObj& q2);
};
bool operator<(const TestObj& q1, const TestObj& q2) { return q1.id > q2.id;}
bool operator>(const TestObj& q1, const TestObj& q2) { return q1.id > q2.id;}
bool operator==(const TestObj& q1, const TestObj& q2) { return q1.id == q2.id;}

void test_heapify(void) {
    Priority_queue<int> q;
    q.push(3);
    ASSERT_EQ(q.data[0], 3);

    q.push(6);
    q.push(10);
    ASSERT_EQ(q.data[0], 10);
    ASSERT_EQ(q.data[1], 3);
    ASSERT_EQ(q.data[2], 6);

    Priority_queue<TestObj> q1;
    TestObj obj1(3);
    q1.push(obj1);
    ASSERT_EQ(q1.data[0].id, 3);
    TestObj obj2(6);
    q1.push(obj2);
    TestObj obj3(10);
    q1.push(obj3);
    ASSERT_EQ(q1.data[0].id, 10);
    ASSERT_EQ(q1.data[1].id, 3);
    ASSERT_EQ(q1.data[2].id, 6);
}

void test_pop_heapify(void) {
    Priority_queue<int> q;
    q.push(3);
    q.push(6);
    q.push(10);
    q.pop();
    ASSERT_EQ(q.data[0], 6);
    q.pop();
    ASSERT_EQ(q.data[0], 3);

    Priority_queue<TestObj> q1;
    TestObj obj1(3);
    q1.push(obj1);
    TestObj obj2(6);
    q1.push(obj2);
    TestObj obj3(10);
    q1.push(obj3);
    std::cout << q1.pop().id << std::endl;
    for (size_t i = 0; i < q1.size(); ++i) { 
        std::cout << (q1.data[i]).id << " ";
    }
    
    ASSERT_EQ(q1.data[0].id, 6);
    q1.pop();
    ASSERT_EQ(q1.data[0].id, 3);
}

void test_bigger_family_member_method(void) {
    Priority_queue<int> q;
    q.push(3);
    q._size = 3;
    q.data[1] = 6;
    q.data[2] = 10;
    ASSERT_EQ(q.bigger_family_member(0), 2);

    q.data[0] = 10;
    q.data[1] = 6;
    q.data[2] = 3;
    ASSERT_EQ(q.bigger_family_member(0), 0);
}

TEST(test_priority_queue, heapify) { test_heapify();}

TEST(test_priority_queue, pop_heapify) { test_pop_heapify();}

TEST(test_priority_queue, bigger_family_member_method) { test_bigger_family_member_method();}

TEST(test_priority_queue, size) {
    Priority_queue<int> q;
    Priority_queue<TestObj> q1;
    ASSERT_EQ(q.size(), 0);
    ASSERT_EQ(q1.size(), 0);

    q.push(4);
    TestObj obj1;
    q1.push(obj1);
    ASSERT_EQ(q.size(), 1);
    ASSERT_EQ(q1.size(), 1);
}

TEST(test_priority_queue, capacity) {
    Priority_queue<int> q;
    ASSERT_EQ(q.capacity(), 0);
    Priority_queue<TestObj> q1;
    ASSERT_EQ(q1.capacity(), 0);

    q.push(4);
    ASSERT_EQ(q.capacity(), 2*ARRAY_SIZE);
    TestObj obj1;
    q1.push(obj1);
    ASSERT_EQ(q1.capacity(), 2*ARRAY_SIZE);

    int i = 0;
    while (i < 2*ARRAY_SIZE) {
        q.push(i++);
        TestObj obj(i);
        q1.push(obj);
    }
    ASSERT_EQ(q.capacity(), 4*ARRAY_SIZE);
    ASSERT_EQ(q1.capacity(), 4*ARRAY_SIZE);
}

TEST(test_priority_queue, empty) {
    Priority_queue<int> q;
    ASSERT_TRUE(q.empty());
    q.push(2);
    ASSERT_FALSE(q.empty());

    Priority_queue<TestObj> q1;
    ASSERT_TRUE(q1.empty());
    TestObj obj1(2);
    q1.push(obj1);
    ASSERT_FALSE(q1.empty());
}

TEST(test_priority_queue, clear) {
    Priority_queue<int> q;
    q.push(1);
    ASSERT_FALSE(q.empty());
    q.clear();
    ASSERT_TRUE(q.empty());

    Priority_queue<TestObj> q1;
    TestObj obj1;
    q1.push(obj1);
    ASSERT_FALSE(q1.empty());
    q1.clear();
    ASSERT_TRUE(q1.empty());
}

TEST(test_priority_queue, top) {
    Priority_queue<int> q;
    q.push(666);
    ASSERT_EQ(q.top(), 666);

    Priority_queue<TestObj> q1;
    TestObj obj1(2);
    q1.push(obj1);
    ASSERT_EQ(q1.top(), obj1);
}

TEST(test_priority_queue, push) {
    Priority_queue<int> q;
    q.push(666);
    ASSERT_EQ(q.top(), 666);
    q.push(123);
    q.push(111);
    ASSERT_EQ(q.top(), 666);

    Priority_queue<TestObj> q1;
    TestObj obj1(2);
    TestObj obj2(3);
    q1.push(obj1);
    ASSERT_EQ(q1.top(), obj1);
    q1.push(obj2);
    ASSERT_EQ(q1.top(), obj2);
}

TEST(test_priority_queue, pop) {
    Priority_queue<int> q;    
    q.push(121);
    q.push(122);
    q.push(123);
    ASSERT_EQ(q.pop(), 123);
    ASSERT_EQ(q.pop(), 122);
    ASSERT_EQ(q.size(), 1);

    Priority_queue<TestObj> q1;
    TestObj obj1(2);
    TestObj obj2(3);
    q1.push(obj1);
    q1.push(obj2);
    ASSERT_EQ(q1.pop(), obj2);
    ASSERT_EQ(q1.pop(), obj1);
    ASSERT_EQ(q1.size(), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}
