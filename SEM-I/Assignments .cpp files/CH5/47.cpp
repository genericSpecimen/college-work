#include<iostream>
int smallest(int num1,int num2,int num3)
{
	int small= num1;
	if(num1<num2 && num1<num3)
		small=num1;
	else if(num2<num3)
		small=num2;
	else
		small=num3;
	return small;
}
int main()
{
	int n1,n2,n3;
	std::cout<<"\nEnter three numbers to find out the smallest of them\n";
	std::cin>>n1>>n2>>n3;
	int small = smallest(n1,n2,n3);
	std::cout<<"\nSmallest number: "<<small;
	return 0;
}