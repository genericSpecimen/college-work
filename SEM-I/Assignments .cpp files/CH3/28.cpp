#include<iostream>
int main()
{
	float x,y,p,s,total;
	std::cout<<"\nEnter two floating point numbers\n";
	std::cin>>x>>y;
	p=x*y;
	s=x+y;
	total=s*s + p * (s - x) * (p + y);
	std::cout<<"\nTotal: "<<total;
	return 0;
}