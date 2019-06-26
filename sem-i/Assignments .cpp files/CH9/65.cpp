#include<iostream>
bool time(int* tSeconds)
{
	if(*tSeconds > 86400)
		return false;
	else
	{
		int hours, minutes;
		minutes = *tSeconds / 60;
		hours = minutes / 60;
		std::cout << "The time is: " << hours << ':' << minutes%60 << ':' << (*tSeconds)%60;
		if(hours < 12)
			std::cout << " A.M.\n";
		else
			std::cout << " P.M.\n";
	}
	return true;
}

int main()
{
	int seconds;
	std::cout << "\nEnter number of seconds: ";
	std::cin >> seconds;
	std::cout << time(&seconds);
}