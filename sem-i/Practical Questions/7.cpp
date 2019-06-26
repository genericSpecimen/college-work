#include<iostream>
int main()
{
	int num;
	std::cout << "\nEnter a number to compute it's factors\n";
	std::cin >> num;
	std::cout << "\nFactors of "<< num << "are: ";
	for(int i=1;i<=num;i++)
	{
		if(num % i == 0)
			std::cout << i <<',';
	}
}