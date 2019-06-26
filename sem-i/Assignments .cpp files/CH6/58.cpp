#include<iostream>
#include<iomanip>
void CtoF()
{
	std::cout<<"Celsius"<<std::setw(50)<<"Fahrenheit\n";
	for(int i=0;i<=100;i++)
	{
		std::cout<<i<<std::setw(50)<<(32 + (i*1.8))<<'\n';
	}
}

void FtoC()
{
	std::cout<<"Fahrenheit"<<std::setw(45)<<"Celsius\n";
	for(int i=32;i<=212;i++)
	{
		std::cout<<i<<std::setw(50)<<(i - 32)/1.8<<'\n';
	}
}
int main()
{
	CtoF();
	std::cout<<'\n'<<'\n';
	FtoC();
}