#include "gtest.h"
#include "tqueue.h"
#include <vector>

TEST(TQueue, can_initialize) {
    ASSERT_NO_THROW(TQueue<int> m(5));
}

TEST(TQueue, can_insert_element) {
    TQueue<int> m(5);
    ASSERT_NO_THROW(m.push(5));
}

