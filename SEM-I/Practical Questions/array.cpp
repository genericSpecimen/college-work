#include<iostream>

void function(int a[])
{
	std::cout << sizeof(a) << std::endl;
}

int main()
{
	int a[] = {1,2,3,4,5};
	std::cout << sizeof(a) << std::endl;
	function(a);
}