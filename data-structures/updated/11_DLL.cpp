#include<iostream>

template <class T>
class Node {
public:
	Node* prev;
	Node* next;
	T info;
	Node() {
		prev = next = nullptr;
	}
	Node(T element, Node* n = nullptr, Node* p = nullptr) {
		this->info = element;
		this->next = n;
		this->prev = p;
	}
};

template <class T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List() {
		head = tail = nullptr;
	}
	~List() {
		for(Node<T>* temp; !this->isEmpty();) {
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	bool isEmpty() {
		return head==nullptr;
	}

	void addToHead(T element) {
		if(head != nullptr) {
			head = new Node<T>(element, head, nullptr);
			head->next->prev = head;
		}
		else head = tail = new Node<T>(element);
	}

	void addToTail(T element) {
		if(tail != nullptr) {
			tail = new Node<T>(element, nullptr, tail);
			tail->prev->next = tail;
		}
		else head = tail = new Node<T>(element);
	}
	
	T deleteFromHead() {
		T element = head->info;
		if(head == tail) {
			delete head;
			head = tail = nullptr;
		}
		else {
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
		return element;
	}

	T deleteFromTail() {
		T element = tail->info;
		if(head == tail) {
			delete head;
			head = tail = nullptr;
		}
		else {
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		return element;
	}
	T deleteNode(T key) {
		try {
			if(head == NULL) throw("Empty list!");
			if(head == tail) {
				if(head->info == key) {
					T data = head->info;
					delete head;
					head = tail = NULL;
					return data;
				} else throw("No such node");
			}
			else {
				Node<T>* temp;
				for(temp=head; temp!=NULL && temp->info!=key; temp=temp->next);
				if(temp!=NULL) {
					if(temp == head) {
						T data = head->info;
						temp->next->prev = NULL;
						head = head->next;
						delete temp;
						return data;
					}
					if(temp == tail) {
						T data = tail->info;
						tail->prev->next = NULL;
						tail = tail->prev;
						delete temp;
						return data;
					}
					else {
						T data = temp->info;
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

	bool searchNode(T key) {
		if(head->info == key || tail->info == key) return true;
		Node<T>* temp;
		for(temp=head; temp!=NULL; temp=temp->next) {
			if(temp->info == key) return true;
		}
		return false;
	}

	List<T> reverseList() {
		List<T> rList;
		for(Node<T>* temp = head; temp != NULL; temp = temp->next) {
			rList.addToHead(temp->info);
		}
		return rList;
	}

	void printList() {
		Node<T>* temp;
		std::cout << "Head <-> ";
		for(temp = head; temp != nullptr; temp = temp->next) {
			std::cout << temp->info << " <-> ";
		}
		std::cout << "NULL\n";
	}

};

int main() {
	List<double> l;
	l.addToHead(0);
	l.addToHead(-100.1);
	l.addToHead(-200.2);
	l.addToHead(-300.3);

	l.addToTail(100.1);
	l.addToTail(200.2);
	l.addToTail(300.3);
	l.addToTail(400.4);
	l.printList();

	l.deleteFromHead();
	l.deleteFromTail();
	l.deleteNode(100.1);
	l.printList();
	std::cout << std::boolalpha << l.searchNode(100.1) << std::endl;
	std::cout << std::boolalpha << l.searchNode(200.2) << std::endl;
	
	List<double> rList = l.reverseList();
	rList.printList();
}
