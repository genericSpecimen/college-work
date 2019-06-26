#include<iostream>
#include<string>
#include<iomanip>

int main(int argc, char *argv[])
{
  std::string str("");
  static int alphabet[26];
  int x;
  std::cout << "\nEnter string: ";
  std::getline(std::cin,str);
  std::cout<<"\n\n Command-Line Arguments\n";
  for(int i=0;i<argc;i++)
  {
    std::cout<<"\n "<<argv[i];
    str+=argv[i];
  }

  for(int i=0;i<str.length();i++)
  {
    if(str[i]>='A' && str[i]<='Z')
    {
      x=((int)str[i])-65;
      alphabet[x]++;
    }
    else if(str[i]>='a' && str[i]<='z')
    {
      x=((int)str[i])-97;
      alphabet[x]++;
    }
  }
 //Displaying No. of occurrences of each alphabets in the command line argument
 std::cout<<"\n\n"<<std::setw(8)<< "Alphabet"<<std::setw(18) << "        No. of Occurrences\n";
 for(int i=0;i<26;i++)
    std::cout<<"\n"<< std::setw(8)<< (char)(65+i)<<std::setw(18)<<alphabet[i];
 return 0;
}