#include<iostream>
int main()
{
	int a,b,c;
	std::cout<<"\nPlease enter three numbers\n";
	std::cin>>a>>b>>c;
	std::cout<<"\nYour numbers forward: \n";
	std::cout<<a<<std::endl<<b<<std::endl<<c<<std::endl;
	std::cout<<"\nYour numbers reversed: \n";
	std::cout<<c<<std::endl<<b<<std::endl<<a<<std::endl;
	return 0;
}