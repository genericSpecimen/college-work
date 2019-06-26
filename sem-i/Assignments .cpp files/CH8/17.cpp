#include<iostream>
int main()
{
	int list[10] = {2,1,2,1,1,2,3,2,1,2};
	std::cout << list[2] << std::endl;
	std::cout << list[list[2]] << std::endl;
	std::cout << list[list[2] + list [3]] << std::endl;
	std::cout << list[list[list[2]]] << std::endl;
}