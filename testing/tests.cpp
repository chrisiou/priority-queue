#include <gtest/gtest.h>
#include "../priority_queue.h"
#include "../priority_queue.cpp"

TEST( test_priority_queue, size)
{
    Priority_queue<int> q;
    ASSERT_EQ(q.size(), 0);
    q.push(4);
    ASSERT_EQ(q.size(), 1);
}

TEST( test_priority_queue, empty)
{
    Priority_queue<int> q;
    ASSERT_TRUE(q.empty());
}

TEST( test_priority_queue, clear) 
{
    Priority_queue<int> q;
    q.push(1);
    ASSERT_FALSE(q.empty());
    q.clear();
    ASSERT_TRUE(q.empty());
}

TEST( test_priority_queue, top) 
{
   Priority_queue<int> q;
   q.push(666);
   ASSERT_EQ(q.top(), 666);
}

TEST( test_priority_queue, push) 
{
   Priority_queue<int> q;
   q.push(666);
   ASSERT_EQ(q.top(), 666);
   q.push(123);
   q.push(111);
   ASSERT_EQ(q.top(), 666);
   q.push(777);
   ASSERT_EQ(q.top(), 777);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
