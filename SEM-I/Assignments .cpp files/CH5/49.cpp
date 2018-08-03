#include<iostream>
void month_of_year(int num)
{
	switch(num)
	{
		case 1:std::cout<<"\nCorresponding month: January";
		       break;
		case 2:std::cout<<"\nCorresponding month: February";
		       break;
		case 3:std::cout<<"\nCorresponding month: March";
		       break;
		case 4:std::cout<<"\nCorresponding month: April";
		       break;
		case 5:std::cout<<"\nCorresponding month: May";
		       break;
		case 6:std::cout<<"\nCorresponding month: June";
		       break;
		case 7:std::cout<<"\nCorresponding month: July";
		       break;
		case 8:std::cout<<"\nCorresponding month: August";
		       break;
		case 9:std::cout<<"\nCorresponding month: September";
		       break;
		case 10:std::cout<<"\nCorresponding month: October";
		       break;
		case 11:std::cout<<"\nCorresponding month: November";
		       break;
		case 12:std::cout<<"\nCorresponding month: December";
		       break;
	}
}
int main()
{
	int num;
	std::cout<<"\nEnter a number between 1-12\n";
	std::cin>>num;
	month_of_year(num);
	return 0;
}