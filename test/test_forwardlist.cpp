#include "gtest.h"
#include "forwardlist.h"
#include <vector>

TEST(TForwardList, can_initialize) {
    ASSERT_NO_THROW(TForwardList<int> m);
}

TEST(TForwardList, can_insert_element) {
    TForwardList<int> m;
    ASSERT_NO_THROW(m.insert(5));
}

TEST(TForwardList, can_initialize_via_vector) {
    std::vector<int> m = {1, 2, 3, 4, 5};
    ASSERT_NO_THROW(TForwardList<int> tmp(m));
}

//TEST(TForwardList, correct_initializing_with_vector) {
//    std::vector<int> m = {1, 2, 3, 4, 5};
//    TForwardList<int> tmp(m);
//    for (int i = 0; i < m.size(); i++) {
//        
//    }
//    ASSERT_NO_THROW(TForwardList<int> tmp(m));
//}

//TEST(TForwardList, correct_copy_constructor) {
//    std::vector<int> m = {1, 2, 3, 4, 5};
//    TForwardList<int> tmp(m);
//    TForwardList<int> file(tmp);
//    for (int i = 0; i < 5; i++) {
//        if (tmp[i] != file[i])
//
//    }
//}
