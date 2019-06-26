#include<iostream>
int main()
{
	int a,b,c;
	int* p = &a; 
	int* q = &b; 
	int* r = &c;
	std::cout << "\nEnter three integers: ";
	std::cin >> *p >> *q >> *r; 
	
	p = &c;
	q = &a;
	r = &b;
	std::cout << "\nAddress of a: " << q << " Value of a: " << *q;
	std::cout << "\nAddress of b: " << r << " Value of b: " << *r;
	std::cout << "\nAddress of c: " << p << " Value of c: " << *p << std::endl;
}