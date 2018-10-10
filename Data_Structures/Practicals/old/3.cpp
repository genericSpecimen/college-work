#include<iostream>
template <class T>
class Node {
public:
	T data;
	Node* next;
	Node(T data, Node* p = nullptr) {
		this->data = data;
		this->next = p;
	}
};

template <class T>
class SLL {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	SLL() {
		head = tail = nullptr;
	}

	~SLL() {
		for(Node<T>* temp; !(this->isEmpty()); ) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	bool isEmpty() {
		return head == nullptr;
	}

	void addToHead(T element) {
		head = new Node<T>(element, head);
		if(tail == nullptr) tail = head;
	}

	void addToTail(T element) {
		if(tail != nullptr) {
			tail->next = new Node<T>(element);
			tail = tail->next;	
		}
		else head = tail = new Node<T>(element);
	}

	T deleteFromHead() {
		if(!this->isEmpty()) {
			T data = head->data;
			Node<T>* temp = head;
			if(head == tail) head = tail = nullptr;
			else head = head->next;
			return data;
		}
		return 0;
	}
	T deleteFromTail() {
		if(!this->isEmpty()) {
			T element = tail->data;
			if(head == tail) {
				Node<T>* temp = head;
				head = tail = nullptr;
				delete temp;
			}
			else {
				Node<T>* temp;
				for(temp = head; temp->next != tail; temp = temp->next);
				delete tail;
				tail = temp;
				tail->next = nullptr;
			}
			return element;
		}
		return 0;
	}
	void deleteNode(T element) {
		if(head != nullptr) {
			//if only one node in the list
			if(head == tail && element == head->data) {
				delete head;
				head = tail = nullptr;
			}
			//if more than one node, old head deleted
			else if(element == head->info) {
				Node<T>* temp = head;
				head = head->next;
				delete temp;
			}
			//more than one node, nonhead node deleted
			else {
				Node<T>* pred;
				Node<T>* temp;
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
	}

	void searchElement(T key) const {
		int i=0;
		for(Node<T>* temp = head; temp != nullptr; temp = temp->next, i++) {
			if(temp->data == key) {
				std::cout << "Element " << key << " exists at node (starting from 0): " << i << std::endl;
				return;
			}
		}
		std::cout << "Element " << key << " doesn't exist." << std::endl;
	}

	SLL<T> reverseList() {
		SLL<T> rList;
		for(Node<T>* temp = head; temp != nullptr; temp = temp->next) {
			rList.addToHead(temp->data);
		}
		return rList;
	}

	void printSLL() const {
		std::cout << "Head -> ";
		for(Node<T>* temp = head; temp != nullptr; temp = temp->next)
			std::cout << temp->data << " -> ";
		std::cout << "NULL\n";
	}

	SLL<T> operator+ (const SLL<T>& list) {
		SLL<T> concat_list;
		//add the elements of the first (invoking) list to newly created list
		for(Node<T>* temp = this->head; temp != nullptr; temp = temp->next) {
			concat_list.addToTail(temp->data);
		}
		for(Node<T>* temp = list.head; temp != nullptr; temp = temp->next) {
			concat_list.addToTail(temp->data);
		}
		return concat_list;
	}
};

int main() {
	SLL<double> list;
	list.addToHead(10.1);
	list.addToHead(20.2);
	list.addToHead(30.3);
	list.addToHead(40.4);
	
	list.addToTail(0);
	list.addToTail(-10.1);
	list.addToTail(-20.2);
	list.addToTail(-30.3);

	list.printSLL();
	std::cout << "\nDeleted from head: " << list.deleteFromHead();
	std::cout << "\nDeleted from tail: " << list.deleteFromTail() << std::endl;
	list.printSLL();

	list.searchElement(20.2);
	list.searchElement(100);

	SLL<double> rList = list.reverseList();
	std::cout << "Reversed List: ";
	rList.printSLL();

	SLL<double> concat_list = list + rList;
	std::cout << "Concatenated List: ";
	concat_list.printSLL();
}
