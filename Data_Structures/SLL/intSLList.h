#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class Node {
public:
	int info;
	Node* next;

	Node() {
		next = 0;
	}
	Node(int info, Node* ptr = 0) {
		this->info = info;
		this->next = ptr;
	}
};

class List {
private:
	Node* head;
	Node* tail;
public:
	List() {
		head = tail = 0;
	}
	~List();
	bool isEmpty() {
		return head==0;
	}

	void addToHead(int);
	void addToTail(int);

	int deleteFromHead();
	int deleteFromTail();
	
	void deleteNode(int);
	
	bool isInList(int) const;

	void printList() const;

};

#endif
