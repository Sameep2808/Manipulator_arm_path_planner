#include <iostream>
#include "ik.h"
#include <cmath>

int main() {

  Ik_solver rob;

  double x, y, z,phi;
  rob.set_initial();
  std::cout << "Enter the final position and end effector angle" << std::endl;
  std::cin >> x;
  std::cin >> y;
  std::cin >> z;
  std::cin >> phi;
  rob.input_end_point(x, y, z);
  rob.ik_solve(phi);

  return 0;
}
