#include<iostream>
int main()
{
	int n;
	float sum=0;
	std::cout<<"\nEnter an integer\n";
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%2 == 0)
			sum -= i;
		else
			sum += i;
	}
	std::cout<<"\nSum of "<<n<<" terms: "<<sum;

}