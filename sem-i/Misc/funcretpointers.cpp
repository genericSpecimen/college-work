#include<iostream>
//functions returning pointers
int* smaller(int* a, int * b)
{
	return (*a < *b ? a : b);
}

int main()
{
	int a = 2;
	int b = 3;
	std::cout << *(smaller(&a, &b)) << std::endl;
}