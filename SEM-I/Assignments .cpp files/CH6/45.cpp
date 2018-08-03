#include<iostream>
int main()
{
	float sum =0;
	int i=0,avg=0,num,min,max;
	std::cout<<"\nEnter numbers until you acheive satisfaction\n";
	std::cin>>min;
	std::cin>>max;
	while(std::cin>>num)
	{
		if(num>max)
			max=num;
		if(num<min)
			min=num;
		sum+=num;
			i++;
	}
	std::cout<<"\nMinimum: "<<min;
	std::cout<<"\nMaximum: "<<max;
	std::cout<<"\nAverage: "<<sum/(float)i;
}