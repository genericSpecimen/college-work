#include <iostream>
#include <algorithm>
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
class DLL {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	DLL() {
		head = tail = nullptr;
	}
	~DLL() {
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

    void insert(T element) {
        if(this->isEmpty()) this->addToTail(element);
        else {
            if(head->info >= element) this->addToHead(element);
            else if(tail->info <= element) this->addToTail(element);
            else {
                Node<T>* temp;
                Node<T>* pred;
                for(pred = head, temp = head->next; temp != NULL && !(temp->info >= element); pred = pred->next, temp = temp->next);
                if(temp->info >= element) {
                    //insert before temp and after pred
                    temp->prev = pred->next = new Node<T>(element);
                    pred->next->next = temp;
                    pred->next->prev = pred;
                }
            }
        }
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

	void printList() {
		Node<T>* temp;
		std::cout << "Head <-> ";
		for(temp = head; temp != nullptr; temp = temp->next) {
			std::cout << temp->info << " <-> ";
		}
		std::cout << "NULL\n";
	}

	DLL<T> operator+ (const DLL<T>& list) {
		DLL<T> merged_list;
		Node<T>* first = this->head;
		Node<T>* second = list.head;
		while(first != NULL && second != NULL) {
			if(first->info <= second->info) {
				merged_list.addToTail(first->info);
				first = first->next;
			}
			else {
				merged_list.addToTail(second->info);
				second = second->next;
			}
		}
		while(first != NULL) {
			merged_list.addToTail(first->info);
			first = first->next;
		}
		while(second != NULL) {
			merged_list.addToTail(second->info);
			second = second->next;
		}
		return merged_list;
	}
};

int main() {
	DLL<int> list1;
	DLL<int> list2;
	DLL<int> merged_list;
	const int size1 = 5;
	const int size2 = 6;
	int array1[] = {10,4,7,13,20};
	int array2[] = {14,50,32,24,67,89};
	std::sort(array1,array1+size1);
	std::sort(array2, array2+size2);

	for(int i=0;i<size1;i++) list1.addToTail(array1[i]);
	std::cout << "LIST 1: ";
	list1.printList();
	for(int i=0;i<size2;i++) list2.addToTail(array2[i]);
	std::cout << "LIST 2: ";
	list2.printList();

	std::cout << "These are two ordered linked lists. What do you want to do? (1-3)\n";
	std::cout << "1. Insertion (in the first list)\n";
	std::cout << "2. Deletion (in the first list)\n";
	std::cout << "3. Merge the two lists\n";
	int option; char ans = 'y';
	do {
		std::cout << "Enter your choice: ";
		std::cin >> option;
		switch(option) {
			case 1: {
				double element;
				std::cout << "Enter element to insert; ";
				std::cin >> element;
				list1.insert(element);
				std::cout << "Updated list: ";
				list1.printList();
				break;
			}
			case 2: {
				double element;
				std::cout << "Enter element to delete; ";
				std::cin >> element;
				list1.deleteNode(element);
				std::cout << "Updated list: ";
				list1.printList();
				break;
			}
			case 3: merged_list = list1 + list2; std::cout << "Merged list: "; merged_list.printList(); break;
			default: std::cout << "Invalid option\n";
		}
		std::cout << "Do you want to continue?(y/n): ";
		std::cin >> ans;
	} while(ans == 'y' || ans == 'Y');
}
