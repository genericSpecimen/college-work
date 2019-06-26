#include<iostream>
int main()
{
	float temp;
	std::cout<<"\nEnter temp in centigrade\n";
	std::cin>>temp;
	std::cout<<"\nTemperature in Fahrenheit: "<<32+(temp*1.8);
	return 0;
}