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
		this.top = -1;
		System.out.println("Initialised stack of size: " + this.size);
	}

	void push(int x) {
		if(top < this.size-1) {
			stack[++top] = x;
			System.out.println("=> Pushed " + x);
		} else System.out.println("Error: Stack overflow!");
	}

	int pop() {
		if(top < 0) {
			System.out.println("Error: Stack underflow!");
			return 0;  
		} else {
			int x = stack[top--];
			return x;
		}
	}

	void display() {
		System.out.println("\nCurrent Stack is: ");
		for(int i = top; i >= 0; i--) {
			if (i == top) System.out.println(stack[i] + " (TOP)");	
			else System.out.println(stack[i]);
		}
		System.out.println("\n");
	}
}

class StackDriver {
	public static void main(String[] args) {
		StaticStack s_stack = new StaticStack(5);
		s_stack.push(120);
		s_stack.push(10);
		s_stack.push(1);
		s_stack.push(100);
		s_stack.push(99);
		
		s_stack.push(10);

		s_stack.display();
		
		int popped = s_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = s_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = s_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = s_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = s_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = s_stack.pop();
		System.out.println("=> Popped: " + popped);
	}
}
