#include<iostream>
#include<cmath>
#include<iomanip>
double interestQuarterly(double oldbalance,double t)
{
	double interest,newbalance=oldbalance;
	interest = oldbalance*pow((1+(0.053/4)),4*t) - oldbalance;
	newbalance = oldbalance + interest;
	std::cout<<4*t<<std::setw(20)<<oldbalance<<std::setw(30)<<interest<<std::setw(20)<<newbalance<<'\n'; 
}
int main()
{
	double oldbalance;
	std::cout<<"\nEnter current bank balance\n";
	std::cin>>oldbalance;
	std::cout<<"\nQuarter"<<std::setw(20)<<"Old Balance"<<std::setw(30)<<"Interest at end of quarter"<<std::setw(20)<<"New Balance\n";
	for(double i=1;i<=4;i++)
	    interestQuarterly(oldbalance,(i/4));

	//std::cout<<"\nInterest at the end of one year: "<<interestQuarterly(oldbalance,1);
	//std::cout<<"\nBalance at the end of one year: "<<interestQuarterly(oldbalance,1) + oldbalance;
}