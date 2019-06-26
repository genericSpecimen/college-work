#include<iostream>
char calcGrade(float marks1,float marks2,float marks3)
{
	float avgmarks = (marks1 + marks2 + marks3)/3;
	if (avgmarks>=90)
		return 'A';
	else if(avgmarks>=70 && avgmarks<90)
	{
		if(marks3>90)
			return 'A';
		else
			return 'B';
	}
	else if(avgmarks>=50 && avgmarks<70)
	{
		if(((marks2+marks3)/2)>70)
			return 'C';
		else
			return 'D';
	}
	else if(avgmarks<50)
		return 'F';

}
void input()
{
	float marks1,marks2,marks3;
	std::cout<<"\nEnter three test scores\n";
	std::cin>>marks1>>marks2>>marks3;
	char grade = calcGrade(marks1,marks2,marks3);
	std::cout<<"\nGrade of student: "<<grade;
}
int main()
{
	input();
}
