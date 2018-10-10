#include<iostream>
template<class T>
class Node {
public:
	T data;
	Node<T>* prev;
	Node<T>* next;
	Node(T data, Node<T>* prev=NULL, Node<T>* next = NULL) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

template<class T>
class CDLL {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	CDLL() {
		head = tail = NULL;
	}

	void insertHead(T data) {
		if(head == NULL) {
			head = tail = new Node<T>(data);
			tail->next = head;
			head->prev = tail;
		}
		else {
			head->prev = tail->next = new Node<T>(data);
			head->prev->next = head;
			head->prev->prev = tail;
			head = head->prev;
		}
	}

	T deleteHead() {
		try {
			if(head == NULL) throw("Empty list");
			if(head == tail) {
				T data = head->data;
				head->next = head->prev = tail->next = tail->prev = NULL;
				delete head;
				return data;
			}
			else {
				T data = head->data;
				Node<T>* temp = head;
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

	bool searchNode(T key) {
		if(head->data == key || tail->data == key) return true;
		Node<T>* temp = head;
		do {
			if(temp != NULL) {
				if(temp->data == key) return true;
				temp = temp->next;
			}
		} while(temp != head);
		return false;
	}

	CDLL<T> reverseList() {
		CDLL<T> rList;
		Node<T>* temp=head;
		do {
			if(temp != NULL) {
				rList.insertHead(temp->data);
				temp = temp->next;
			}
		} while(temp != head);
		return rList;
	}

	void printList() const {
		std::cout << "HEAD -> ";
		Node<T>* temp = head;
		do {
			if(temp != NULL) std::cout << temp->data << " <-> ";
			temp = temp->next;
		} while(temp != head);
		std::cout << "TAIL\n";
	}
	~CDLL() {
		Node<T>* temp;
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
	CDLL<double> list;
	list.insertHead(10.1);
	list.insertHead(20.2);
	list.insertHead(30.3);
	list.insertHead(40.4);
	list.printList();
	std::cout << "Deleted: " << list.deleteHead() << std::endl;
	list.printList();
	std::cout << std::boolalpha << list.searchNode(20.2) << std::endl;
	std::cout << std::boolalpha << list.searchNode(1) << std::endl;
	CDLL<double> rList = list.reverseList();
	rList.printList();
}
