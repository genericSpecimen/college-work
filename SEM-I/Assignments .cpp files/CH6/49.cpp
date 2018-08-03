#include<iostream>
int main()
{
	int num,smallest;
	std::cin>>smallest;
	while(std::cin>>num)
	{
		if(num<smallest)
			smallest=num;
	}
	std::cout<<"\nSmallest number is: "<<smallest;
}