#include<iostream>
int main()
{
	int a,b,c;
	int* x = &a;

	int* p = &b;
	int **y = &p;

	int* q = &c;
	int** r = &q;
	int*** z = &r;

	std::cout << "\nEnter the values of a and b: ";
	std::cin >> *x >> **y;
	***z = *x * **y;
	std::cout << "\n Value of a: " << *x;
	std::cout << "\n Value of b: " << **y;
	std::cout << "\n Value of c: " << ***z << std::endl;
}