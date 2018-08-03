#include<iostream>
void isValid(int isbn[])
{
	int weightedsum = 0;
	for(int i=0;i<10;i++)
	{
		weightedsum += isbn[i]*(10-i);
	}
	std::cout << "\nWighted sum= " << weightedsum;
	if(weightedsum % 11 == 0)
		std::cout << "\nISBN is valid\n";
	else
		std::cout << "\nISBN is invalid\n";
}

void sumofsums(int isbn[])   //USING THE SUMOFSUMS METHOD
{
	int sumdig = 0, sumofsum = 0;
	for(int i=0;i<10;i++)
	{
		sumdig += isbn[i];
		sumofsum += sumdig;
	}
	std::cout << "\nSum of sums: " << sumofsum;
	if(sumofsum % 11 == 0)
		std::cout << "\nISBN is valid\n";
	else
		std::cout << "\nISBN is invalid\n";
}
int main()
{
	int isbn[10];
	std::cout << "\nEnter 10 digit ISBN number without dashes and with spaces\n";
	for(int i=0;i<10;i++)
		std::cin >> isbn[i];
	//isValid(isbn);
	sumofsums(isbn);
}