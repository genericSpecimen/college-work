#include<iostream>
//void pascal(int size)
//{

//}

int main()
{
	int n;
	std::cout << "\nEnter the size of the pascal triangle to be printed: ";
	std::cin >> n;
	int* ptr = new int[n*n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			if(j ==0 || j == i)
				//*(ptr + i*n + j) = 1; //these two statements are identical
				ptr[i*n + j] = 1;
			else
				//*(ptr + i*n + j) = *(ptr + (i-1)*n + j-1) + *(ptr + (i-1)*n + j);
				ptr[i*n + j] = ptr[(i-1)*n + (j-1)] + ptr[(i-1)*n + j];
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			std::cout << ptr[i*n + j] << ' ';
		std::cout << std::endl;
	}
	delete[] ptr; 
}