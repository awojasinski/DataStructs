#include "gtest/gtest.h"

extern "C" {
#include "linked_list.h"
}

TEST(widget, ok) {
  ASSERT_EQ(widget_ok(2, 3), 1);
}

TEST(widget, not_ok) {
  ASSERT_EQ(widget_ok(1, 2), 0);
}