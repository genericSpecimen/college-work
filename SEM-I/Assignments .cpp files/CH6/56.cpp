#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
double pr,iy,ny,nm,im,p,q,mp;
void calculateMonthlyPayment();
void printInformation();
void printAmortizationTable();

int main()
{
	std::cout << "\nEnter the loan amount (principal).\n";
	std::cin >> pr;
	std::cout << "\nEnter the interest per year (percent).\n";
	std::cin >> iy;
	std::cout << "\nEnter number of years.\n";
	std::cin >> ny;
	calculateMonthlyPayment();
	printInformation();
	printAmortizationTable();
}

void calculateMonthlyPayment()
{
	nm = ny * 12;
	im = (iy / 12)/100;
	p = pow((1 + im),nm);
	q = p/(p - 1);
	mp = (pr * im * q);
}

void printInformation()
{
	std::cout << "\nThe amount of the loan (principal): " << pr;
	std::cout << "\nThe interest rate per year (percent): " << iy;
	std::cout << "\nThe interest rate per month (decimal): " << im;
	std::cout << "\nNumber of years: " << ny;
	std::cout << "\nNumber of months: " << nm;
	std::cout << "\nMonthly payment: " << std::setprecision(5) << mp;
}

void printAmortizationTable()
{
	double oldbalance = pr, newbalance = pr;
	std::cout<<"\nMonth"<<std::setw(20)<<"Old Balance"<<std::setw(20)<<"Monthly Payment"<<std::setw(20)<<"Interest Paid"<<std::setw(20)<<"Principal paid"<<std::setw(20)<<"New Balance"<<'\n';
	for(int i=1;i <= nm-1;i++)
	{
		double interest = newbalance * im;
		newbalance = (pow((1+im),i))*pr - ( ((pow((1+im),i) - 1)*mp)/im );
		std::cout<<i<<std::setw(20)<<oldbalance<<std::setw(20)<<mp<<std::setw(20)<<interest<<std::setw(20)<<(mp - interest)<<std::setw(20)<<newbalance<<'\n';
		oldbalance = newbalance;		
	}
	std::cout<<ny*12<<std::setw(20)<<oldbalance<<std::setw(20)<<oldbalance*im + oldbalance<<std::setw(20)<<oldbalance*im<<std::setw(20)<<oldbalance<<std::setw(20)<<newbalance- oldbalance<<'\n';
	std::cout<<"\nTotal amount paid: "<<(nm-1)*mp + oldbalance*im + oldbalance;
}