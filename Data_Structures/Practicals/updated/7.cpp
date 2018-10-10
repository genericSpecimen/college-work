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
    int option;
    char ans = 'y';
    Queue queue;
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
