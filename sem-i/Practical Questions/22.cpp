#include<iostream>
#include<string>
class person
{
protected:
	int pid;
	std::string pname;
public:
	virtual void getdata()
	{
		std::cout << "\nEnter person id and name\n";
		std::cin >> pid;
		std::cin.ignore(INT_MAX,'\n');
		std::getline(std::cin, pname);
	}
	virtual void putdata()
	{
		std::cout << "\nPerson ID: " << pid;
		std::cout << "\nPerson name: " << pname;
 	}
};

class teacher : public person
{
public:
	int texp;
	void getdata()
	{
		std::cout << "\nEnter teacher id, name and years of teaching experience\n";
		std::cin >> pid;
		std::cin.ignore(INT_MAX,'\n');
		std::getline(std::cin, pname);
		std::cin >> texp;
	}
	void putdata()
	{
		std::cout << "\nTeacher ID: " << pid;
		std::cout << "\nTeacher name: " << pname;
		std::cout << "\nYears of teaching experience: " << texp << std::endl;
	}
};

class student : public person
{
public:
	int grade;
	void getdata()
	{
		std::cout << "\nEnter student id, name and grade in which student is studying\n";
		std::cin >> pid;
		std::cin.ignore(INT_MAX,'\n');
		std::getline(std::cin, pname);
		std::cin >> grade;
	}
	void putdata()
	{
		std::cout << "\nStudent ID: " << pid;
		std::cout << "\nStudent name: " << pname;
		std::cout << "\nGrade : " << grade << std::endl;
	}
};


int main()
{
	person * pperson = new person;
	person * pteacher = new teacher;
	person * pstudent = new student;

	pperson->getdata();
	pteacher->getdata();
	pstudent->getdata();

	pperson->putdata();
	pteacher->putdata();
	pstudent->putdata();

	delete pperson;
	delete pteacher;
	delete pstudent;

	return 0;
}