#include<iostream>
class Node {
public:
	int data;
	Node* next;
	Node(int element, Node* p = NULL) {
		this->data = element;
		this->next = p;
	}
};

class Stack {
	Node* top;
public:
	Stack() {
		top = NULL;
	}
	~Stack() {
		for(Node* temp;!(this->isEmpty());) {
			temp = top->next;
			delete top;
			top = temp;
		}
	}

	void push(int element) {
		if(this->isEmpty()) {
			top = new Node(element);
		}
		else {
			top = new Node(element, top);
		}
	}

	int pop() {
		if(!(this->isEmpty())) {
			int data = top->data;
			Node* temp = top;
			top = top->next;
			delete temp;
			return data;
		}
		return 0;
	}	

	bool isEmpty() {
		return top == NULL;
	}

	void printStack() {
		std::cout << "Top -> ";
	       	for(Node* temp=top; temp!=NULL ; temp = temp->next)
			std::cout << temp->data << " -> ";
		std::cout << "NULL\n";	
	}
};

int main() {
	int option;
	char ans='y';
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	for(int i=0;i<5;i++) std::cout << "Popped: " << s.pop() << std::endl;
}
