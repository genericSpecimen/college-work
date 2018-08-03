#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int input, sum = 0;
	std::vector<int> v;
	std::cout<<"\nEnter numbers you want to add separated by space or by pressing enter and enter 0 to display sum\n";
	while(std::cin>>input && input!=0)
		v.push_back(input);
	for(int i=0;i<v.size();i++)
		sum+=v[i];
	std::cout<<"\nSum = "<<sum;
	return 0;
}