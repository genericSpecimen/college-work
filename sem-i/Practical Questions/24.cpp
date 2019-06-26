#include<iostream>
#include<string>
class box
{
	int length, breadth, height;
public:
	box(int a, int b, int c) : length(a), breadth(b), height(c) {}
	int surfacearea()
	{ return (2*(length*breadth + breadth*height + height*length)); }
	int volume()
	{ return length*breadth*height; }
	std::string check()
	{
		if(length == breadth && breadth == height && height == length)
			return "cube";
		else
			return "cuboid";
	}

	void putdata()
	{
		std::cout << "\nThe box is a "<< check();
		std::cout << "\nLength: " << length << "\nBreadth: " << breadth <<"\nHeight: " << height << std::endl;
		std::cout << "\nThe surface area of this " << check() << ':' << surfacearea();
		std::cout << "\nThe volume of this " << check() << ':' << volume();
	}

	box operator ++ () //prefix
	{
		++length;
		++breadth;
		++height;
		return box(length,breadth,height);
	}

	box operator ++ (int a) //postfix
	{
		box b(length,breadth,height); //save original value
		++length;
		++breadth;
		++height;
		return b; //return original value
	}

	box operator -- () //prefix
	{
		--length;
		--breadth;
		--height;
	}

	box operator -- (int a) //postfix
	{
		box b(length, breadth, height); //save original value
		--length;
		--breadth;
		--height;
		return b; //return original value
	}

	bool operator == (const box& param)
	{
		if(length == param.length && breadth == param.breadth && height == param.height)
			return true;
		else
			return false;
	}

	box operator = (const box& param)
	{
		length = param.length;
		breadth = param.breadth;
		height = param.height;
		return *this;
	}
};

int main()
{
	box b1(2,3,4);
	box b2(5,5,5);

	b1.putdata();
	std::cout << std::endl;
	b2.putdata();

	//using increment and decrement operator by overloading 
	std::cout << "\nAFTER USING PREFIX INCREMENT\n";
	++b1;
	b1.putdata();
	std::cout << std::endl;

	std::cout << "\nAFTER USING POSTFIX INCREMENT\n";
	b1++;
	b1.putdata();
	std::cout << std::endl;

	std::cout << "\nAFTER USING PREFIX DECREMENT\n";
	--b1;
	b1.putdata();
	std::cout << std::endl;

	std::cout << "\nAFTER USING POSTFIX DECREMENT\n";
	b1--;
	b1.putdata();
	std::cout << std::endl;

	b1 = b2; //using overloaded assignment operator 

	if(b1 == b2)
		std::cout << "\nThe two boxes are equal\n";
	else
		std::cout << "\nThe two boxes are not equal\n";
}