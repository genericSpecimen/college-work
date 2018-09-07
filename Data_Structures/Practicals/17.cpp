#include "stack.h"
#include "queue.h"

template<typename T>
void reverse(Queue<T> q) {
	Stack<T> temp;
	while(!q.isEmpty()) {
		temp.push(q.dequeue());
	}
	Queue<T> rev;
	while(!temp.isEmpty()) {
		rev.enqueue(temp.pop());
	}
	rev.printQueue();
}

int main() {
	Queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.printQueue();
	reverse(q);
}
