#include<iostream>
#include<iomanip>
#include<cstdlib>
int option,size;
void getOption();
void getSize();
void pattern1(int);
void pattern2(int);
void pattern3(int);
void pattern4(int);

int main()
{
	std::cout<<std::setw(10);
	std::cout<<"MENU";
	std::cout<<"\n1. Pattern 1\n2. Pattern 2\n3. Pattern 3\n4. Pattern 4\n5. EXIT";
	std::cout<<"\nEnter option.\n";
	getOption();
	if(option == 5)
		exit(0);
	std::cout<<"\nEnter pattern size (2 to 9).\n";
	getSize();
	switch(option)
	{
		case 1 : pattern1(size);
		         break;
		case 2 : pattern2(size);
		         break;
		case 3 : pattern3(size);
		         break;
		case 4 : pattern4(size);
		         break;         
		default : std::cout<<"\nEnter valid option\n";              
	}
}

void getOption()
{
	std::cin >> option;
	if(option < 1 || option > 5)
	{
		std::cout<<"\nInvalid option. Enter option again\n";
		getOption();
	}
	else
		std::cout<<"\nYou have chosen option number: "<<option;
}

void getSize()
{
	std::cin >> size;
	if(size < 2 || size > 9)
	{
		std::cout<<"\nInvalid size. Enter size again\n";
		getSize();
	}
	else
		std::cout<<"\nYou have chosen size: "<<size<<'\n'; 
}

void pattern1(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(i == j)
				std::cout<<'5';
			else
				std::cout<<'$';
		}
		std::cout<<'\n';
	}
}

void pattern2(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=size-1;j>=0;j--)
		{
			if(i == j)
				std::cout<<'5';
			else
				std::cout<<'$';
		}
		std::cout<<'\n';
	}
}

void pattern3(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=size-i;j>0;j--)
			std::cout<<'$';
		for(int j=0;j<i;j++)
			std::cout<<'5';
		std::cout<<'\n';
	}
}

void pattern4(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<i;j++)
			std::cout<<'5';
		for(int j=size-i;j>0;j--)
			std::cout<<'$';
		std::cout<<'\n';
	}
}