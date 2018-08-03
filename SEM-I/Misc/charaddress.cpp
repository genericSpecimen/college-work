#include<iostream>
int main()
{
	char a,b;
	std::cout<<static_cast<void *>(&a)<<' '<<static_cast<void *>(&b);
	//std::cout<<"\nHello\n";
}