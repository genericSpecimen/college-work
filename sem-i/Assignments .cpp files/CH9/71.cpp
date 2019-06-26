#include<iostream>
int** pascal(int n)
{
	int** p = new int* [n];
	for(int i=0;i<n;i++)
		p[i] = new int [i];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j ==0 || j == i)
				p[i][j] = 1;
			else
				p[i][j] = p[i-1][j-1] + p[i-1][j];
		}	
	}
	return p;
	for(int i=0;i<n;i++)
		delete[] p[i];
	delete[] p;
}
int main()
{
	int n;
	std::cout << "\nEnter size of pascal triangle to be created: ";
	std::cin >> n;
	int** pascalArray = pascal(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			std::cout << pascalArray[i][j] << ' ';
		std::cout << std::endl;
	}
}
