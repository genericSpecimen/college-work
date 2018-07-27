#include <iostream>
#include "genStack.h"

int main() {
	Stack<int, 5> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
}
