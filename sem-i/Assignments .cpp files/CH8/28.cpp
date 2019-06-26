#include<iostream>
bool check(int a[], int b[])
{
	int flag = 0;
	for(int i=0;i<10;i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[10] = {1,2,4,4,5,6,7,8,9,10};
	if(check(a,b))
		std::cout << "\nEQUAL\n";
	else
		std::cout << "\nNOT EQUAL\n";
}