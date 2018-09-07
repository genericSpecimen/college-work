#include<iostream>

unsigned long long int fib_itr(unsigned long int num) {
	if(num < 2) return num;
	long int i = 2, last = 0, current = 1, temp;
	while(i<=num) {
		temp = current;
		current += last;
		last = temp;
		i++;
	}
	return current;
}

unsigned long long int fib_rec(unsigned long int num) {
	if(num < 0) return -1;
	if(num == 0 || num == 1) return num;
	return fib_rec(num-1) + fib_rec(num-2);
}

int main() {
	for(int i=0;i<10;i++) std::cout << fib_itr(i) << " ";
	std::cout << std::endl;
	for(int i=0;i<10;i++) std::cout << fib_rec(i) << " ";
	std::cout << std::endl;
}
