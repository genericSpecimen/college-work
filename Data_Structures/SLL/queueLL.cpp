#include<iostream>
class Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next=NULL) {
		this->data = data;
		this->next = next;
	}
};

class Queue {
private:
	Node* front;
	Node* rear;
public:
	Queue() {
		front = rear = NULL;
	}
	void enqueue(int data) {
		if(front == NULL && rear == NULL) {
			front = rear = new Node(data);
		} else {
			rear->next = new Node(data);
			rear = rear->next;
		}
	}

	int dequeue() {
		if(front == NULL) {
			std::cout << "Empty queue!\n";
			return 0;
		}
		if(front == rear) {
			Node* temp = front;
			int data = front->data;
			front = rear = NULL;
			delete temp;
			return data;
		}
		else {
			int data = front->data;
			front = front->next;
			return data;
		}

	}
	void printQueue() {
		std::cout << "FRONT -> ";
		for(Node* temp=front; temp!=NULL; temp=temp->next)
			std::cout << temp->data << " -> ";
		std::cout << " REAR\n";
	}
};

int main() {
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.printQueue();

	std::cout << "Dequeued: " << q.dequeue() << std::endl;
	q.printQueue();
}
