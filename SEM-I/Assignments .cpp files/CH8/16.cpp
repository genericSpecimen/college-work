#include<iostream>
int main()
{
	int list[10] = {0};
	for(int i=0;i<5;i++)
		list[2*i + 1] = i + 2;
	for(int i=0;i<10;i++)
		std::cout << list[i] << std::endl;
}