#include<iostream>
void sumUsingMalloc(int n)
{
	int sum = 0;
	int* ptr = (int*) malloc(n*sizeof(int));
	if(!ptr)
		std::cout << "\nAllocation failed\n";
	std::cout << "\nEnter "<<n<< " numbers\n";
	for(int i=0;i<n;i++)
		{
			std::cin >> *(ptr + i);
			sum += *(ptr + i);
		}
	std::cout << "\nSum: "<<sum;	
}

void sumUsingCalloc(int n)
{
	int sum=0;
	int * ptr = (int*) calloc(n,sizeof(int));
	if(!ptr)
		std::cout << "\nAllocation failed\n";
	std::cout << "\nEnter "<<n<< " numbers\n";
	for(int i=0;i<n;i++)
	{
		std::cin >> *(ptr + i);
		sum += *(ptr + i);
	}
	std::cout << "\nSum: "<<sum;
}

void sumUsingNew(int n)
{
	int sum = 0;
	int* ptr = new int[n];
	if(!ptr)
		std::cout << "\nAllocation failed\n";
	std::cout << "\nEnter "<<n<< " numbers\n";
	for(int i=0;i<n;i++)
	{
		std::cin >> *(ptr + i);
		sum += *(ptr + i);
	}
	std::cout << "\nSum: "<< sum;
	delete[] ptr;
}

int main()
{
	int n,option;
	std::cout << "\nEnter number of elements you want to add: ";
	std::cin >> n;
	std::cout << "\nWhich function do you want to use to add "<<n<<" numbers? Choose from option 1-3\n";
	std::cout <<"\n1.Using malloc()\n2.Using calloc()\n3.Using new operator\n";
	std::cin >> option;
	switch(option)
	{
		case 1:sumUsingMalloc(n);break;
		case 2:sumUsingCalloc(n);break;
		case 3:sumUsingNew(n);break;
		default: std::cout << "\nInvalid option.\n";
	}
}

