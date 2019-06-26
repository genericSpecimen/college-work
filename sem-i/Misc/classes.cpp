#include<iostream>
#include<string>
class person
{
public:
	int pid;
	std::string pname;
	void person(int id,std::string name)
	{
		pid = id;
		pname = name;
	}

	void print()
	{
		std::cout << "\nID number of person: " << pid;
		std::cout << "\nName of person: " << pname;
	}
};
//class teacher: public person
//{

//}

int main()
{
	person p1;
}