#include<iostream>
#include<vector>
#include<string>
int convertJtoG(int* date, int* month, int* jyear, int* jdate)
{
	if(*jdate <0 || *jdate > 366)
		return 0;
	else
	{
		std::vector<std::string> months {"January","February","March","April","May","June","July","August","September","October","November","December"};
		*date = *jdate;
		const static int days_in_month [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int leap = ( *jyear % 400 == 0 || *jyear % 100 != 0) &&( *jyear % 4 == 0); //leap = 1 if it's a leap year
		for(*month = 0; *month<12; ++(*month))
		{
			int mlen = days_in_month[*month];
			if(leap == 1 && *month == 1)  //'1' is for the month of february
				mlen ++;
			if(*date < mlen)
				break;
			*date -= mlen;
		}
		std::cout << "\nMONTH: " << months[*month];
		std::cout << "\nDATE: " << *date;
		return 1;
	}
}

int main()
{
	int gdate, gmonth, jyear, jdate;
	std::cout << "\nEnter a Julian date (date and year) to convert it into a Gregorian date and month: ";
	std::cin >> jdate >> jyear;
	std::cout << std::endl << convertJtoG(&gdate, &gmonth, &jyear, &jdate);
	std::cout << "\nA positive number indicates no error in parameters";
	std::cout << "\nA zero value indicates you have entered an incorrect julian date. A julian date must be greater than 0 and less than 366.\n";
}
