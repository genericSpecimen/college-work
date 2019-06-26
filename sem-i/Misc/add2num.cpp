//add two numbers using pointers 
#include<iostream>
int main()
{
	int num1,num2;
	std::cout<<"\nEnter two numbers to add them\n";
	std::cin>>num1>>num2;
	int* ptr2num1 = &num1;
	int* ptr2num2 = &num2;
	int sum = *ptr2num1 + *ptr2num2;
	std::cout<<"\nSum of numbers: "<<sum;
	return 0;
}