#include "ik.h"
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
      acos(
          ((x2 * x2) + (y2 * y2) - (length[0] * length[0])
              - (length[1] * length[1])) / (2 * length[1] * length[0]));
  angle[1] = (acos(
      (((length[0] + length[1] * cos(angle[2])) * x2)
          + (length[1] * y2 * sin(angle[2]))) / ((x2 * x2) + (y2 * y2)))) / rad;
  angle[3] = 90 - (angle[1] + angle[2]);
  std::cout << angle[0] << std::endl;
  std::cout << angle[1] << std::endl;
  std::cout << angle[2] << std::endl;
  std::cout << angle[3] << std::endl;
}

void Ik_solver::set_initial() {
  std::cout << "Enter the length of 3 links" << std::endl;
  std::cin >> length[0];
  std::cin >> length[1];
  std::cin >> length[2];
  input_end_point(x_initial,y_initial,z_initial);
  ik_solve(45);
}
