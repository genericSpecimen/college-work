#include "stack.h"
template<typename T>
void add_polynomials(Stack<T> p1, Stack<T> p2, int degree) {
	Stack<T> result;
	for(int i=0;i<degree;i++) {
		result.push(p1.pop() + p2.pop());
	}
	std::cout << "Sum of these polynomials: ";
	for(int i=0;i<degree;i++) std::cout << result.pop() << " ";
	std::cout << std::endl;
}

int main() {
	Stack<double> p1;
	Stack<double> p2;
	int degree;
	double a;
	std::cout << "Enter the degree of polynomials: ";
	std::cin >> degree;
	std::cout << "Enter the first polynomial  (only the coefficients): ";
	for(int i=0;i<degree;i++) {
		std::cin >> a;
		p1.push(a);
	}
	std::cout << "Enter the second polynomial (only the coefficients): ";
	for(int i=0;i<degree;i++) {
		std::cin >> a;
		p2.push(a);
	}
	

	add_polynomials(p1,p2,degree);
}
