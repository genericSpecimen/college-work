#include<iostream>
int main()
{
	int num,sum=0,product=1;
	std::cout<<"\nEnter an integer\n";
	std::cin>>num;
	while(num>0)
	{
		sum += num%10;
		product *= num%10;
		num/=10;
	}
	std::cout<<"\nSum of digits: "<<sum;
	std::cout<<"\nProduct of digits: "<<product;

}