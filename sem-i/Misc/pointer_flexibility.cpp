//show the pointer flexibility when one pointer can point to many variables
#include<iostream>
int main()
{
	int a = 20, b = 30, c = 40;
	int* ptr = &a;
	std::cout<<"\nAddress of a: "<<ptr<<" Value of a: "<<*ptr;
	ptr = &b;
	std::cout<<"\nAddress of b: "<<ptr<<" Value of b: "<<*ptr;
	ptr = &c;
	std::cout<<"\nAddress of c: "<<ptr<<" Value of c: "<<*ptr;
}