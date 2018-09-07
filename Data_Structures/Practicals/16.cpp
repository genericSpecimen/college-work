#include "stack.h"
template <typename T>
void reverse(Stack<T>& s) {
	Stack<T> rev;
	while(!s.isEmpty()) {
		rev.push(s.pop());
	}
	rev.printStack();
}

int main() {
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.printStack();
	reverse(s);
}
