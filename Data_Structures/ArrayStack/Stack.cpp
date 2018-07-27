#include<iostream>

class Stack {
private:
	int* array;
	int top;
	int size;
public:
	Stack(int size) {
			array = new int[size];
			this->size = size;
			this->top = -1;
	}

	void push(int data) {
		if(!isFull())
			array[++top] = data;
		else
			std::cout << "The stack is full. You can't push elements.\n";
	}

	int peek() {
		return array[top]; 
	}
	int pop() {
		if(!isEmpty()) {
			int data = array[top];
			top--;
			return data;
		}
		else std::cout << "Can't pop as stack is empty.";
		return 0;
	}

	bool isEmpty() {
		if(top == -1)
			return true;
		return false;
	}

	bool isFull() {
		if(top == this->size-1)
			return true;
		return false;
	}
	~Stack() {
		delete[] array;
	}
};

int main() {
	int size, data, option;
	char ans = 'y';

	std::cout << "Enter the size of the stack to be created: ";
	std::cin >> size;
	Stack s(size);
	
	std::cout << "What do you want to do? Enter from option 1-4: ";
	std::cout << "\n1. Push an element.";
	std::cout << "\n2. Pop  an element.";
	std::cout << "\n3. Peek the top element.";
	do {
		std::cout << "\nEnter an option: ";
		std::cin >> option;
		switch(option) {
			case 1:	int element;
		       		std::cout << "Enter the element to be pushed: ";
				std::cin >> element;
				s.push(element); break;
			case 2: std::cout << s.pop() << std::endl; break;
			case 3: std::cout << s.peek() << std::endl; break;
			default: std::cout << "Invalid option!\n";
		}
		std::cout << "Do you want to continue? (y/n): ";
		std::cin >> ans;
	} while(ans == 'Y' || ans == 'y');
}
