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

	bool is_page_in_frame(T key) {
        if(!isEmpty()) {
            if(head->info == key || tail->info == key) return true;
		    Node<T>* temp;
		    for(temp=head; temp!=NULL; temp=temp->next) {
			    if(temp->info == key) return true;
		    }
        }
		return false;
	}

	DLL<T> reverseList() {
		DLL<T> rList;
		for(Node<T>* temp = head; temp != NULL; temp = temp->next) {
			rList.addToHead(temp->info);
		}
		return rList;
	}

	void printList() {
		Node<T>* temp;
		for(temp = head; temp != nullptr; temp = temp->next) {
			std::cout << temp->info << " ";
		}
		std::cout << " <- Tail (LRU page)\n";
	}

};

int main() {
    std::string reference_string("70120304230321201701");
    const int frame_size = 3;
    int num_page_faults = 0;
    
    DLL<int> page_stack;
    std::cout << "Reference string: " << reference_string << std::endl;
	std::cout << "Frame size: " << frame_size << std::endl;

    int counter = 0; //keeps track of number of pages in frame
    for(int i=0;i<reference_string.length();i++) {
        int current_page = reference_string[i]-'0';
        if(counter < frame_size) {
            if(page_stack.is_page_in_frame(current_page)) {
                //do nothing
                std::cout << "Page " << current_page;
                std::cout << " =>  No page fault => ";
                page_stack.printList();
            } else {
                std::cout << "Page " << current_page;
                std::cout << " =>  1 Page fault  => ";
                page_stack.addToHead(current_page);
                counter++;
                num_page_faults++;
                page_stack.printList();
            }
        } else {
            if (page_stack.is_page_in_frame(current_page)) {
                //remove from stack and put it on top to signify it has been used recently
                page_stack.deleteNode(current_page);
                page_stack.addToHead(current_page);
                std::cout << "Page " << current_page;
                std::cout << " =>  No page fault => ";
                page_stack.printList();
            } else {
                //page fault: remove the LRU page and add the current_page to the head of the stack
                page_stack.deleteFromTail();
                page_stack.addToHead(current_page);
                std::cout << "Page " << current_page;
                std::cout << " =>  1 Page fault  => ";
                page_stack.printList();
                num_page_faults++;
            }
        }
    }
    std::cout << "Total number of page faults: " << num_page_faults << std::endl;
}
