#include<iostream>
int main()
{
	char a[6] = {'z','x','m','s','e','h'};
	int temp,i;
  	temp = a[5];
  	for (i = 5; i > 0; i--)
     	a[i] = a[i-1];
  	a[0] = temp;
  	for(int i=0;i<6;i++)
  	std::cout << a[i] << ' ';	
}
