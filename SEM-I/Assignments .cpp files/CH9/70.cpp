#include<iostream>
void reverse(int* a, int size)
{
	int temp;
	for(int i=0; i<size/2 ; i++)
	{
		temp = a[i];
		a[i] = a[size-1-i];
		a[size-1-i] = temp;
	}
	std::cout <<"\nThe reversed array is\n";
	for(int i=0;i<size;i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;	 
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(a)/sizeof(a[0]);
	reverse(a,size);
}