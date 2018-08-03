#include<iostream>
int main()
{
	short int code;
	const float salesTax = 0.0825;
	double sum = 0;
	std::cout<<sizeof(code)<<' '<<sizeof(salesTax)<<' '<<sizeof(sum)<<std::endl;
	std::cout<<salesTax;
}