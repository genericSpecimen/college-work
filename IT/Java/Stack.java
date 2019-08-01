import java.util.ArrayList;

abstract class Stack {
	abstract void push(int x);
	abstract int pop();
	abstract void display();
}

class StaticStack extends Stack {
	int[] stack;
	int size, top;
	StaticStack(int size) {
		stack = new int[size];
		this.size = size;
		System.out.pritnln("Initialised a stack of size " + this.size);
	}

	void push(int x) {
		System.out.println("Pushed " + x);
	}

	int pop() {
		System.out.println("Popped ");
		return 0;
	}
}

class StackDriver {
	public static void main(String[] args) {
		StaticStack s_stack = new StaticStack(5);
		s_stack.push(13);
		s_stack.pop();
	}
}
