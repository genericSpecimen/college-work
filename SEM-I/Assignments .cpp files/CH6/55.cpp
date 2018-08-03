#include<iostream>
#include<iomanip>
int year;
int calculateDayOfweek(int);
void printMonth(int);
void printDay(int);
int numberOfdays(int);
int main()
{
	char ans = 'y';
	do
	{
		std::cout<<"\nEnter a year to print calendar of that year\n";
	    std::cin >> year;
	    int day = calculateDayOfweek(year);
	    std::cout<<"\nDay on 1st January "<<year<<" is ";
	    printDay(day);
	    std::cout<<'\n';
	    for(int i=0;i<12;i++)
	    {
	    	printMonth(i);
	    	std::cout <<std::setw(20) << year <<'\n';
	    	int k = 0;
	    	for(int j=0;j<7;j++)
	    		{
	    			printDay(k);
	    			std::cout <<' ';
	    			k++;
	    		}
	    	std::cout<<'\n';	
	    	for(int space=0;space<day;space++)
	    	{
	    		std::cout<<"    ";
	    	}
            int noOfDays = numberOfdays(i);
            for(int dates = 1;dates <= noOfDays; dates++)
            {
            	std::cout<<dates<<std::setw(4);
            	if((day + dates) % 7 == 0)
            		std::cout<<'\n';
            }
	    	std::cout<<'\n'<<'\n';
	    	day = (day + noOfDays)%7;
	    }
	    std::cout<<"\nDo you want to view calendar for another year? (y/n)\n";
	    std::cin>>ans;
	} while(ans == 'y' || ans == 'Y');
}


int calculateDayOfweek(int year)
{
	int day1jan = ( (year - 1) * 365 + ((year - 1)/4) - ((year - 1)/100) + ((year - 1)/400) + 1 ) % 7;
	return day1jan;
}

void printDay(int day)
{
	switch(day)
	{
		case 0 : std::cout<<"Sun";
		         break;
		case 1 : std::cout<<"Mon";
		         break;
		case 2 : std::cout<<"Tue";
		         break;
		case 3 : std::cout<<"Wed";
		         break;
		case 4 : std::cout<<"Thu";
		         break;
        case 5 : std::cout<<"Fri";
	             break;
        case 6 : std::cout<<"Sat";
		         break;
	}
}

void printMonth(int month)
{
	switch(month)
	{
		case 0 : std::cout << "January";
		         break;
		case 1 : std::cout << "February";
		         break;  
		case 2 : std::cout << "March";
		         break;
		case 3 : std::cout << "April";
		         break;
		case 4 : std::cout << "May";
		         break;
		case 5 : std::cout << "June";
		         break;
		case 6 : std::cout << "July";
		         break;
		case 7 : std::cout << "August";
		         break;
		case 8 : std::cout << "September";
		         break;
		case 9 : std::cout << "October";
		         break;
		case 10 : std::cout << "November";
		         break;
		case 11 : std::cout << "December";
		         break;                                                                                                 
	}
}

int numberOfdays(int month)
{
	switch(month)
	{
		case 0 : return 31;
		         break;
		case 1 : if( (!(year % 4) && (year % 100)) || !(year % 400) ) 
		            return 29;
		         else
		            return 28;   
		         break;  
		case 2 : return 31; 
		         break;
		case 3 : return 30;
		         break;
		case 4 : return 31;
		         break;
		case 5 : return 30;
		         break;
		case 6 : return 31;
		         break;
		case 7 : return 31;
		         break;
		case 8 : return 30;
		         break;
		case 9 : return 31;
		         break;
		case 10 :return 30;
		         break;
		case 11 :return 31;
		         break;
	}           
}