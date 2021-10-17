#include <ik.h>
#include <iostream>

void Ik_solver::input_end_point(double x,double y,double z) {
	x_final=x;
	y_final=y;
	z_final=z;
}

void Ik_solver::ik_solve() {

}

void Ik_solver::set_initial(){
	input_end_point(x_initial,y_initial,z_initial);
}
