///============================================================================
/// @file        : ik.cpp
/// @author      : Sameep Pote (Driver)
/// @author      : Yash Kulkarni (Navigator)
/// @version     : 1.0
/// @author      : Yash Kulkarni (Driver)
/// @author      : Sameep Pote (Navigator)
/// @version     : 2.0
/// @copyright   : MIT License
/// @brief       : ik.cpp This file is used to write all ther ik solver codes
///============================================================================

#include <ik.h>
#include <iostream>
#include <cmath>

void Ik_solver::input_end_point(double x, double y, double z) {
  x_final = x;
  y_final = y;
  z_final = z;
}

void Ik_solver::ik_solve(double phi) {
  double rad = M_PI / 180;
  angle[0] = atan(z_final / x_final) / rad;
  double x2 = x_final - (length[2] * cos(rad * phi));
  double y2 = y_final - (length[2] * sin(rad * phi));
  angle[2] =
      (acos(
          ((x2 * x2) + (y2 * y2) - (length[0] * length[0])
              - (length[1] * length[1])) / (2 * length[1] * length[0]))) / rad;
  /*angle[1] = (acos(
   (((length[0] + (length[1] * cos(angle[2]))) * x2)
   + (length[1] * y2 * sin(angle[2]))) / ((x2 * x2) + (y2 * y2)))) / rad;*/
  double c1 = ((((length[0] + (length[1] * cos(angle[2]))) * x2)
      + (length[1] * y2 * sin(angle[2]))) / ((x2 * x2) + (y2 * y2)));
  double s1 = ((((length[0] + (length[1] * cos(angle[2]))) * y2)
      + (length[1] * x2 * sin(angle[2]))) / ((x2 * x2) + (y2 * y2)));
  angle[1] = atan(s1 / c1);
  angle[3] = phi - (angle[1] + angle[2]);
  std::cout << angle[0] << std::endl;
  std::cout << angle[1] << std::endl;
  std::cout << angle[2] << std::endl;
  std::cout << angle[3] << std::endl;
}

void Ik_solver::set_initial(double l1, double l2, double l3) {
  length[0] = l1;
  length[1] = l2;
  length[2] = l3;
  input_end_point(l1 + l2 + l3, 0, 0);
}
