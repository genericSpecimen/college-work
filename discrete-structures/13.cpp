#include<iostream>
int main() {
	int x,y;
	std::cout << "Enter the truth values of variables x and y.";
	std::cout << "\n0 for false.";
	std::cout << "\n1 for true.";
	std::cout << "\nEnter values: ";
	std::cin >> x >> y;

	std::cout << "Conjunction    | " << std::boolalpha << (x && y) << std::endl;
	std::cout << "Disjunction    | " << std::boolalpha << (x || y) << std::endl;
	std::cout << "Exclusive OR   | " << std::boolalpha << ((!x) != (!y)) << std::endl;
	std::cout << "Conditional    | " << std::boolalpha << !(x && (!y)) << std::endl;
	std::cout << "Bi-conditional | " << std::boolalpha << ((x && y) || (!x && !y)) << std::endl;
	std::cout << "Exclusive NOR  | " << std::boolalpha << !((!x) != (!y)) << std::endl;
	std::cout << "Negation of x  | " << std::boolalpha << !x << std::endl;
	std::cout << "Negation of y  | " << std::boolalpha << !y << std::endl;
	std::cout << "NAND           | " << std::boolalpha << !(x && y) << std::endl;
	std::cout << "NOR            | " << std::boolalpha << !(x || y) << std::endl;
}