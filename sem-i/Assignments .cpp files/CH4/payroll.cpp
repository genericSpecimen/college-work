#include<iostream>
void payroll(double salesmade,double bonus)
{
	double salary = 0.125*salesmade + bonus;
	double fedWithholding = 0.25*salary, stateWithholding = 0.10*salary, retirement = 0.08*salary;
	double netsalary = salary - fedWithholding - stateWithholding - retirement;
	std::cout<<"\nPayroll earnings statement\n";
	std::cout<<"\nSales: "<<salesmade;
	std::cout<<"\nBonus: "<<bonus;
	std::cout<<"\nSales commission: "<< 0.125*salesmade;
	std::cout<<"\nFederal Withholding: "<<fedWithholding;
	std::cout<<"\nState Withholding: "<<stateWithholding;
	std::cout<<"\nRetirement plan: "<<retirement;
	std::cout<<"\nNet salary: "<<netsalary;
}

int main()
{
	double sales,bonus;
	std::cout<<"\nEnter the sales made by employee\n";
	std::cin>>sales;
	std::cout<<"\nEnter the bonus rewarded\n";
	std::cin>>bonus;
	payroll(sales,bonus);
	return 0;
}