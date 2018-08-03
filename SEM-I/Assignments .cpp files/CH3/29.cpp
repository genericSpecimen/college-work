#include<iostream>
int main()
{
	int num1,num2;
	std::cout<<"\nEnter two integers (first divided by second)\n";
	std::cin>>num1>>num2;
	std::cout<<"\nQuotient: "<<num1/num2;
	std::cout<<"\nRemainder: "<<num1%num2;
	return 0;
}