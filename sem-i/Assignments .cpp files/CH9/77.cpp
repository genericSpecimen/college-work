#include<iostream>
int main()
{
	char a[6] = {'z','x','m','s','e','h'};
	int temp,i;
  	temp = a[0];
  	for (i = 0; i < 6-1; i++)
     	a[i] = a[i+1];
  	a[i] = temp;
  	for(int i=0;i<6;i++)
  	std::cout << a[i] << ' ';	
}