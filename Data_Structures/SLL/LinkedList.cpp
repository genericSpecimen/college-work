#include<iostream>

class Node {
public:
	int data;
	Node* next;
	Node(int data, Node* p = nullptr) {
		this->data = data;
		this->next = p;
	}
};

class SLL {
private:
	Node* head;
	Node* tail;
public:
	SLL() {
		head = tail = nullptr;
	}

	~SLL() {
		for(Node* temp; !(this->isEmpty()); ) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	bool isEmpty() {
		return head == nullptr;
	}

	void addToHead(int element) {
		head = new Node(element, head);
		if(tail == nullptr) tail = head;
	}

	void addToTail(int element) {
		if(tail != nullptr) {
			tail->next = new Node(element);
			tail = tail->next;	
		}
		else head = tail = new Node(element);
	}

	int deleteFromHead() {
		if(!this->isEmpty()) {
			int data = head->data;
			Node* temp = head;
			if(head == tail) head = tail = nullptr;
			else head = head->next;
			return data;
		}
		return 0;
	}
	int deleteFromTail() {
		if(!this->isEmpty()) {
			int element = tail->data;
			if(head == tail) {
				Node* temp = head;
				head = tail = nullptr;
				delete temp;
			}
			else {
				Node* temp;
				for(temp = head; temp->next != tail; temp = temp->next);
				delete tail;
				tail = temp;
				tail->next = nullptr;
			}
			return element;
		}
		return 0;
	}
	void deleteNode(int element) {
		if(head != nullptr) {
			//if only one node in the list
			if(head == tail && element == head->data) {
				delete head;
				head = tail = nullptr;
			}
			//if more than one node, old head deleted
			else if(element == head->info) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}
			//more than one node, nonhead node deleted
			else {
				Node* pred;
				Node* temp;
				/*
				 * pred keeps track of the predecessor of element to be found
				 * temp keeps track of the element to be found
				 * run the loop until either
				 * 1. temp == nullptr, i.e. end of list reached, element not found
				 * 2. temp->data == element, i.e. element is found
				 */
				for(pred = head, temp = head->next;
				    temp != nullptr && !(temp->data == element);
				    pred = pred->next, temp = temp->next);
				if(temp != nullptr) {//element found
					pred->next = temp->next;
					if(temp == tail)
						tail = pred;
					delete temp;
			}
		}
	}
	
	//bool isInList(int) const {}
	void printSLL() const {
		std::cout << "Head -> ";
		for(Node* temp = head; temp != nullptr; temp = temp->next)
			std::cout << temp->data << " -> ";
		std::cout << "NULL\n";
	}
};

int main() {
	SLL list;
	list.addToHead(10);
	list.addToHead(20);
	list.addToHead(30);
	list.addToHead(40);
	
	list.addToTail(0);
	list.addToTail(-10);
	list.addToTail(-20);
	list.addToTail(-30);

	list.printSLL();
	std::cout << "\nDeleted from head: " << list.deleteFromHead();
	std::cout << "\nDeleted from tail: " << list.deleteFromTail() << std::endl;
	list.printSLL();
}
