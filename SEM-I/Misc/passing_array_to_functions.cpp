//passing array in functions
#include<iostream>
void printArray(double array[], int size); 
int main()
{
	double rainfall[5] = {0.1,0.2,0.3,0.4,0.5};
	
	printArray(rainfall,5); //function call, just specify the name, not the square brackets
	std::cout<<"\nEnter 5 rainfall amounts\n";
	for(int i = 0; i < 5; i++)
	{
		std::cin>>rainfall[i];
	}
	
	printArray(rainfall,5);
}

void printArray(double array[], int size) // we aren't passing the whole array but only the pointer to the first element of the array
{
	for(int i = 0; i < size; i++)
	{
		std::cout<<array[i]<<std::endl;
	}
}

