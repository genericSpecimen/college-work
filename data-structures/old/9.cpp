#include<iostream>
class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data, Node* prev=NULL, Node* next=NULL) {
		this->data = data;
		this->prev = prev;
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
			front->prev = rear->next = new Node(data);
			rear->next->next = front;
			rear->next->prev = rear;
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
			Node* temp = front;
			rear->next = front->next;
			front->next->prev = rear;
			front = front->next;
			delete temp;
			return data;
		}

	}
	void printQueue() {
		Node* temp = front;
		std::cout << "FRONT -> ";
		do {
			if(temp!=NULL) {
				std::cout << temp->data << " <-> ";
				temp = temp->next;
			}
		} while(temp!=front);
		std::cout << " REAR\n";
	}
	
	void printQueueReverse() {
		Node* temp = rear;
		std::cout << "REAR -> ";
		do {
			if(temp != NULL) {
				std::cout << temp->data << " <-> ";
				temp = temp->prev;
			}
		} while(temp != rear);
		std::cout << " FRONT\n";
	}
	~Queue() {
		while(front != NULL) this->dequeue();
	}
};

int main() {
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.printQueue();
	q.printQueueReverse();

	std::cout << "Dequeued: " << q.dequeue() << std::endl;
	q.printQueue();
}
