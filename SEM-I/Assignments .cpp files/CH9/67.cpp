#include<iostream>
void gcd_lcm(int* a, int* b)
{
	int mod = *a % *b;
	int factor1 = *a, factor2 = *b;
	int gcd, lcm;
	while(mod > 0)
	{
		*a = *b;
		gcd = mod;
		mod = *a % mod;
	}
	if(mod == 0)
		std::cout << "GCD: " << gcd;
	lcm = (factor1 * factor2) / gcd;
	std::cout <<"\nLCM: " << lcm << std::endl;

}

int main()
{
	int num1, num2;
	std::cout << "\nEnter two numbers to calculate their gcd and lcm: ";
	std::cin >> num1 >> num2;
	gcd_lcm(&num1, &num2);
}