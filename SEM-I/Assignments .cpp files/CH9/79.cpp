#include<iostream>
int main()
{
	int a;
	int*p = &a;
	int** q = &p; int** r = &p; 
	int*** s = &q; int*** t = &q;   
	int*** u = &r; int*** v = &r;
	std::cout << "\nEnter an integer: ";
	std::cin >> a;

	std::cout << "\nVALUES OF A";
	std::cout << "\nUsing pointer p: " << *p << std::endl;  
	std::cout << "\nUsing pointer q: " << **q << std::endl;  
	std::cout << "\nUsing pointer r: " << **r << std::endl;  
	std::cout << "\nUsing pointer s: " << ***s << std::endl;  
	std::cout << "\nUsing pointer t: " << ***t << std::endl;  
	std::cout << "\nUsing pointer u: " << ***u << std::endl;  
	std::cout << "\nUsing pointer v: " << ***v << std::endl;  
}