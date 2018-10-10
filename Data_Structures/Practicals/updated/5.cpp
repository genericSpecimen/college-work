#include<iostream>
template<class T, int size>
class Stack {
private:
	T array[size];
	int top;
public:
	Stack() {
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
        return (top == -1);
	}

	bool isFull() {
        return (top == size-1);
	}

    void clear() {
        top = -1;
    }
};

int main() {
	int option;
    char ans = 'y';
	const int size = 10;
    Stack<double, size> stack;
	std::cout << "Array implementation of Stack. What do you want to do? (1-3)\n";
    std::cout << "1. Push\n";
    std::cout << "2. Pop\n";
    std::cout << "3. Clear\n";
    do {
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch(option) {
            case 1: double element; std::cout << "Enter element to push; "; std::cin >> element; stack.push(element); break;
            case 2: std::cout << "Popped: " << stack.pop() << std::endl; break;
            case 3: stack.clear(); std::cout << "Cleared stack!\n"; break;
            default: std::cout << "Invalid option\n";
        }
        std::cout << "Do you want to continue?(y/n): ";
        std::cin >> ans;
    } while(ans == 'y' || ans == 'Y');
}
