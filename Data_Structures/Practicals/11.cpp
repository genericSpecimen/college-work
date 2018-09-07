#include<iostream>
#include<string>
long int fact(unsigned long int num) {
	if(num < 0) return -1;
	else if(num == 0) return 1;
	else return num*fact(num-1);
}

long int factIterative(unsigned long int num) {
	double fact=1;
	for(unsigned int i=num;i>=1;i--) {
		fact *= i;
	}
	return fact;
}

void compute_factors(unsigned long int num) {
	for(int i=1;i<=num/2;i++) {
		if(num % i == 0) std::cout << i << ",";
	}
	std::cout << std::endl;
}


int main() {
	int num=9;
	std::cout << "Factorial of " << num  << " is: " << fact(num) << std::endl;
	std::cout << "Factors of 100: ";
	compute_factors(100);
	std::cout << std::endl;
}
