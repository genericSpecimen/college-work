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
		System.out.println("Initialised static stack of size: " + this.size);
	}

	void push(int x) {
		if(top < this.size-1) {
			stack[++top] = x;
			System.out.println("=> Pushed " + x);
		} else System.out.println("Error: Stack overflow!");
	}

	int pop() {
		if(top < 0) {
			System.out.printf("%s", "Error: Stack underflow! ");
			return 0;  
		} else {
			int x = stack[top--];
			return x;
		}
	}

	void display() {
		System.out.println("Current stack:");
		for(int i = top; i >= 0; i--) {
			if (i == top) System.out.println(stack[i] + " (TOP)");	
			else System.out.println(stack[i]);
		}
		System.out.println();
	}
}

class DynamicStack extends Stack {
	ArrayList<Integer> stack;
	DynamicStack() {
		stack = new ArrayList<Integer>();
	}

	void push(int x) {
		stack.add(x);
		System.out.println("=> Pushed " + x);
	}

	int pop() {
		if(stack.isEmpty()) {
			System.out.printf("%s", "Error: Stack underflow! ");
			return 0;
		}
		int top = stack.size() - 1;
		int popped = stack.get(top);
		stack.remove(top);
		return popped;
	}

	void display() {
		System.out.println("Current stack:");
		for(int i = stack.size()-1; i >= 0; i--) {
			if(i == stack.size()-1) System.out.println(stack.get(i) + " (TOP)");
			else System.out.println(stack.get(i));
		}
		System.out.println();	
	}
}

class StackDriver {
	public static void main(String[] args) {
		System.out.println("----------Static Stack------------");
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
		System.out.println("----------------------------------\n");
		
		System.out.println("----------Dynamic Stack------------");
		DynamicStack d_stack = new DynamicStack();
		d_stack.push(10);
		d_stack.push(20);
		d_stack.push(30);
		d_stack.push(40);

		d_stack.display();
		
		popped = d_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = d_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = d_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = d_stack.pop();
		System.out.println("=> Popped: " + popped);
		popped = d_stack.pop();
		System.out.println("=> Popped: " + popped);
		System.out.println("----------------------------------");


	}
}
