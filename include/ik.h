#ifndef _INCLUDE_IK_H
#define _INCLUDE_IK_H

class Ik_solver {

 private:
  double length[3] = { 1, 1, 1 };
  double x_initial = 5, y_initial = 3, z_initial = 0;

 public:

  double x_final, y_final, z_final;
  double angle[4];
  void input_end_point(double x, double y, double z);

  void ik_solve(double phi);

  void set_initial();

  void get_points();

};

#endif

