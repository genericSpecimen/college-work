#include<iostream>
int main()
{
	int num;
	std::cout<<"\nEnter an integer to reverse it: ";
	std::cin>>num;
	std::cout<<"\nThe reversed number is: ";
	while(num>0)
	{
		std::cout<<num%10;
		num/=10;
	}
	return 0;
}