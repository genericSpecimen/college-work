#include<iostream>
int num1,num2,num3,num4,num5;
int smallest();
int largest();
int sum();
float average();

int main()
{
	int option;
	float result;
	std::cout<<"\nEnter five numbers\n";
	std::cin >> num1 >> num2 >> num3 >> num4 >> num5;
	std::cout<<"\nWhat do you want to do with these numbers? (Choose from options 1-4)\n";
	std::cout<<"1. Find the smallest number\n2. Find the largest number\n3. Find the sum\n4. Find the average\n";
	std::cin>>option;
	switch(option)
	{
		case 1 : result = smallest();
		         std::cout<<"\nThe smallest of these numbers is: "<<result;
		         break;
		case 2 : result = largest();
		         std::cout<<"\nThe largest of these numbers is: "<<result;
		         break;
		case 3 : result = sum();
		         std::cout<<"\nThe sum of these numbers is: "<<result;
		         break;
		case 4 : result = average();
		         std::cout<<"\nThe average of these numbers is: "<<result;
		         break;
		default :std::cout<<"\nEnter valid option\n";         
	}
}

int smallest()
{
	int smallest = num1;
	if(num2 < smallest)
		smallest = num2;
	if(num3 < smallest)
		smallest = num3;
	if(num4 < smallest)
		smallest = num4;
	if(num5 < smallest)
		smallest = num5;
	return smallest;
}

int largest()
{
	int largest = num1;
	if(num2 > largest)
		largest = num2;
	if(num3 > largest)
		largest = num3;
	if(num4 > largest)
		largest = num4;
	if(num5 > largest)
		largest = num5;
	return largest;
}

int sum()
{
	int sum = 0;
	sum = num1 + num2 + num3 + num4 + num5;
	return sum;
}

float average()
{
	float average = 0;
	average = static_cast<float>((num1 + num2 + num3 + num4 + num5))/5;      //the correct parentheses placing is important
	return average;
}
