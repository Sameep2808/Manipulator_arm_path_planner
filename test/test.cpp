///============================================================================
/// @file        : test.cpp
/// @author      : Sameep Pote (Driver)
/// @author      : Yash Kulkarni (Navigator)
/// @version     : 1.0
/// @author      : Yash Kulkarni (Driver)
/// @author      : Sameep Pote (Navigator)
/// @version     : 2.0
/// @copyright   : MIT License
/// @brief       : test.cpp This file is used for unit testing all the fuctions
///============================================================================
#include <gtest/gtest.h>
#include <ik.h>

Ik_solver r;

TEST(set_endpoint_0, should_pass) {
  r.input_end_point(0, 0, 0);
  ASSERT_DOUBLE_EQ(r.x_final, 0);
  ASSERT_DOUBLE_EQ(r.y_final, 0);
  ASSERT_DOUBLE_EQ(r.z_final, 0);
}

TEST(set_endpoint_pos, should_pass) {
  r.input_end_point(432, 432.432, 0.432);
  ASSERT_DOUBLE_EQ(r.x_final, 432);
  ASSERT_DOUBLE_EQ(r.y_final, 432.432);
  ASSERT_DOUBLE_EQ(r.z_final, 0.432);
}

TEST(set_endpoint_neg, should_pass) {
  r.input_end_point(-10, -10, -10);
  ASSERT_DOUBLE_EQ(r.x_final, -10);
  ASSERT_DOUBLE_EQ(r.y_final, -10);
  ASSERT_DOUBLE_EQ(r.z_final, -10);
}

TEST(set_initial, should_pass) {
  r.set_initial(1, 1, 1);
  ASSERT_DOUBLE_EQ(r.x_final, 3);
  ASSERT_DOUBLE_EQ(r.y_final, 0);
  ASSERT_DOUBLE_EQ(r.z_final, 0);
}

TEST(ik_solve_check, should_pass) {
  r.input_end_point(3, 0, 0);
  r.ik_solve(0);
  ASSERT_DOUBLE_EQ(r.angle[0], 0);
  ASSERT_DOUBLE_EQ(r.angle[1], 0);
  ASSERT_DOUBLE_EQ(r.angle[2], 0);
  ASSERT_DOUBLE_EQ(r.angle[3], 0);
}
