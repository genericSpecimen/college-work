#include<iostream>

class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data, Node* prev=NULL, Node* next = NULL) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

class CDLL {
private:
	Node* head;
	Node* tail;
public:
	CDLL() {
		head = tail = NULL;
	}

	void insertHead(int data) {
		if(head == NULL) {
			head = tail = new Node(data);
			tail->next = head;
			head->prev = tail;
		}
		else {
			head->prev = tail->next = new Node(data);
			head->prev->next = head;
			head->prev->prev = tail;
			head = head->prev;
		}
	}

	int deleteHead() {
		try {
			if(head == NULL) throw("Empty list");
			if(head == tail) {
				int data = head->data;
				head->next = head->prev = tail->next = tail->prev = NULL;
				delete head;
				return data;
			}
			else {
				int data = head->data;
				Node* temp = head;
				head->next->prev = tail;
				tail->next = head->next;
				head = head->next;
				delete temp;
				return data;
			}
		} catch(const char* s) {
			std::cerr << "Error: " << s << std::endl;
		}	
		return 0;
	}
	void printList() {
		std::cout << "HEAD -> ";
		Node* temp = head;
		do {
			if(temp != NULL) std::cout << temp->data << " <-> ";
			temp = temp->next;
		} while(temp != head);
		std::cout << "TAIL\n";
	}
	~CDLL() {
		Node* temp;
		do {
			if(head != NULL) {
				temp = head->next;
				delete head;
				head = temp;
			}
		}while(temp!=head);
	}
	
};

int main() {
	CDLL list;
	list.insertHead(10);
	list.insertHead(20);
	list.insertHead(30);
	list.insertHead(40);
	list.printList();
	std::cout << "Deleted: " << list.deleteHead() << std::endl;
	list.printList();
}
