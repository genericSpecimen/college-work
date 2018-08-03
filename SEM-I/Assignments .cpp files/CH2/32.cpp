#include<iostream>
int main()
{
	int input;
	std::cout<<"\nEnter an integer\n";
	std::cin>>input;
	std::cout<<"\nThe number as a character: "<<(char)input;
	std::cout<<"\nThe number as a decimal: "<<input;
	std::cout<<"\nThe number as a float: "<<(float)input;
	return 0;
}