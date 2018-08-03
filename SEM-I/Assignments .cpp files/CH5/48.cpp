#include<iostream>
void day_of_week(int num)
{
	switch(num)
	{
		case 0:std::cout<<"\nCorresponding day: Sunday";
		       break;
		case 1:std::cout<<"\nCorresponding day: Monday";
		       break;
		case 2:std::cout<<"\nCorresponding day: Tuesday";
		       break;
		case 3:std::cout<<"\nCorresponding day: Wednesday";
		       break;
		case 4:std::cout<<"\nCorresponding day: Thursday";
		       break;
		case 5:std::cout<<"\nCorresponding day: Friday";
		       break;
		case 6:std::cout<<"\nCorresponding day: Saturday";
		       break;                                   
	}
}
int main()
{
	int num;
	std::cout<<"\nEnter a number between 0-6\n";
	std::cin>>num;
	day_of_week(num);
	return 0;
}