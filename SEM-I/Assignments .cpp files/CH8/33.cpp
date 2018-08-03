#include<iostream>
#include<iomanip>
//copy a 1D array of 20 elements to a 5*4 2D array 
void copy(int a[], int b[][4])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			b[i][j] = a[i*4 + j];
		}
	}
}

int main()
{
	int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int b[5][4];
	copy(a,b);
	std::cout << "\nContents of 2D array after copying\n";
	std::cout << std::setfill('0');
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
			std::cout << std::setw(2) << b[i][j] << ' ';
		std::cout << std::endl;
	}
}