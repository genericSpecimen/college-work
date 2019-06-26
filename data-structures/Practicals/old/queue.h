#include<iostream>
#include "node.h"
template<typename T>
class Queue {
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue() {
		front = rear = NULL;
	}
	bool isEmpty() { return front==NULL; }
	void enqueue(T data) {
		if(front == NULL && rear == NULL) {
			front = rear = new Node<T>(data);
		} else {
			rear->next = new Node<T>(data);
			rear = rear->next;
		}
	}

	T dequeue() {
		if(front == NULL) {
			std::cout << "Empty queue!\n";
			return 0;
		}
		if(front == rear) {
			Node<T>* temp = front;
			T data = front->data;
			front = rear = NULL;
			delete temp;
			return data;
		}
		else {
			T data = front->data;
			front = front->next;
			return data;
		}

	}
	void printQueue() {
		std::cout << "FRONT -> ";
		for(Node<T>* temp=front; temp!=NULL; temp=temp->next)
			std::cout << temp->data << " -> ";
		std::cout << " REAR\n";
	}
	~Queue() {
		for(Node<T>* p; !(front == NULL);) {
			p = front->next;
			delete p;
			front = p;
		}
	}
};
