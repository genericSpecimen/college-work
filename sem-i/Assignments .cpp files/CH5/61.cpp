#include<iostream>
#include<cmath>
void calculateRoots(double, double, double);
int main()
{
	double a,b,c;
	std::cout<<"\nCalculate the real root(s) of a quadratic equation\n";
	std::cout<<"\nEnter the constants (a,b,c) of the quadratic equation of the form ax^2 + bx + c = 0\n";
	std::cin >> a >> b >> c;
	calculateRoots(a,b,c);
}

void calculateRoots(double a, double b, double c)
{
	if(a == 0 && b == 0)
		std::cout<<"\nIt has no solution\n";
	else if (a == 0)
		std::cout<<"\nIt's not a quadratic equation, but a linear equation.\nThere's only one root: "<<(-c/b)<<'\n';
	else if((pow(b,2) - 4*a*c) < 0)
		std::cout<<"\nSince discriminant is negative, there are no real roots.\n";
	else
	{
		double root1,root2;
		root1 = (-b + sqrt(pow(b,2) - 4*a*c))/(2*a);
		root2 = (-b - sqrt(pow(b,2) - 4*a*c))/(2*a);
		std::cout<<"\nThe two roots are: "<< root1 <<" and "<< root2;
	}
}