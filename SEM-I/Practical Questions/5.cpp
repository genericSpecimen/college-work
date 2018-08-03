#include<iostream>
#include<string>
bool isPalindrome(std::string s1)
{
	for(int i=0;i<s1.size()/2;i++)
	{
		if(s1[i] != s1[s1.size()-i-1])
			return false;
	}
	return true;
}

int main()
{
	std::string str1;
	std::cout << "\nEnter a string: ";
	std::getline(std::cin,str1);
	if(isPalindrome(str1) == true)
		std::cout << "\nString is a palindrome\n";
	else
		std::cout << "\nString is not a palindrome\n";
	return 0;
}