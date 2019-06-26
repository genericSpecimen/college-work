#include <iostream>
//program to demonstrate call by value and call by reference
//call by value
void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
int main()
{
	int x,y;
	std::cout<<"\nEnter two numbers to totally swap them\n";
	std::cin>>x>>y;
	swap(x,y);
	std::cout<<x<<std::endl<<y;
	return 0;
}

//CALL BY REFERENCE
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int x,y;
	std::cout<<"\nEnter two numbers to totally swap them\n";
	std::cin>>x>>y;
	swap(&x,&y);
	std::cout<<x<<std::endl<<y;
	return 0;
}