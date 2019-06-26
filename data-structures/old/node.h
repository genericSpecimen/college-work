#pragma once
template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node(T data, Node<T>* next=NULL) {
		this->data = data;
		this->next = next;
	}
};
