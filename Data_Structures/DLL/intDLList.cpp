#include<iostream>

class Node {
public:
	Node* prev;
	Node* next;
	int info;
	Node() {
		prev = next = nullptr;
	}
	Node(int element, Node* n = nullptr, Node* p = nullptr) {
		this->info = element;
		this->next = n;
		this->prev = p;
	}
};

class List {
private:
	Node* head;
	Node* tail;
public:
	List() {
		head = tail = nullptr;
	}
	~List() {
		for(Node* temp; !this->isEmpty();) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	bool isEmpty() {
		return head==nullptr;
	}

	void addToTail(int element) {
		if(tail != nullptr) {
			tail = new Node(element, nullptr, tail);
			tail->prev->next = tail;
		}
		else head = tail = new Node(element);
	}

	int deleteFromTail() {
		int element = tail->info;
		if(head == tail) {
			delete head;
			head = tail = 0;
		}
		else {
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		return element;
	}

	void printList() {
		Node* temp;
		std::cout << "Head <-> ";
		for(temp = head; temp != nullptr; temp = temp->next) {
			std::cout << temp->info << " <-> ";
		}
		std::cout << "NULL\n";
	}

};

int main() {
	List l;
	l.addToTail(100);
	l.addToTail(200);
	l.addToTail(300);
	l.addToTail(400);
	l.printList();

	l.deleteFromTail();
	l.printList();
}
