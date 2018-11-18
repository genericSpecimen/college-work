#include<iostream>
template<class T, int size>
class Queue {
private:
	int front, rear;
	T elements[size];
public:
	Queue() {
		front = rear = -1;
	}
	void enqueue(T data) {
		if(!isFull()) {
			if(rear == size-1 || rear == -1) {
				elements[0] = data;
				rear = 0;
				if(front == -1) front = 0;
			} else {
				elements[++rear] = data;
			}
		} else std::cout << "Queue is full.\n";
	}
	T dequeue() {
		if(!isEmpty()) {
			T temp = elements[front];
			if(front == rear)
				front = rear = -1;
			else if(front == size-1)
				front = 0;
			else front++;
			return temp;
		}
		else std::cout << "Empty Queue!\n";
		return 0;
	}
	bool isFull() {
		return front == 0 && rear==size-1 || front == rear+1;
	}
	bool isEmpty() {
		return front == -1;
	}
	void printQueue() {
		for(int temp = front; temp <= rear; temp++) {
			std::cout << elements[temp] << " ";
		}
		std::cout << std::endl;
	}
};

int main() {
    int option;
    char ans = 'y';
	const int size = 10;
    Queue<double, size> queue;
	std::cout << "Circular array implementation of Queue. What do you want to do? (1-2)\n";
    std::cout << "1. Enqueue\n";
    std::cout << "2. Dequeue\n";
    do {
        std::cout << "Enter your choice: ";
        std::cin >> option;
        switch(option) {
            case 1: double element; std::cout << "Enter element to enqueue; "; std::cin >> element; queue.enqueue(element); break;
            case 2: std::cout << "Dequeued: " << queue.dequeue() << std::endl; break;
            default: std::cout << "Invalid option\n";
        }
        std::cout << "Do you want to continue?(y/n): ";
        std::cin >> ans;
    } while(ans == 'y' || ans == 'Y');
}
