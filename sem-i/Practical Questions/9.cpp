#include<iostream>
int main()
{
	int numLines;
	std::cout << "\nEnter number of lines: ";
	std::cin >> numLines;
	for(int i=0;i<numLines;i++)
	{
		for(int space=0;space<numLines - i;space++)
			std::cout << ' ';
		for(int j=0;j<2*i+1;j++)
			std::cout << '*';
		std::cout << std::endl;
	}
}