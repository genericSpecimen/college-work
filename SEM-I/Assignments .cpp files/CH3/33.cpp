#include<iostream>
int main()
{
	float angle;
	std::cout<<"\nEnter an angle in degrees\n";
	std::cin>>angle;
	std::cout<<std::endl<<angle<<" degrees"<<" is "<<angle/57.295779<<" radians\n";
	return 0;
}