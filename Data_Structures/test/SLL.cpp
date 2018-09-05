#include<iostream>

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;	
	}
};

class SLL {
private:
	Node* head;
public:
	SLL() {
		head = NULL;
	}
	void insert_at_head(int data) {
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
	void insert_at_tail(int data) {
		if(head != NULL) { //non-empty list
			Node* temp;
			for(temp=head; temp->next!=NULL;temp=temp->next); //temp points to the last element after this
	       		temp->next = new Node(data);
			temp->next->next = NULL;

		}
		else {
			//list is empty
			head = new Node(data);
			head->next = NULL;
		}
	}

	void insert_after(int data, int element) {
		if(head == NULL) return; //empty list
		Node* temp;
		for(temp=head; temp!=NULL && temp->data != data; temp=temp->next);
		Node* nextelement = temp->next;
		temp->next = new Node(element);
		temp->next->next = nextelement;
	}

	int delete_head() {
		try {
			if(head == NULL) throw("Empty list, can't perform deletion");
			if(head->next == NULL) {//only one node
				int data = head->data;
				delete head;
				head = NULL;
				return data;
			}
			else { //more than one node
				int data = head->data;
				Node* temp = head;
				head = head->next;
				delete temp;
				return data;
			}

		} catch(const char* s) {
			std::cerr << "Error: " << s << std::endl;
		}
		return 0;
	}

	int delete_node(int data) {
		try {
			if(head == NULL) throw("Empty List, can't perform deletion");
			else if(head->data == data) {
				int data = head->data;
				Node* temp = head;
				head = head->next;
				delete temp;
				temp = NULL;
				return data;
			}
			else {
				Node* pred;
				Node* temp;
				for(pred=head, temp=head->next; temp!=NULL && !(temp->data==data); pred=pred->next, temp=temp->next);
				if(temp!=NULL) {
					int data = temp->data;
					pred->next = temp->next;
					delete temp;
					return data;
				}

			}
		} catch(const char* s) {
			std::cerr << "Error: " << s << std::endl;
		}
		return 0;
	}

	void change() {
		if(head==NULL) { std::cout << "Error: Empty list\n"; return; }
		if(head->next == NULL) { std::cout << "Error: Two nodes must exist\n"; return; }
		Node* temp = head;
		head->next=NULL;
		head = head->next;
		//find last node and link it's next pointer to temp
		Node* last;
		for(last = head; last->next!=NULL; last=last->next);
		last->next = temp;
		
	}
	void print_list() {
		std::cout << "HEAD -> ";
		for(Node* temp = head; temp!=NULL; temp=temp->next)
			std::cout << temp->data << " -> ";
		std::cout << "NULL\n";
	}
};

int main(int argc, char* argv[]) {
	SLL list;
	list.print_list();
	list.insert_at_tail(100);
	list.print_list();
	std::cout << "Deleted node containing data: " << list.delete_head() << std::endl;
	list.print_list();
	list.delete_node(10);
	
	std::cout << "-----------------------------------";
	list.insert_at_head(10);
	list.insert_at_head(20);
	list.insert_at_head(30);
	list.print_list();

	list.insert_at_tail(40);
	list.insert_at_tail(50);
	list.insert_at_tail(60);
	list.insert_at_tail(70);
	list.print_list();
	list.insert_after(30,100);
	list.print_list();
	std::cout << "Deleted element: " << list.delete_node(100) << std::endl;
	list.print_list();
	list.change();
	list.print_list();
}
