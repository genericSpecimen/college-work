#include<iostream>
int isValid(int isbn[])
{
	int weightedsum = 0;
	for(int i=0;i<10;i++)
	{
		weightedsum += isbn[i]*(10-i);
	}
	//std::cout << "\nWighted sum= " << weightedsum;
	if(weightedsum % 11 == 0)
		return 1;
	else
		return 0;	
}

int main()
{
	int isbn[10];
	std::cout << "\nEnter 10 digit ISBN number without dashes and with spaces\n";
	for(int i=0;i<10;i++)
		std::cin >> isbn[i];
	std::cout << isValid(isbn) << std::endl;
}