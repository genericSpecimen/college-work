#include<iostream>
//program to check if number entered by user is prime or not
int main()
{
	int num,flag=1;
	std::cout<<"\nEnter a positive integer\n";
	std::cin>>num;
	for(int i=2;i<(num/2);i++)
	{
		if(num%i==0)
			flag=0;
	}
	if(flag==0)
		std::cout<<"\nNumber is not prime\n";
	else
		std::cout<<"\nNumber is prime";
	
}