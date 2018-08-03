#include<iostream>
int main()
{
	float l,b;
	std::cout<<"\nEnter length and breadth of rectangle to calculate it's area and perimeter\n";
	std::cin>>l>>b;
	std::cout<<"\nArea: "<<l*b;
	std::cout<<"\nPerimeter: "<<2*(l+b);
	return 0;
}