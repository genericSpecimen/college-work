#include<iostream>

int gcd(int num1, int num2) {
	if (num1 == 0) return num2;
	return gcd(num2 % num1, num1);
}

int gcd_iter(int num1, int num2) {
	int a = (num1 > num2)? num1 : num2; //max
	int b = (num1 < num2)? num1 : num2; //min
	while(b != 0) {
		int rem = a % b;
		a = b;
		b = rem;
	}
	return a;
}

int main() {
	int x, y;
	std::cout << "Enter two numbers to find their gcd: ";
	std::cin >> x >> y;
	std::cout << gcd(x,y) << std::endl;
	std::cout << gcd_iter(x,y) << std::endl;
}
