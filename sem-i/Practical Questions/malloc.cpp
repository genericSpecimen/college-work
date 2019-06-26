#include<iostream>
//learning malloc (memory allocation) and calloc (contiguous allocation)
// and new operator
//malloc 
/*int main()
{
	int* ptr = (int*) malloc(sizeof(int));
	if(ptr == NULL)
		std::cout << "\nCould not allocate memory\n";
	else
		std::cout << "\nMemory allocated successfully\n";
	
	int n;
	std::cout << "\nEnter an integer\n";
	std::cin >> n;
	int* ptr = (int*) malloc(n*sizeof(int));
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		std::cout << "\nEnter element to be stored at: " <<ptr + i<<':';
		std::cin >> *(ptr + i);
		sum += *(ptr + i);
	}
	std::cout << "\nSum: "<< sum;
		
}*/

/*int main()
{}
	int n, sum =0;
	std::cout << "\nEnter an integer\n";
	std::cin >> n;
	int* ptr = (int*) calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		std::cout << "\nCurrent value at: "<<ptr+i<<':'<<*(ptr+i);
		std::cout << "\nEnter element to be stored at: "<<ptr+i<<':';
		std::cin >> *(ptr + i);
		sum += *(ptr + i);
	}
	std::cout << "\nSum: "<< sum;
}
*/

//new and delete
int main()
{
	int* ptr = new int(25) ; //intialised to 25
	if(!ptr)
		std::cout << "\nAllocation failed\n";
	else
		std::cout << "\nAllocation successful\n";
	//*ptr = 25;
	std :: cout << ptr << ' ' <<*ptr;
	delete ptr;
	//std :: cout << ptr << ' ' <<*ptr;

	int* ptrArray = new int[10];
	for(int i=0;i<10;i++)
		*(ptrArray + i) = i;

	for(int i=0;i<10;i++)
		std::cout <<"\nValue at address "<<(ptrArray + i)<<':'<<*(ptrArray + i);
	delete[] ptrArray;
}