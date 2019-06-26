//type casting
#include<iostream>
int main()
{
	double x = 5.25;
	int y;
	y=x; //implicit type casting done by the compiler
	std::cout<<y; //5


	y = (int)x; //explicit type casting 
	
}