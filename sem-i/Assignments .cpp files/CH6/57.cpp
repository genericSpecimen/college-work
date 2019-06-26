#include<iostream>
int main()
{
	int num,num1,numcount = 0,smallest,largest,flag20 = 0,flag20count = 0,flag10to90 = 0,flag10to90count = 0;
	float sum = 0;
	std::cout<<"\nEnter as many integers as you want. Enter 99999 to stop.\n";
	std::cin>>num1;
	smallest = num1;
	largest = num1;
	sum += num1;
	numcount++;
	if(num1 < 20)
	{
		flag20 = 1;
		flag20count++;
	}
	if(num1 > 10 && num1 < 90)
	{
		flag10to90 = 1;
		flag10to90count++;
	}

	do
	{
		std::cin>>num;
		if(num == 99999)
			break;
		if(num < smallest)
			smallest = num;
		if(num > largest)
			largest = num;
		sum += num;
		if(num < 20)
		{
			flag20 = 1;
			flag20count++;
		}
		if(num > 10 && num < 90)
		{
			flag10to90 = 1;
			flag10to90count++;
		}
		numcount++;    	
	} while(num != 99999);

	std::cout<<"\nNumber of integers: "<<numcount;
	std::cout<<"\nSum of integers: "<<sum;
	std::cout<<"\nAverage of integers: "<<sum/numcount;
	std::cout<<"\nSmallest integer: "<<smallest;
	std::cout<<"\nLargest integer: "<<largest;
	std::cout<<"\nNumber(s) < 20: ";
	if(flag20count > 0)
		std::cout<<"true";
	else
		std::cout<<"false";
	std::cout<<"\nAll in range: ";
	if(flag10to90count == numcount)
		std::cout<<"true";
	else
		std::cout<<"false";
}