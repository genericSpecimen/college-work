//random numbers
// x+(rand()%(y-x+1));
#include<iostream>
#include<cstdlib>
#include<ctime>
int main()
{
	srand(time(0));
	for(int i =0;i<49;i++)
		std::cout<<1+(rand()%20)<<std::endl;
}