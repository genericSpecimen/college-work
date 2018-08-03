#include<iostream>
int age;
int calcage(int* dateyyyy1,int* dateyyyy2)
{
	age = *dateyyyy1 - *dateyyyy2;
	return age;
}
void inputdates()
{
	int datemm1,datemm2,datedd1,datedd2,dateyyyy1,dateyyyy2;
	std::cout<<"\nEnter current date in the following format: mm/dd/yyyy (without entering slashes, separate using spaces\n";
	std::cin>>datemm1>>datedd1>>dateyyyy1;
	std::cout<<"\nEnter your birth date in the following format: mm/dd/yyyy (without entering slashes, separate using spaces\n";
	std::cin>>datemm2>>datedd2>>dateyyyy2;
	if(datemm1<datemm2)
		--dateyyyy1;
	if(datemm1==datemm2)
	{
		if(datedd1<datedd2)
		--dateyyyy1;	
	}
	age = calcage(&dateyyyy1,&dateyyyy2);
	std::cout<<"\nYour age is: "<<age<<" years.";
}
void output()
{
	std::cout<<"\nYour age is: "<<age<<" years.";
}
int main()
{
	inputdates();
}