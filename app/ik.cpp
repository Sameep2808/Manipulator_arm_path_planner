#include <ik.h>
#include <iostream>
#include <cmath>


void Ik_solver::input_end_point(double x,double y,double z) {
	x_final=x;
	y_final=y;
	z_final=z;
}

void Ik_solver::ik_solve() {
	angle[0]=atan(z_final/x_final);
	double x2=x_final-(length[2]*cos(90));
	double y2=y_final-(length[2]*sin(90));
	angle[2]=acos(((x2*x2)+(y2*y2)-(length[0]*length[0])-(length[1]*length[1]))/(2*length[1]*length[0]));
	angle[1]=acos((((length[0]+length[1]*cos(angle[1]))*x2)+(length[1]*y2*sin(angle[1])))/((x2*x2)+(y2*y2)));
}

void Ik_solver::set_initial(){
	std::cout<<"Enter the length of 3 links"<<std::endl;
	std::cin>>length[0];
	std::cin>>length[1];
	std::cin>>length[2];
	input_end_point(x_initial,y_initial,z_initial);
}
