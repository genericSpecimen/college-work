#include<iostream>
#include<math.h>
int reverse(int num, int len)
{
	if(len == 1)
		return num;
	else
		return ((num%10) * pow(10,len-1) + reverse(num/10,--len));
}
int main()
{
	int num, len=0;
	std::cout<<"\nEnter an integer to reverse it\n";
	std::cin>>num;
	int temp = num;
	while(temp>0)
	{
		len++;
		temp/=10;
	}
	int reversednumber = reverse(num,len);
	std::cout<<"\nReversed number is: "<<reversednumber;
}