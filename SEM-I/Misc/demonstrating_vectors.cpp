#include<iostream>
#include<vector>
//program to demonstrate vectors
// vector<type> name(size);

void printVector(std::vector<int> b)
{
	for(int i=0; i<b.size(); i++)
	{
		std::cout<<b[i]<< '|';
	}
}
int main()
{
	std::vector<int> v(3);
	v[0] = 10;
	v[1] = 22;
	v[2] = 5;

	v.push_back(7); // v[3] = 7
	std::cout<<v.front()<<std::endl;
	std::cout<<v.back()<<std::endl;
	std::cout<<v.at(2)<<std::endl;
	printVector(v);
	return 0;
 
}