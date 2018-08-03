#include<iostream>
#include<vector>
void mergeUsingNew()
{
	int size1,size2;
	std::cout << "\nEnter the size of first array: ";
	std::cin >> size1;
	int* ptrarray1 = new int[size1]; 
	std::cout << "\nEnter the values of first array in ascending order\n";
	for(int i=0;i<size1;i++)
		std::cin >> *(ptrarray1 + i);

	std::cout << "\nEnter the size of second array: ";
	std::cin >> size2;
	int* ptrarray2 = new int[size2]; 
	std::cout << "\nEnter the values of second array in ascending order\n";
	for(int i=0;i<size2;i++)
		std::cin >> *(ptrarray2 + i);

	int i=0,j=0,k=0;
	int* ptrarray3 = new int[size1+size2];

	while(i<size1 && j<size2)
	{
		if(*(ptrarray1 + i) < *(ptrarray2 + j))
		    *(ptrarray3 + k++) = *(ptrarray1 + i++);
		else
			*(ptrarray3 + k++) = *(ptrarray2 + j++);
	}
	while(i<size1)
		*(ptrarray3 + k++) = *(ptrarray1 + i++);
	while(j<size2)
		*(ptrarray3 + k++) = *(ptrarray2 + j++);

	std::cout << "\nMerged array is\n";
	for(int num=0;num<size1+size2;num++)
		std::cout << *(ptrarray3 + num) <<',';
	delete[] ptrarray1; 
	delete[] ptrarray2; 
	delete[] ptrarray3; 
}

void mergeUsingVector()
{
	int size1,size2;
	std::cout << "\nEnter size of first array: ";
	std::cin >> size1;
	std::vector<int> v1(size1);

	std::cout << "\nEnter elements of first array in ascending order\n";
	for(int i=0;i<size1;i++)
		std::cin >> v1[i];

	std::cout << "\nEnter size of second array: ";
	std::cin >> size2;
	std::vector<int> v2(size2);

	std::cout << "\nEnter elements of second array in ascending order\n";
	for(int i=0;i<size2;i++)
		std::cin >> v2[i];

	std::vector<int> v3(size1 + size2);
	int i=0,j=0,k=0;
	while(i<size1 && j<size2)
	{
		if(v1[i] < v2[j])
		    v3[k++] = v1[i++];
		else
			v3[k++] = v2[j++];
	}
	while(i<size1)
		v3[k++] = v1[i++];
	while(j<size2)
		v3[k++] = v2[j++];

	std::cout << "\nMerged array is\n";
	for(int num=0;num<size1+size2;num++)
		std::cout << v3[num] << ',';
}
int main()
{
	int option;
	std::cout << "\nHow do you want to merge two arrays? Choose from 1 and 2\n";
	std::cout << "1.Dynamic memory allocation using new operator\n2.Using vectors\n";
	std::cout << "\nEnter your option\n";
	std::cin >> option;
	if(option == 1)
		mergeUsingNew();
	else if(option == 2)
		mergeUsingVector();
	else
		std::cout << "\nInvalid option\n";
}
