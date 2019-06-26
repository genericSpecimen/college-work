#include<iostream>
const int HDollar = 50, quarter = 25, dime = 10, nickel = 5, penny = 1;
void printChange(double* change)
{
	std::cout <<"\nChange due: "<< *change;
	std::cout <<"\nChange required in Dollars: "<<static_cast<int>(*change);
	int changeInCents = static_cast<int> (((*change - static_cast<int>(*change))*100));
	int numHDollar = 0, numQuarter = 0, numDime = 0, numNickel = 0, numPenny = 0;

	if( (changeInCents % 50) > 0 || (changeInCents % 50) == 0 )
	{
		numHDollar = changeInCents / 50;
		changeInCents = (changeInCents) - (numHDollar * HDollar);
	}

	if( (changeInCents % 25) > 0 || (changeInCents % 25) == 0 )
	{
		numQuarter = changeInCents / 25;
		changeInCents = (changeInCents) - (numQuarter * quarter);
	}

	if( (changeInCents % 10) > 0 || (changeInCents % 10) == 0 )
	{
		numDime = changeInCents / 10;
		changeInCents = (changeInCents) - (numDime * dime);
	}

	if( (changeInCents % 5) > 0 || (changeInCents % 5) == 0)
	{
		numNickel = changeInCents / 5;
		changeInCents = (changeInCents) - (numNickel * nickel);
	}

	if( (changeInCents % 1) > 0 || (changeInCents % 1) == 0)
	{
		numPenny = changeInCents / 1;
		changeInCents = (changeInCents) - (numPenny * penny);
	}

	std::cout << "\nNumber of half dollars required: "<<numHDollar;
	std::cout << "\nNumber of quarters required: "<<numQuarter;
	std::cout << "\nNumber of dimes required: "<<numDime;
	std::cout << "\nNumber of nickels required: "<<numNickel;
	std::cout << "\nNumber of pennies required: "<<numPenny;
}
int main()
{
	double price, billTendered;
	std::cout << "\nEnter the total price of items bought: ";
	std::cin >> price;
	std::cout << "\nEnter the size of bill tendered: ";
	std::cin >> billTendered;

	double change = billTendered - price;
	printChange(&change);
}