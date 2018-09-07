#include<iostream>
template<class T>
class Queue {
private:
	int front, rear;
	T* elements;
public:
	int size;
	Queue(int size) {
		this->size = size;
		front = rear = -1;
		elements = new T[size];
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
	~Queue() {
		delete[] elements;
	}
};

int main() {
	Queue<char> q(6);
	q.enqueue('A');
	q.enqueue('C');
	q.enqueue('D');
	q.printQueue();

	q.dequeue();
	q.dequeue();
	q.printQueue();

}






