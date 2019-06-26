#include<iostream>
float function()
{
	int num,sum=0,i=0;
	float avg;
	while(std::cin>>num)
	{
		if(num<0)
			{
				return -5;
				break;
			}
		else
		{
			sum+=num;
			i++;
		}
	}
	if(!(num<0))
		{
			avg = (float) sum/i;
	        return avg;
	    }    
}

int main()
{
	std::cout<<"\nEnter as many numbers as you like\n";
	float result = function();
	std::cout<<result;
	if(result=-5)
		std::cout<<"\nYou entered a negative number which is why output is a random negative number\n";
}