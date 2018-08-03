#include<iostream>
using namespace std;
//program to demonstrate the use of namespaces
/*
int main()
{
	int value;
	value = 0;
	double value; //error : In each scope, a name can only represent one entity. 
	value = 0.0             //So, there cannot be two variables with the same name in the same scope.
	//Using namespaces, we can create two variables or member functions having the same name.
}
*/

//using namespaces
/*
int val = 100;                    // global variable
namespace first
{
	int val = 500;
}
int main()
{
	int val = 200;
	cout<<val<<'\n';  //200
	cout<<val<<'\n';  //200
	cout<<first::val; //500 
	return 0;
}
*/


namespace ns1
{
	int value()
	{return 5;}
}
namespace ns2
{
	const double x = 100;
	double value()
	{return (2*x);}
}

int main()
{
	std::cout<<ns1::value()<<std::endl;
	std::cout<<ns2::value()<<std::endl;
	std::cout<<ns2::x<<std::endl;
	return 0;
}	 