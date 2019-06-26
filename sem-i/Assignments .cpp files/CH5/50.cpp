#include<iostream>
int parkingCharge(char type, int nohour)
{
	switch(type)
	{
		case 'c' : return 2*nohour;
		           break;
		case 'b' : return 3*nohour;
		           break;
		case 't' : return 4*nohour;           
	}
}
int main()
{
	char type;
	int nohour;
	std::cout<<"\nEnter vehicle type and number of hours\n 1. 'c' for car\n 2. 'b' for bus\n 3. 't' for truck\n";
	std::cin>>type>>nohour;
	int charge = parkingCharge(type,nohour);
	std::cout<<"\nParking Charge: "<<'$'<<charge;
	return 0;
}
