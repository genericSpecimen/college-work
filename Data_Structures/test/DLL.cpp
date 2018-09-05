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

class DLL {
private:
	Node* head;
	Node* tail;
public:
	DLL() {
		head = tail = NULL;	
	}

	void addToHead(int data) {
		if(head == NULL) { //empty list
			head = tail = new Node(data);
		}
		else { //non empty list
			head->prev = new Node(data);
			head->prev->next = head;
			head = head->prev;
		}
	}

	void addToTail(int data) {
		if(head == NULL) {
			head = tail = new Node(data);
		} else {
			tail->next = new Node(data);
			tail->next->prev = tail;
			tail = tail->next;
		}
	}

	void add_after(int key, int data) {
		if(head == NULL) {
			std::cout << "Error: empty list!\n"; return;
		}
		Node* temp;
		for(temp=head; temp!=NULL && !(temp->data==key); temp=temp->next);
		if(temp != NULL) {
			Node* n = temp->next;
			n->prev = temp->next = new Node(data);
			temp->next->prev = temp;
			temp->next->next = n;

		}
	}

	int deleteHead() {
		try {
			if(head == NULL) throw("Empty list");
			if(head == tail) {
				int data = head->data;
				delete head;
				head = tail = NULL;
				return data;
			}
			else {
				int data = head->data;
				Node* temp = head;
				head->next->prev = NULL;
				head = head->next;
				delete temp;
				return data;
			}
		} catch(const char* s) {
			std::cerr << "Error: " << s << std::endl;
		}
		return 0;
	}
	int deleteTail() {
		try {
			if(head == NULL) throw("Empty list");
			if(head == tail) {
				int data = tail->data;
				delete tail;
				head = tail = NULL;
				return data;
			}
			else {
				int data = tail->data;
				Node* temp = tail;
				tail->prev->next = NULL;
				tail = tail->prev;
				delete temp;
				return data;
			}
		} catch(const char* s) {
			std::cerr << "Error: " << s << std::endl;
		}
		return 0;
	}
	int deleteNode(int data) {
		try {
			if(head == NULL) throw("Empty list!");
			if(head == tail) {
				if(head->data = data) {
					int data = head->data;
					delete head;
					head = tail = NULL;
					return data;
				} else throw("No such node");
			}
			else {
				Node* temp;
				for(temp=head; temp!=NULL && temp->data!=data; temp=temp->next);
				if(temp!=NULL) {
					if(temp == head) {
						int data = head->data;
						temp->next->prev = NULL;
						head = head->next;
						delete temp;
						return data;
					}
					if(temp == tail) {
						int data = tail->data;
						tail->prev->next = NULL;
						tail = tail->prev;
						delete temp;
						return data;
					}
					else {
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
						delete temp;
						return data;
					}
				} else throw("No such node");
			}
		
		} catch(const char* s) {
			std::cerr << "Error: " << s << std::endl;
		}
		return 0;
	}

	void printList() {
		std::cout << "HEAD -> ";
		for(Node* temp=head; temp!=NULL; temp=temp->next)
			std::cout << temp->data << " <-> ";
		std::cout << "TAIL\n";
	}

	void printBackwards() {
		std::cout << "TAIL -> ";
		for(Node* temp=tail;temp!=NULL;temp=temp->prev)
			std::cout << temp->data << " <-> ";
		std::cout << "HEAD\n";
	}
	~DLL() {
		for(Node* p; !(head == NULL);) {
			p = head->next;
			delete head;
			head = p;
		}
	}
};

int main() {
	DLL list;
	/*
	list.addToHead(10);
	list.addToHead(20);
	list.addToHead(30);
	list.addToHead(40);
	*/
	list.printList();
	list.printBackwards();
	list.addToTail(10);
	list.addToTail(20);
	list.addToTail(30);
	list.addToTail(40);
	list.printList();
	list.printBackwards();
	list.add_after(20,100);
	list.printList();
	list.printBackwards();
	std::cout << "Deleted: " << list.deleteHead() << std::endl;
	list.printList();
	list.printBackwards();
	std::cout << "Deleted: " << list.deleteTail() << std::endl;
	list.printList();
	list.printBackwards();
	/*
	std::cout << "Deleted: " << list.deleteTail() << std::endl;
	list.printList();
	std::cout << "Deleted: " << list.deleteTail() << std::endl;
	list.printList();
	*/
	std::cout << "Deleted: " << list.deleteNode(20) << std::endl;
	list.printList();
	list.printBackwards();
}
