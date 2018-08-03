//display day of the week a person was born using date of birth
#include<iostream>
int dd,mm,yyyy;
void input();
int calculateDayOfweek();
void output(int);
int main()
{
	std::cout<<"\nEnter your birth date in the following format dd mm yyyy\n";
	input();
	int day = calculateDayOfweek();
	std::cout<<"\nDay = "<<day;
	output(day); 
}

void input()
{
	std::cin>>dd>>mm>>yyyy;
}
int calculateDayOfweek()
{
	int day31dec,daycount;
	day31dec = (((yyyy - 1) * 365 + ((yyyy - 1)/4) - ((yyyy - 1)/100) + ((yyyy - 1)/400))) % 7;
	std::cout<<"\nDay on 31st december of the previous year: "<<day31dec;
	switch(mm)
	{
		case 12 : daycount += 30;
		case 11 : daycount += 31;
		case 10 : daycount += 30;
		case 9 : daycount += 31;
		case 8 : daycount += 31;
		case 7 : daycount += 30;
		case 6 : daycount += 31;
		case 5 : daycount += 30;
		case 4 : daycount += 31;
		case 3 : if( (!(yyyy % 4) && (yyyy % 100)) || !(yyyy % 400) )
		            daycount += 29;
		         else
		            daycount += 28;

		case 2 : daycount += 31;
	}
	daycount += dd;
	daycount += day31dec;
	return (daycount % 7); 
}

void output(int daycount)
{
	std::cout<<"\nDay of the week on which you were born\n";
	switch(daycount)
	{
		case 0 : std::cout<<"Sunday";
		         break;
		case 1 : std::cout<<"Monday";
		         break;
		case 2 : std::cout<<"Tuesday";
		         break;
		case 3 : std::cout<<"Wednesday";
		         break;
		case 4 : std::cout<<"Thursday";
		         break;
		case 5 : std::cout<<"Friday";
		         break;
		case 6 : std::cout<<"Saturday";
		         break; 
		default : std::cout<<"what";                                                              
	}
}

