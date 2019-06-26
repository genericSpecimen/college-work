#include<iostream>
int main()
{
	int input1,input,largest,count=1,n;
	std::cout<<"\nEnter an integer\n";
	std::cin>>n;
	std::cout<<"\nEnter "<<n<<" integers\n";
	std::cin>>input1;
	largest = input1;
	for(int i=0;i<n-1;i++)
	{
		std::cin>>input;
		if(input>largest)
			{
				largest=input;
				count = 1;
			}		
		if(input==largest)
			count++;

	}
	if(largest == input1)
		count++;
	std::cout<<"\nLargest Value entered: "<<largest;
	std::cout<<"\nIt was entered this many times: "<<count;
	return 0;
}