#include <iostream>
template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node(T data, Node<T>* next=NULL) {
		this->data = data;
		this->next = next;
	}
};

template<class T>
class Stack {
	Node<T>* top;
public:
	Stack() {
		top = nullptr;
	}
	~Stack() {
		for(Node<T>* temp;!(this->isEmpty());) {
			temp = top->next;
			delete top;
			top = temp;
		}
	}

	void push(T element) {
		if(this->isEmpty()) {
			top = new Node<T>(element);
		}
		else {
			top = new Node<T>(element, top);
		}
	}

	T pop() {
		if(!(this->isEmpty())) {
			T data = top->data;
			Node<T>* temp = top;
			top = top->next;
			delete temp;
			return data;
		}
		return 0;
	}	

	bool isEmpty() {
		return top == nullptr;
	}

	void printStack() {
		std::cout << "Top -> ";
	       	for(Node<T>* temp=top; temp!=nullptr ; temp = temp->next)
			std::cout << temp->data << " -> ";
		std::cout << "NULL\n";	
	}

    void clear() {
        for(Node<T>* temp;!(this->isEmpty());) {
            temp = top->next;
            delete top;
            top = temp;
        }
    }
};

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
			while(isdigit(expression[i])) { //support for more than one digit numbers
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
