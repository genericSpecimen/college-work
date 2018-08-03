#include<iostream>
#include<iomanip>
int main()
{
	int matrix[6][6];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(i+j < 5)
				matrix[i][j] = 1;
			else if(i+j == 5)
				matrix[i][j] = 0;
			else if(i+j > 5)
				matrix[i][j] = -1;
		}
	}
	std::cout << "\nThe filled array is\n";
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
			std::cout << std::setw(2) << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
}