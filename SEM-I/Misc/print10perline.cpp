//program that prints numbers 10 per line

#include<iostream>

/*
int main()
{
	for(int i=0;i<50;i++)                         //using for loop
	{
		for(int j=0;j<10;j++)
			{
				std::cout<<' '<<i+1;
				i++;
			}
		i--;
		std::cout<<std::endl;	
	}
}
*/

/*
int main()
{
	for(int i = 1;i<=50;i++)
	{
		std::cout<<' '<<i;
		if(i%10==0)
			std::cout<<std::endl;
	}
}
*/

/*int main()
{
	int i = 1;
	while(i<=50)
	{
		std::cout<<i<<' ';                      //using while loop
		if(i%10 == 0)
			std::cout<<std::endl;
		i++;
	}
}
*/
int main()
{
	int i = 1;
	do
	{
		std::cout<<i<<' ';                      //using do - while loop
		if(i%10 == 0)
			std::cout<<std::endl;
		i++;
	}while(i<=50);
}