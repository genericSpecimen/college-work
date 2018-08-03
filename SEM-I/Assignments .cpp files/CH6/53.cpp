#include<iostream>
#include<cmath>
int main()
{
	float num,sum = 0,product = 1,sumOfInverse = 0;
	int i=0;
	std::cout<<"\nEnter numbers to calculate their average, geometric mean and the harmonic mean\n";
	while(std::cin>>num)
	{
		sum += num;
		product *= num;
		sumOfInverse += (1/num);
		i++;
	}

	std::cout<<"\nArithmetic mean of these numbers: "<<sum/i;
	std::cout<<"\nGeometric mean of these numbers: "<<pow(product,(1/static_cast<float>(i)));
	std::cout<<"\nHarmonic mean of these numbers: "<<(i/sumOfInverse);
}