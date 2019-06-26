//demonstrating pointers to pointers
#include<iostream>
int main()
{
	int a = 20;
	int* ptr2a = &a;
	int* ptr2ptr2a;
	ptr2ptr2a = &ptr2a;
	std::cout<<"\nAddress of a: "<<ptr2a;
	std::cout<<"\nValue of a: "<<*ptr2a;
	std::cout<<"\nAddress of pointer to a: "<<ptr2ptr2a;
	std::cout<<"\nValue of pointer to pointer to a (i.e. address of a): "<<*ptr2ptr2a;
}