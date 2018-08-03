#include <iostream>
//program to find reverse of a number
int main()
{
	int num;
	std::cout<<"\nEnter an integer\n";
	std::cin>>num;
	while(num>0)
		{ 
			std::cout<<num%10;
			num/=10;
		}
	return 0;	
}