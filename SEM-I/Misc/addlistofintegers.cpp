#include<iostream>
int main()
{
	int i=0,num[5],sum=0;
	std::cout<<"\nEnter 5 numbers\n";
	while(i<5)
	{
		std::cin>>num[i];
		sum+=num[i];
		i++;
	}
	std::cout<<"\nSum of numbers= "<<sum;

}