#include <gtest/gtest.h>
#include "ik.h"

Ik_solver r;

TEST(set_endpoint_0, should_pass) {
r.input_end_point(0,0,0);
ASSERT_DOUBLE_EQ(r.x_final,0);
ASSERT_DOUBLE_EQ(r.y_final,0);
ASSERT_DOUBLE_EQ(r.z_final,0);
}

TEST(set_endpoint_pos, should_pass) {
r.input_end_point(432,432.432,0.432);
ASSERT_DOUBLE_EQ(r.x_final,432);
ASSERT_DOUBLE_EQ(r.y_final,432.432);
ASSERT_DOUBLE_EQ(r.z_final,0.432);
}

TEST(set_endpoint_neg, should_pass) {
r.input_end_point(-10,-10,-10);
ASSERT_DOUBLE_EQ(r.x_final,-10);
ASSERT_DOUBLE_EQ(r.y_final,-10);
ASSERT_DOUBLE_EQ(r.z_final,-10);
}
