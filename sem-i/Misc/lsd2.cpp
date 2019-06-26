//program to extract two least significant digits of a number and add them
#include<iostream>
void lsd2(int num1)
{
	int lsd1,lsd2;
	lsd1=num1%10;
	num1/=10; //num1=num1/10
	lsd2=num1%10;
	std::cout<<"LSD1="<<lsd1<<std::endl;
	std::cout<<"LSD2="<<lsd2<<std::endl;
	std::cout<<"Sum="<<lsd1+lsd2<<std::endl;
}
int main()
{
	int num1;
	std::cout<<"\nEnter kar number bhadwe\n";
	std::cin>>num1;
	lsd2(num1);
	return 0;
}