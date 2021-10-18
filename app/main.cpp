#include <iostream>
#include <lib.hpp>
#include "ik.h"
#include <cmath>

int main() {

  Ik_solver rob;

  double x, y, z;

  rob.set_initial();
  std::cout << "Enter the final position" << std::endl;
  std::cin >> x;
  std::cin >> y;
  std::cin >> z;

  rob.input_end_point(x, y, z);
  rob.ik_solve();

  return 0;
}
