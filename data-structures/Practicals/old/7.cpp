#include<iostream>
template<class T>
class Stack {
private:
	T* array;
	int top;
	int size;
public:
	Stack(int size) {
			array = new T[size];
			this->size = size;
			this->top = -1;
	}

	void push(T data) {
		if(!isFull())
			array[++top] = data;
		else
			std::cout << "The stack is full. You can't push elements.\n";
	}

	T peek() {
		return array[top]; 
	}
	T pop() {
		if(!isEmpty()) {
			T data = array[top];
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
	Stack<double> s(4);
	s.push(100.1);
	s.push(200.2);
	s.push(300.3);
	s.push(400.4);

	for(int i=0;i<4;i++) std::cout << "Popped: " << s.pop() << std::endl;
}
