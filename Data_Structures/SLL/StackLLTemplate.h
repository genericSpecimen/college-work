#include<iostream>
template <class T>
class Node {
public:
	T data;
	Node* next;
	Node(T element, Node<T>* p = nullptr) {
		this->data = element;
		this->next = p;
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
};

/*int main() {
	
	int option;
	char ans='y';
	Stack s;
	std::cout << "What do you want to do? (1-3):";
	std::cout << "\n1. Push an element.";
	std::cout << "\n2. Pop an element.";
	std::cout << "\n3. Clear the stack.";
	std::cout << "\n4. Print the stack.";

	do {
		std::cout << "\nEnter your option: ";
		std::cin >> option;
		switch(option) {
			case 1: std::cout << "Enter element to be pushed: ";
				int element;
				std::cin >> element;
				s.push(element);
				break;
			case 2: s.pop(); break;
			case 3: s.~Stack(); break;
			case 4: s.printStack();
			default: std::cout << "Invalid option!";	
		}
		std::cout << "Do you want to continue? (y/n)";
		std::cin >> ans;
	} while(ans=='y' || ans == 'Y');
*/	

	/*
	Stack<double> s;
	s.push(100.4404);
	s.push(200.4404);
	s.push(300.4404);
	s.push(400.4404);
	
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	
}*/
