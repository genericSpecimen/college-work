#include<iostream>
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int num1,num2;
	std::cout << "\nEnter two numbers\n";
	std::cin >> num1 >>num2;
	std::cout <<"\nNumbers before swapping: "<<num1 <<' '<<num2;
	swap(&num1, &num2);
	std::cout <<"\nNumbers after swapping: "<<num1 <<' '<<num2;

}