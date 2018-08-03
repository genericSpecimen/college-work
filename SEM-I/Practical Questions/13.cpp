#include<iostream>
void alterContents(int& x, int& y)
{
	x = x * 20;
	y = y + 100;
}

int main()
{
	int num1,num2;
	std::cout << "\nEnter two numbers to alter them: ";
	std::cin >> num1 >> num2;
	alterContents(num1, num2);
	std::cout <<"\nAltered contents: "<< num1 << ' ' <<num2;
	return 0;
}