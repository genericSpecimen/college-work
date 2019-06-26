#include<iostream>
int main()
{
	int n;
	float input,sum =0;
    std::cout<<"\nEnter an integer n and enter n floating point numbers";
    std::cin>>n;
    for(int i =0;i<n;i++)
        {
	      std::cin>>input;
	      sum+=input;
        }
    std::cout<<"\nSum ="<<sum;
    std::cout<<"\nAverage ="<<static_cast<float>(sum)/n;

}

