#include<iostream>
int main()
{
	int i;
	int list[10] = {2,1,2,4,1,2,0,2,1,2};
	int line[10];
	for(i=0;i<10;i++)
		line[i] = list[9-i];
	for(i=0;i<10;i++)
		std::cout << line[i] << " ";
} 