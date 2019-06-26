#include<iostream>
class circle
{
	public:
		const double pi = 3.14159;
		double radius, area, circumference;
	    void calcAreaCircum(double);
};

void circle::calcAreaCircum(double radius)
{
	area = pi * radius * radius;
	circumference = 2 * pi * radius;
}

int main()
{
	circle c1;
	std::cout << "\nEnter the radius of circle: ";
	std::cin >> c1.radius;
	c1.calcAreaCircum(c1.radius);
	std::cout <<"\nArea of circle: "<<c1.area;
	std::cout <<"\nCircumference of circle: "<<c1.circumference;

}