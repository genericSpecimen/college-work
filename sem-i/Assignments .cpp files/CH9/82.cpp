#include<iostream>
void print(void * ptr)
{
	std::cout << "\nPrinting data at location: " << ptr;
	std::cout << "\nData as char: " << *(static_cast<char *> (ptr));
	std::cout << "\nData as int: " << *(static_cast<int *> (ptr)); 
	std::cout << "\nData as long: " << *(static_cast<long *> (ptr));
	std::cout << "\nData as float: " << *(static_cast<float *> (ptr));
}

int main()
{
	char c;
	int n;
	long int n1;
	float n2;
	std::cout << "\nEnter a character, an integer, a long integer and a float\n";
	std::cin >> c >> n >> n1 >> n2;             
    void *p = &c;
	print(p);
	p = &n;
	print(p);
	p = &n1;
	print(p);
	p = &n2;
	print(p); 
}