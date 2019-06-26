#include<iostream>
int main()
{
	int num,sum=0;
	std::cout<<"\nEnter numbers to add them until you acheive satisfaction\n";
	while(std::cin>>num)
	{
		sum+=num;
		std::cout<<"Total: "<<sum<<std::endl;
	}


}