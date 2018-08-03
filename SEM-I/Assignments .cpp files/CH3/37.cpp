#include<iostream>
int main()
{
	int fib1=0,fib2=1,fib3;
	fib3=fib2+fib1;
	std::cout<<std::endl<<fib1<<", "<<fib2<<", "<<fib3;
	fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;
    fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;
    fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;
    fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;
    fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;
    fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;
    fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;
    fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;
    fib1=fib2;
	fib2=fib3;
    fib3=fib2+fib1;
    std::cout<<", "<<fib3;

}