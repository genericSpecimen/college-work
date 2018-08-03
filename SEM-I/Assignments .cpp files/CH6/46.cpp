#include<iostream>
int readpositiveint(int a)
{
	do
	{
		if (a<0 || (a%2!=0))
		   return 1;
		else
		   return a;
	} while(a<0 || (a%2!=0));	
}

int main()
{
	int a;
	std::cout<<"\nEnter a positive even integer\n";
	while(std::cin>>a)
	{
		int valid = readpositiveint(a);
        if(valid == 1)
        	{
        		std::cout<<"\nEnter a valid number\n";
                continue;
            }
        else
        std::cout<<' '<<valid;    
    }
    return 0;
}