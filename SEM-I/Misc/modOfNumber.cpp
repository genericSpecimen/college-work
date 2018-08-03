#include<iostream>
int modnum(int num1,int num2)
{
	return num1%num2;
}
int main()
{
	int num1,num2;
	std::cout<<"\nEnter two numbers (separated by space or by pressing enter) to calculate their mod.";
	std::cin>>num1>>num2;
	int mod = modnum(num1,num2);
	std::cout<<num1<<" mod "<<num2<<" = "<<mod;
	return 0;
}