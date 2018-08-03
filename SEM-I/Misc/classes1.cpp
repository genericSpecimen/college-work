#include<iostream>
class rectangle
{
	int length, width;
public:
	rectangle(int, int);
	/*int area()
	{
		return length*width;
	}
	void print()
	{
		std::cout << "\nThe length of rectangle is: " << length; 
		std::cout << "\nThe width of rectangle is: " << width; 
	}*/
};

/*int rectangle::area()
{
	return length*width;
}

void rectangle::print()
{
	std::cout << "\nThe length of rectangle is: " << length; 
	std::cout << "\nThe width of rectangle is: " << width;
}
*/
rectangle::rectangle(int a, int b)
{
	length = a;
	width = b;
}

int main()
{
	int l,b;
	std::cout << "\nEnter length and width: ";
	std::cin >> l >> b;
	rectangle r1(l,b);
	r1.print();
	std::cout << "\nThe area of rectangle is: " << r1.area() << std::endl;
}