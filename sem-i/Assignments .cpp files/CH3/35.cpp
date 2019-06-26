#include<iostream>
int main()
{
	float inch;
	std::cout<<"\nEnter a measurement in inches\n";
	std::cin>>inch;
	std::cout<<"\nMeasurement in foot: "<<inch/12;
	std::cout<<"\nMeasurement in yard: "<<inch/36;
	std::cout<<"\nMeasurement in centimeter: "<<inch*2.54;
	std::cout<<"\nMeasurement in meter: "<<inch/39.97;
	return 0;
}