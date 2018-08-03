#include<iostream>
int check(int* a, int* b,int* n) 
{
	for(int i=0;i<*n;i++)
	{
		if(a[i] != b[i])
			return 0;
	}
	return 1;
}

int main()
{
	int A[] = {1,2,3,4,5,6,7,8,9,10};
	int B[] = {1,2,3,4,5,4,7,8,9,10};
	int n;
	std::cout << "\nEnter the number of elements to be compared: ";
	std::cin >> n;
	std::cout <<check(A, B, &n) << '\n' ; 
}