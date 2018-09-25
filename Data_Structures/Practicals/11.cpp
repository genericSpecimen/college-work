#include<iostream>
#include<string>
long long int fact(unsigned long long int num) {
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
	std::cout << num << ",";
	std::cout << std::endl;
}

void compute_factors_recursive(unsigned long int n, unsigned long int i) {
	if(i == 0) return;
	if(n%i == 0) std::cout << i << ", ";
	return compute_factors_recursive(n,i-1);
}

int main() {
	unsigned long int num;
	std::cout << "Enter an integer to calculate its factorial and its factors: ";
	std::cin >> num;
	std::cout << "Factorial of " << num  << " is: " << fact(num) << std::endl;
	std::cout << "Factors of " << num << ": ";
	compute_factors(num);
	std::cout << "Factors of " << num << " (recursively): ";
	compute_factors_recursive(num, num);
	std::cout << std::endl;
}
