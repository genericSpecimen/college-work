#include<iostream>
const int penny = 1, nickel = 5, dime = 10, quarter = 25;
int main()
{
	float purchasePrice, billTendered, change; int changeInCents;
	int numQuarter  = 0, numDime = 0, numNickel = 0, numPenny = 0;
	std::cout << "\nEnter the purchase price\n";
	std::cin >> purchasePrice;
	std::cout << "\nEnter size of bill tendered\n";
	std::cin >> billTendered;
	change = billTendered - purchasePrice;
	std::cout <<"\nChange due: "<<change;
	std::cout <<"\nChange required in Dollars: "<<static_cast<int>(change);
	changeInCents = static_cast<int> (((change - static_cast<int>(change))*100));
	std::cout << "\nChange in cents: "<< changeInCents;	

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

	std::cout << "\nNumber of quarters required: "<<numQuarter;
	std::cout << "\nNumber of dimes required: "<<numDime;
	std::cout << "\nNumber of nickels required: "<<numNickel;
	std::cout << "\nNumber of pennies required: "<<numPenny;
}