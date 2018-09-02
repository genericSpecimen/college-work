#include "StackLLTemplate.h"
#include <string>
int main(int argc, char* argv[]) {
	Stack<int> s1;
	Stack<int> s2;
	const char* n1 = argv[1];
	const char* n2 = argv[2];
	std::string num1(n1);
	std::string num2(n2);
	for(int i=0;i<num1.length();i++) {
		s1.push(num1[i]-'0');
	}
	for(int i=0;i<num2.length();i++) {
		s2.push(num2[i]-'0');
	}
	
	Stack<int> resultStack;
	int carry = 0;
	while(!s1.isEmpty() && !s2.isEmpty()) {
		int result = carry + s1.pop() + s2.pop();
		if(result >= 10) carry = 1; else carry = 0;
		resultStack.push(result%10);
	}
	while(!s1.isEmpty()) {
		int result = carry + s1.pop();
		if(result >= 10) carry = 1; else carry = 0;
		resultStack.push(result%10);
	}	
	while(!s2.isEmpty()) {
		int result = carry + s2.pop();
		if(result >= 10) carry = 1; else carry = 0;
		resultStack.push(result%10);

	}

	while(!resultStack.isEmpty()) {
		std::cout << resultStack.pop();
	}

	std::cout << std::endl;
}
