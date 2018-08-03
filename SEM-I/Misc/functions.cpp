//FUNCTIONS
#include<iostream>
//int multiply(int num1, int num2); //function prototype/declaration used to declare name, return type and number of arguments
int multiply(int, int);
int main()
{
	int number1,number2;
	std::cout<<"\nEnter two numbers (separated by space or by pressing enter) to multiply them";
	std::cin>>number1>>number2;
	int product = multiply(number1,number2);//function call
	std::cout<<product;
	return 0;
}
int multiply(int num1,int num2) //function definition
{
	return num1*num2;
}