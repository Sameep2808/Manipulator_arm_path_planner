/**
 * Copyright 2021 <Sameep Pote> <Yash Kulkarni>
**/
#include <gtest/gtest.h>
#include <ik.h>

Ik_solver r;

TEST(dummy_test, should_pass) {
  r.limit_movement();
  EXPECT_EQ(1, 1);
}

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
  r.set_initial();
  ASSERT_DOUBLE_EQ(r.x_final, 5);
  ASSERT_DOUBLE_EQ(r.y_final, 3);
  ASSERT_DOUBLE_EQ(r.z_final, 0);
}

TEST(ik_solve_check, should_pass) {
  r.input_end_point(8, 2, 8);
  r.ik_solve(45);
  ASSERT_DOUBLE_EQ(r.angle[0], 45);
  ASSERT_DOUBLE_EQ(r.angle[1], 20.339051610130117);
  ASSERT_DOUBLE_EQ(r.angle[2], 1.2409922980326833);
  ASSERT_DOUBLE_EQ(r.angle[3], 68.419956091837207);
}
