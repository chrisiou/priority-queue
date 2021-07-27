#include <gtest/gtest.h>
#include "../priority_queue.h"
#include "../priority_queue.cpp"

TEST( test_priority_queue, size)
{
   Priority_queue<int> q;
   ASSERT_EQ(q.size(), 0);
}

TEST( test_priority_queue, empty)
{
   Priority_queue<int> q;
   ASSERT_TRUE(q.empty());
}

TEST( test_priority_queue, clear) 
{
   Priority_queue<int> q;
   q.clear();
   ASSERT_TRUE(q.empty());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
