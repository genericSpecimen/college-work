#include<iostream>
#include<string>
#include<cstring>   //for std::strcat
#include<cctype>
#include<cstdlib>
void printAddr(std::string str)
{
	for(int i=0;i<str.size();i++)
		std::cout << "\nAddress of character " << str[i] <<" is: "<<static_cast<void *>(&str[i]);
}

void concatWithoutStrcat(std::string str1, std::string str2)
{
	str2 += str1;
	std::cout <<'\n' << str2; 
}

void concatWithStrcat(char* str1, const char* str2)      
{
	std::strcat(str1,str2);               //char * strcat ( char* destination, const char* source)
	std::cout <<'\n' << str1; 
}

void compareStrings(std::string str1, std::string str2)
{
	std::cout << "\nComparing " << str1 <<" and " <<str2;
	std::cout << "\nResult of comparison: " << str1.compare(str2);
	std::cout << "\nA negative value indicates " << str1 << " is smaller than " << str2;
	std::cout << "\nA positive value indicates " << str1 << " is larger than " << str2;
	std::cout << "\nA zero value indicates " << str1 << " is equal to " << str2;
}

void calcLength(std::string str1)
{
	int count = 0;
	char* ptr = &str1[0];
	while(*ptr != '\0')
	{
		ptr++;
		count++;
	}
	std::cout << "\nLength of string is: "<<count;
}

void converttoUpper(std::string str1)
{
	for(int i=0;i<str1.size();i++)
	{
		if(islower(str1[i]))
			str1[i] = toupper(str1[i]);
	}
	std::cout << "\nUpdated string is: "<< str1;
}

void converttoLower(std::string str1)
{
	for(int i=0;i<str1.size();i++)
	{
		if(isupper(str1[i]))
			str1[i] = tolower(str1[i]);
	}
	std::cout << "\nUpdated string is: "<< str1;
}

void calcVowels(std::string str)
{
	int count = 0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U')
			count++;
	}
	std::cout << "\nNumber of vowels in "<<str<<": "<<count;
}

void reverseString(std::string str)
{
	for(int i=0;i<str.size()/2;i++)
	{
		char temp = str[i]; 
		str[i] = str[str.size()-i-1];
		str[str.size()-i-1] = temp;
	}
	std::cout << "\nReversed string is: "<<str;
}

void printMenu()
{
	std::cout << "\nWhat do you want to do? Enter option from 1-9\n";
	std::cout << "1. Show address of each character in string\n";
    std::cout << "2. Concatenate two strings without using strcat function.\n";
    std::cout << "3. Concatenate two strings using strcat function.\n";
    std::cout << "4. Compare two strings\n";
    std::cout << "5. Calculate length of the string (use pointers)\n";
    std::cout << "6. Convert all lowercase characters to uppercase\n";
    std::cout << "7. Convert all uppercase characters to lowercase\n";
    std::cout << "8. Calculate number of vowels\n";
    std::cout << "9. Reverse the string\n";
    std::cout << "10. Exit\n";
}

std::string takeinput(bool another = false)
{
	std::string str;
	if(another)
		std::cout << "\nEnter a string\n";
	else
		std::cout << "\nEnter a string\n";
	std::cin >> str;
	return str;
}

int main()
{
	int option; char ans = 'y';
	do
	{
	    printMenu();
	    std::cout << "\nEnter option: ";
	    std::cin >> option;
	    switch(option)
	    {
	    	case 1:printAddr(takeinput());break;
	    	case 2:concatWithoutStrcat(takeinput(),takeinput(true));break;
	    	case 3:concatWithStrcat(&takeinput()[0],takeinput(true).c_str()); break;
	    	case 4:compareStrings(takeinput(),takeinput(true));break;
	    	case 5:calcLength(takeinput());break;
	    	case 6:converttoUpper(takeinput());break;
	    	case 7:converttoLower(takeinput());break;
	    	case 8:calcVowels(takeinput());break;
	    	case 9:reverseString(takeinput());break;
	    	case 10:exit(0);
	    	default:std::cout << "\nInvalid option.\n";
	    }
	    std::cout << "\nDo you want to do something else? (y/n): ";
	    std::cin >> ans;
    } while(ans == 'y' || ans == 'Y');
}    