#include<iostream>
#include<vector>
int sum=0;
float avg;
void printEven(std::vector<int>v);
void printOdd(std::vector<int>v);
void CalculateSumAvg(std::vector<int>v);
void printMaxMin(std::vector<int>v);
void rmDuplicates(std::vector<int>v);
void printRev(std::vector<int>v); 
int main()
{
	std::vector<int> v;
	char ans;
	int input,option;
	std::cout<<"\nEnter vector elements(integers only)\n";
	 while(std::cin>>input)
	 	v.push_back(input);
	if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		}	
    do
    {  
    	
	for(int i=0;i<v.size();i++)
	std::cout<<v[i]<<' ';
	std::cout<<"\nWhat do you want to do?\nEnter option from 1-5\n";
	std::cout<<"\n1. Print the even valued elements.\n2.Print the odd valued elements\n3.Calculate and print the sum and average of the elements of array.\n4.Print the maximum and minimum element of array\n5.Remove the duplicates from the array\n6.Print the array in reverse order\n";
	std::cin.clear();
	std::cin>>option;
	switch(option)
	{
		case 1: printEven (v); 
		        break;
		case 2: printOdd (v); 
		        break;
		case 3: CalculateSumAvg (v);
		        break;
		case 4: printMaxMin (v);
		        break;
		case 5: rmDuplicates(v);
		        break;
		case 6: printRev(v);
		        break;
		default: std::cout<<"\nEnter a valid option\n";
	}
	std::cout<<"\nDo you want to do something else? (y/n): ";
	std::cin>>ans;
    }while(ans == 'y' || ans == 'Y');
}

void printEven(std::vector<int> v)
{
	for(int i =0;i<v.size();i++)
	{
		if(v[i]%2 == 0)
			std::cout<<v[i]<<' ';
	}
}

void printOdd(std::vector<int> v)
{
	for(int i =0;i<v.size();i++)
	{
		if(v[i]%2 != 0)
			std::cout<<v[i]<<' ';
	}
}

void CalculateSumAvg(std::vector<int> v)
{
	for(int i =0;i<v.size();i++)
	{
		sum += v[i];
	}
	avg = static_cast<float>(sum)/v.size();
	std::cout<<"\nSum of vector elements is: "<<sum;
	std::cout<<"\nAverage of vector elements is: "<<avg;
}

void printMaxMin(std::vector<int> v)
{
	int max = v[0],min = v[0];
	for(int i =1;i<v.size();i++)
	{
		if(v[i] > max)
			max = v[i];
		if(v[i] < min)
			min = v[i];
	}
	std::cout<<"\nMaximum element is: "<<max;
	std::cout<<"\nMinimum element is: "<<min;
}

void rmDuplicates(std::vector<int> v)
{
	int n = v.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;)
		{
			if(v[i] == v[j])
			{
				for(int k=j;k<n-1;++k)
					v[k] = v[k+1];
				--n;
			}
			else
				++j;
		}
	}

	std::cout << "\nAfter removing duplicates\n";
	for(int i=0;i<n;i++)
		std::cout << v[i] << ' ';
}

void printRev(std::vector<int> v)
{
	for(int i=v.size()-1;i>=0;i--)
		std::cout<<v[i]<<' ';
}