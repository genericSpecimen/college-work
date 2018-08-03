//pointers to pointers
#include<iostream>
int main()
{
	int a = 2;
	int* p2a = &a;
	int** p2p2a = &p2a;
	std::cout << **p2p2a << std::endl;

	char A = 'a';
	char* p2A = &A;
	std::cout << p2a << std::endl;
	std::cout << static_cast<void *>(p2A) << std::endl;

}