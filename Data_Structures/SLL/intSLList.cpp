#include <iostream>
#include "intSLList.h"

List::~List() {
	
	/*
	 * while the list is not empty,
	 * 1. Store the next of head.
	 * 2. delete the head.
	 * 3. reassign the head to the stored pointer.
	 */

	for(Node* p; !isEmpty();) {
		p = head->next;
		delete head;
		head = p;
	}
}

void List::addToHead(int element) {
	/*
	 * 1. Create a new node whose 'next' points to the current head and assign it to 'head'.
	 * 2. Check if tail==0, i.e. if the list was empty. If so, assign new 'head' to 'tail'.
	 */

	head = new Node(element, head);
	if(tail == 0) tail = head;
}

void List::addToTail(int element) {
	/*
	 * 1. if list is not empty, assign a new node to tail->next, then assign tail->next to tail.
	 * 2. if list is empty, create a new node and assign it to head and tail.
	 */

	if(tail != 0) {
		tail->next = new Node(element);
		tail = tail->next;
	}
	else head = tail = new Node(element);
}

int List::deleteFromHead() {
	/*
	 * 1. Store the data of head to later return it.
	 * 2. assign 'head' to a temp Node pointer.
	 * 3. if only one node is present, i.e. head == tail then assign 0 to both.
	 *    else, assign head->next to head.
	 * 4. delete temp and return stored data.
	 */

	int element = head->info;
	Node* temp = head;
	if(head == tail) head = tail = 0;
	else head = head->next;
	delete temp;
	return element;
}

int List::deleteFromTail() {
	/*
	 * 1. Store the data of tail to later return it.
	 * 2. if only one node present, i.e. head == tail, delete head and assign head=tail=0;
	 * 3. if more than one node present:
	 * 	find the predecessor of tail
	 * 	delete tail and assign the predecessor of tail to tail.
	 * 	assign 0 to tail->next
	 * 4. return stored data
	 */

	int element = tail->info;
	if(head == tail) {
		delete head;
		head = tail = 0;
	}
	else {
		//find predecessor of tail
		Node* temp;
		for(temp = head; temp->next != tail; temp = temp->next);
		
		delete tail;
		tail = temp;
		tail->next = 0;
	}
	return element;
}

void List::deleteNode(int element) {
	if(head != 0) {
		if(head == tail && element == head->info) { //only one node
			delete head;
			head = tail = 0;
		}
		else if(element == head->info) { //more than one node, old head deleted
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else { //more than one node, nonhead node deleted
			/*
			 * Node pointer temp will keep track of the node to be deleted.
			 *
			 * Node pointer pred will keep track of the node before
			 * the node to be deleted so that IF we find the node
			 * to be deleted we can link pred->next to temp->next
			 * since temp needs to be deleted.
			 *
			 *
			 * We traverse through the linked list until:
			 *  1. temp points to null (element not found)
			 *  2. temp->info == element (element found)
			 *
			 * if temp != 0 then element must've been found and temp points to it. Now
			 *  pred->next = temp->next;
			 * if (temp == tail), i.e. element to be deleted is the tail, then new tail
			 * is pred.
			 */ 
			Node* pred;
			Node* temp;
			for(pred = head, temp = head->next;
			    temp != 0 && !(temp->info == element);
			    pred = pred->next, temp = temp->next);
			if(temp != 0) {
				pred->next = temp->next;
				if(temp == tail) tail = pred;
				delete temp;
			}
		}
	}
}

bool List::isInList(int element) const {
	Node* temp;
	for(temp = head; temp != 0 && !(temp->info == element); temp = temp->next);

	return temp!=0;
}

void List::printList() const {
	Node* temp;
	std::cout << "head -> ";
	for(temp = head; temp!=0; temp = temp->next)
		std::cout << temp->info << " -> ";
	std::cout << "NULL\n";
}

int main() {
	List list;
	std::cout << "List is empty: " << std::boolalpha << list.isEmpty() << std::endl;
	list.addToHead(10);
	list.addToHead(20);
	list.addToHead(30);
	list.addToHead(40);
	list.addToHead(50);

	list.addToTail(-10);
	list.addToTail(-20);
	
	list.deleteFromHead();
	list.deleteFromTail();

	list.deleteNode(30);
	list.printList();
	std::cout << "10 is in list: " << std::boolalpha << list.isInList(10) << std::endl;
	std::cout << "List is empty: " << std::boolalpha << list.isEmpty() << std::endl;
}
