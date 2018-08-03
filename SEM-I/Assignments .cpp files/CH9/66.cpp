#include<iostream>
void intANDfrac(double* num)
{
	std::cout << "\nThe integral part is: " << static_cast<int> (*num);
	std::cout << "\nThe fractional part is: " << *num - static_cast<int> (*num) << std::endl;
}
int main()
{
	double number;
	std::cout << "\nEnter a floating point number: ";
	std::cin >> number;
	intANDfrac(&number);
}