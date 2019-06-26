#include<iostream>
int main()
{
	int n;
	float sum = 0;
	std::cout<<"\nEnter an integer n: ";
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum += (1/static_cast<float>(i));
	}
	std::cout<<"\nSum of "<<n<<" terms: "<<sum;
	return 0;
}