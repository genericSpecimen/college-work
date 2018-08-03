#include<iostream>
#define swap(a,b) {int temp = a; a = b; b = temp;}   //macro to swap two numbers
int main()
{
	int x,y;
	std::cout << "\nEnter two numbers to swap them\n";
	std::cin >> x >> y;
	swap(x,y);
	std::cout << "\nSwapped numbers are: " << x <<' ' << y;
}