#include <iostream>
#include "StackLLTemplate.h"

int evaluate(const std::string& expression) {
	Stack<double> values;
	for(int i=0;i<expression.length();i++) {
		if(expression[i] == ' ') continue;
		else if(isdigit(expression[i])) {
			/*
			 * push to stack by
			 * subtracting the ASCII value of '0'
			 * from the ASCII value of expression[i]
			 */
			double num = 0;
			while(isdigit(expression[i])) {
				num = num*10 + (int)(expression[i] - '0');	
				i++;
			}
			i--;
			values.push(num);
		}
		else {
			//pop operands and perform operation
			double op1 = values.pop();
			double op2 = values.pop();
			switch(expression[i]) {
				case '+': values.push(op2 + op1); break;
				case '-': values.push(op2 - op1); break;
				case '*': values.push(op2 * op1); break;
				case '/': values.push(op2 / op1); break;
			}

		}
	}
	return values.pop();
}

int main() {
	std::string expression = "4 5 +";
	while (true) {
		std::cout << "Enter a postfix expression: ";
		std::getline(std::cin, expression);
		std::cout << evaluate(expression) << std::endl;
	}
}
