//learning strings 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	/*
	std::string s = "Napolean";
	std::cout<<s<<" has "<<s.length()<<" characters\n"; 
	s.replace(5,2,"ia"); //changes Napolean to Napolian
	std::cout<<s;
	
	string s; cout<<"\nsize = "<<s.size()<<endl<< "string = "<<s;
	string s1("hello");cout<<"\nsize = "<<s1.size()<<endl<< "string = "<<s1;
	string s2 = "hello";cout<<"\nsize = "<<s2.size()<<endl<< "string = "<<s2;
	string s3(8,'x');cout<<"\nsize = "<<s3.size()<<endl<< "string = "<<s3;
	string s4 = s3;cout<<"\nsize = "<<s4.size()<<endl<< "string = "<<s4;
	string s5(s2,3,2);cout<<"\nsize = "<<s5.size()<<endl<< "string = "<<s5; // lo // s5 copies a substring of s2, it starts from index 3 and counts 2 characters.
    */

    //string manipulation functions
    //string comparison
    string s1 = "ABC Company";
    string s2 = "ABC Co";
    string s3 = "ABC Inc";
    s1.compare(s2);
    if(s1<s2)
    	cout<<"wow";
    else
    cout<<"not wow"; 

}