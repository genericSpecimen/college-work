#include <iostream>
#include <string>
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

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cout << "Usage: add_nums <num1> <num2>" << std::endl; 
    } else {
        Stack<int> s1;
        Stack<int> s2;

        std::string num1(argv[1]);
        std::string num2(argv[2]);
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

        if(carry == 1) resultStack.push(carry);

        while(!resultStack.isEmpty()) {
            std::cout << resultStack.pop();
        }

        std::cout << std::endl;
    }
}
