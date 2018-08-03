#include<iostream>
int main()
{
	char ans = 'y';
	do
	{
		int a, b, option;
		int* pa = &a;
		int* pb = &b;
		std::cout << "\nEnter two numbers: ";
		std::cin >> *pa >> *pb;
		std::cout << "\nWhat do you want to do?";
		std::cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Find remainder\n";
		std::cin >> option;
		switch(option)
		{
			case 1: std::cout << "\nSum: " << *pa + *pb; break; 
			case 2: std::cout << "\nAfter subtraction: " << *pa - *pb; break; 
			case 3: std::cout << "\nProduct: " << *pa * *pb; break; 
			case 4: std::cout << "\nQuotient: " << *pa / *pb; break; 
			case 5: std::cout << "\nRemainder: " << *pa % *pb; break;
			default: std::cout << "\nInvalid option.\n"; 
		}
		std::cout << "\nDo you want to continue?(y/n): ";
		std::cin >> ans;
	} while(ans == 'y' || ans == 'Y'); 
}