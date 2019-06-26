#include<iostream>
int main()
{
	int a = 9;
	int* p = &a;
	std::cout << *p++;
}