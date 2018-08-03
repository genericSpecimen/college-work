#include<iostream>
int main()
{
	for(int i =0;i<9;i++)
	{
		for(int j=0;j<9-i;j++)
			std::cout<<j+1<<' ';
		std::cout<<std::endl;		
	}
	return 0;
}