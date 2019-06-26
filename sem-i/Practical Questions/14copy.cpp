#include<iostream>
#define pi 3.14159
void calc(double radius, double &area, double &circumference)
{
	area = pi * radius * radius;
	circumference = 2 * pi * radius;
}

int main()
{
	double radius, area, circumference;
	std::cout << "\nEnter the radius of a circle\n";
	std::cin >> radius;
	calc(radius,area,circumference);
	std::cout << "\nArea of circle: "<<area;
	std::cout << "\nCircumference of circle: "<<circumference;
}