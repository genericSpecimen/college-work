#include<iostream>
int main()
{
	int num;
	std::cout<<"\nEnter a number between 0 and 32,767\n";
	std::cin>>num;

    std::cout<<(num/10000)%10<<"   "<<(num/1000)%10<<"   "<<(num/100)%10<<"   "<<(num/10)%10<<"   "<<num%10<<"   "<<std::endl;
    std::cout<<(num/1000)%10<<"   "<<(num/100)%10<<"   "<<(num/10)%10<<"   "<<num%10<<"   "<<std::endl;
    std::cout<<(num/100)%10<<"   "<<(num/10)%10<<"   "<<num%10<<"   "<<std::endl;
    std::cout<<(num/10)%10<<"   "<<num%10<<"   "<<std::endl;
    std::cout<<num%10<<"   "<<std::endl;
}