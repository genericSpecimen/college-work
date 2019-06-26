#include<iostream>
int main()
{
	int n;
	std::cout<<"\nEnter number of rows\n";
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<13;j++)
			std::cout<<'*';
		std::cout<<std::endl;
	}
}