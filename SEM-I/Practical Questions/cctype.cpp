#include<iostream>
#include<string>
#include<cctype>
int main()
{
	std::string str1 ("Hello");
	for(int i=0;i<str1.size();i++)
	{
		if(islower(str1[i]))
		{
			str1[i] = toupper(str1[i]);
			std::cout << str1[i] << std::endl;
		}
	}
}