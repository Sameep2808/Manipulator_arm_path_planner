///============================================================================
/// @file        : ik.cpp
/// @author      : Sameep Pote (Driver)
/// @author      : Yash Kulkarni (Navigator)
/// @version     : 1.0
/// @author      : Yash Kulkarni (Driver)
/// @author      : Sameep Pote (Navigator)
/// @version     : 2.0
/// @copyright   : MIT License
/// @brief       : ik.h This file is used to define all ther ik solver codes
///============================================================================

#ifndef INCLUDE_IK_H_
#define INCLUDE_IK_H_

/// @class Ik_solver
/// @brief The class used to compute the inverse kinematics of robotic arm
class Ik_solver {
 private:
  double length[3] = { 1, 1, 1 };
  double x_initial = 5, y_initial = 3, z_initial = 0;

 public:
  double x_final, y_final, z_final;
  double angle[4] = { 0, 0, 0, 0 };

  /// @fn void input_end_point(double, double, double)
  /// @brief function used to take input endpoint from the user
  /// @param x
  /// @param y
  /// @param z
  void input_end_point(double x, double y, double z);

  /// @fn void ik_solve(double)
  /// @brief function used to compute inverse kinematics for robotic arm
  /// @param phi
  void ik_solve(double phi);

  /// @fn void set_initial()
  /// @brief function used to set initial constraints for robotic arm
  ///
  void set_initial(double l1, double l2, double l3);

};
#endif  // INCLUDE_IK_H_
