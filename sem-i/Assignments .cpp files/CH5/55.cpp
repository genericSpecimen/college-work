#include<iostream>
int enteringHour,enteringMin,leavingHour,leavingMin,timeHour,timeMin,actualtimehour;
float charge,totalcharges;
char type;
void output();
int timeSpent()
{
	//int actualtimehour;
	int changedleavingmin,changedleavinghour;
	if(leavingMin < enteringMin)
	{
		changedleavingmin = leavingMin + 60;
		changedleavinghour = leavingHour - 1;
	}
	else
	{
		changedleavingmin = leavingMin;
		changedleavinghour = leavingHour;
	}

	timeMin = changedleavingmin - enteringMin;
	timeHour = changedleavinghour - enteringHour;
	actualtimehour = timeHour;
	if(timeMin<=60 && timeMin>0)
		++actualtimehour;
	//std::cout<<"\nTotal time parked: "<<timeHour;
	return actualtimehour;
}
float calculateCharges(char type)
{
	int totalTime = timeSpent();
	switch(type)
	{
		case 'C': if(totalTime>3)
		            charge = (totalTime - 3)*1.5;
		          else
		          	charge = 0;
		          break;
		case 'T': if(totalTime>2)
		            charge = (2*1) + (totalTime - 2)*2.3;
		          else
		            charge = 1*totalTime;
		          break;
		case 'B': if(totalTime>1)
		            charge = (1*2) + (totalTime - 1)*3.7;
		          else
		            charge = 1*2;
		          break;
		default : std::cout<<"\nEnter valid vehicle type\n";		                                                 
	}
	return charge;
}
void input()
{
	//char type;
	//int enteringHour,enteringMin,leavingHour,leavingMin;
	std::cout<<"\nEnter type of vehicle.\n1. 'C' for Car\n2. 'B' for Bus\n3. 'T' for truck\n";
	std::cin>>type;
	std::cout<<"\nVehicle entered lot at hour? (0-24)\n";
	std::cin>>enteringHour;
	std::cout<<"\nVehicle entered lot at minute? (0-60)\n";
	std::cin>>enteringMin;
    std::cout<<"\nVehicle left lot at hour? (0-24)\n";
	std::cin>>leavingHour;
	std::cout<<"\nVehicle left lot at minute? (0-60)\n";
	std::cin>>leavingMin;
	totalcharges = calculateCharges(type);
	output();
}
void output()
{
	std::cout<<"\n     PARKING LOT CHARGE\n";
	std::cout<<"\nType of vehicle:       ";
	if(type == 'C')
		std::cout<<"Car\n";
	else if(type == 'B')
		std::cout<<"Bus\n";
	else if(type == 'T')
		std::cout<< "Truck\n";

	std::cout<<"TIME IN                  "<<enteringHour<<':'<<enteringMin;
	std::cout<<"\nTIME OUT                 "<<leavingHour<<':'<<leavingMin;
	std::cout<<"\n                       ----------";
	std::cout<<"\nPARKING TIME              "<<timeHour<<':'<<timeMin;
	std::cout<<"\nROUNDED TOTAL              "<<actualtimehour;
	std::cout<<"\n                       ----------          ";
	std::cout<<"\nTOTAL CHARGE             $"<<totalcharges;
}
int main()
{
	input();
}