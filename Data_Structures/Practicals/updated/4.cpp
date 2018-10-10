#include<iostream>

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

int main() {
    int option;
    char ans = 'y';
    Stack<double> stack;
    std::cout << "Linked list implementation of Stack. What do you want to do? (1-3)\n";
    std::cout << "1. Push\n";
    std::cout << "2. Pop\n";
    std::cout << "3. Clear\n";
    std::cout << "4. Print the stack\n";
    do {
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch(option) {
            case 1: double element; std::cout << "Enter element to push; "; std::cin >> element; stack.push(element); break;
            case 2: std::cout << "Popped: " << stack.pop() << std::endl; break;
            case 3: stack.clear(); std::cout << "Cleared stack!\n"; break;
            case 4: stack.printStack(); break;
            default: std::cout << "Invalid option\n";
        }
        std::cout << "Do you want to continue?(y/n): ";
        std::cin >> ans;
    } while(ans == 'y' || ans == 'Y');
}