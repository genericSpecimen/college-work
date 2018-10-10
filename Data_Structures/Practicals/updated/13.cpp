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

template<typename T>
void add_polynomials(Stack<T> p1, Stack<T> p2, int degree) {
	Stack<T> result;
	for(int i=0;i<degree;i++) {
		result.push(p1.pop() + p2.pop());
	}
	std::cout << "Sum of these polynomials: ";
	for(int i=0;i<degree;i++) std::cout << result.pop() << " x^" << degree - i-1 << " + ";
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
