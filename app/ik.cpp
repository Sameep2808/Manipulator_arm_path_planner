#include <ik.h>
#include <iostream>

void Ik_solver::input_end_point(double x,double y,double z) {
	x_final=x;
	y_final=y;
	z_final=z;
}

void Ik_solver::ik_solve() {
	angle[0]=


}

void Ik_solver::set_initial(){
	std::cout<<"Enter the length of 3 links"<<std::endl;
	std::cin>>length[0];
	std::cin>>length[1];
	std::cin>>length[2];
	input_end_point(x_initial,y_initial,z_initial);
}
