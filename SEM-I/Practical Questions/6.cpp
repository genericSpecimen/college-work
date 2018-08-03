#include<iostream>
bool isprime(int num)
{
	int flag = 1;
	if(num == 1 || num == 2)
		return false;
	if(num == 3 )
		return true;
	if(num == 4)
		return false;
	for(int i=2;i<(num/2);i++)
	{
		if(num%i==0)
			flag=0;
	}
	if(flag==0)
		return false; 
	else
		return true;
}
int main()
{
	std::cout<<"Prime numbers from 1 to 100\n";
	for(int i =1;i<=100;i++)
	{
		bool result = isprime(i);
		if(result == true)
			std::cout<<i<<',';
	}
	std::cout<<'\n';
}