#include<iostream>

class Node {
public:
	int data;
	Node* next;
	Node() {
		next = nullptr;
	}
	Node(int data, Node* ptr=nullptr) {
		this->data = data;
		this->next = ptr;
	}
};

class Stack {
private:
	Node* head;
	Node* tail;
public:
	Stack() {
		head = tail = nullptr;
	}
	bool isEmpty() {
		return head==nullptr;
	}
	void push(int element) {
		/*
		 * if stack is empty, create a new node and assign it to head and tail
		 * else, create a new node and assign it to tail->next and then assign tail->next to tail.
		 */
		if(this->isEmpty()) {
			head = tail = new Node(element);
		}
		else {
			tail->next = new Node(element);
			tail = tail->next;
		}
	}

	int pop() {
		if(!this->isEmpty()) {
			int data = tail->data;
			/*
			 * todo: if stack isn't empty, pop the tail.
			 * how to do:
			 * if head==tail, i.e. only one node, delete the head and assign head=tail=nullptr
			 * if more than one node, find predecessor of tail pred and assign pred->next = nullptr
			 * 	delete tail; tail = pred;
			 */
			if(head == tail) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node* pred; //Node pointer to keep track of predecessor of tail
				for(pred = head; pred->next != tail; pred = pred->next);

				pred->next = nullptr;
				delete tail;
				tail = pred;
			}
			return data;
		}
		return 0; //return 0 if stack is empty
	}

	void printStack() {
		Node* temp;
		std::cout << "Head -> ";
		for(temp = head; temp != nullptr; temp = temp->next) {
			std::cout << temp->data << " -> ";
		}
		std::cout << "NULL\n";
	}
};

int main() {
	Stack s;
	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	s.printStack();
	std::cout << "Popped: " << s.pop() << std::endl;
	s.printStack();
}
