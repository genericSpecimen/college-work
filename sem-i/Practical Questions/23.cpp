#include<iostream>
template <class T>
class triangle
{
	T width, height;
public:
	triangle(T a, T b) : width(a), height(b) {}
	T area() { return width*height/2; }
	triangle operator = (const triangle& param)
	{
		width = param.width;
		height = param.height;
		return *this;
	}

	bool operator == (const triangle& param)
	{
		if(width == param.width && height == param.height) return true;
		else return false;
	}
};

int main()
{
	triangle<int> trgl1(3,4);
	triangle<int> trgl2(6,7);
	std::cout << "\nArea of triangle 1: " << trgl1.area();
	std::cout << "\nArea of triangle 2: " << trgl2.area();
	triangle<double> trgl3(6.0665,2.3354);
	std::cout << "\nArea of triangle 3: " << trgl3.area();
	trgl2 = trgl1;
	std::cout << "\nArea of triangle 2 after assignment: " << trgl2.area();
	if(trgl1 == trgl2)
		std::cout << "\nTriangle 1 and 2 are equal.\n";
	else
		std::cout << "\nTriangle 1 and 2 are not equal.\n";
	return 0;
}