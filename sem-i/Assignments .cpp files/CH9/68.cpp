#include<iostream>
int check(int* a, int* b) 
{
	for(int i=0;i<10;i++)
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
	std::cout <<check(A, B) << '\n' ; 
}