#include<iostream>
void addem(int& x, int& y)
{
	x += 2;
	y += 5;
}

int main()
{
	int a , b;
	std::cout << "\nEnter two integers: ";
	std::cin >> a >> b;
	addem(a,b);
	std::cout << a <<' ' << b << std::endl; 
}