#ifndef _INCLUDE_IK_H
#define _INCLUDE_IK_H

class Ik_solver {

 private:
  double length[3] = { 1, 1, 1 };
  double angle[4];
  double x_initial = 1, y_initial = 1, z_initial = 1;

 public:

  double new_angle[4];
  double x_final, y_final, z_final;

  void input_end_point(double x, double y, double z);

  void ik_solve();

  void set_initial();

};

#endif

