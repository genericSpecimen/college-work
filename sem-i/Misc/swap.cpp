//show the use of pointers in functions
#include<iostream>
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int num1,num2;
	std::cout<<"\nEnter two numbers to swap them\n";
	std::cin>>num1>>num2;
	swap(&num1,&num2);
	std::cout<<"\nSwapped numbers: "<<num1<<' '<<num2;
}