#include<iostream>
int main()
{
	int num;
	do
	{
		//std::cin>>num;    not needed as this is already the condition of do while loop
		std::cout<<' '<<num<<std::endl;
	} while(std::cin>>num);
}