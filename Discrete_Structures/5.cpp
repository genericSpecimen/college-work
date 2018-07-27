#include<iostream>
void fibRecursive(int t1, int t2, int numOfTerms) {
	if(numOfTerms > 0){
		int t3 = t1+t2;
		std::cout << t3 << ',';
		fibRecursive(t2,t3,--numOfTerms);
	}
}

int main() {
	int num;
	std::cout << "Enter the number of terms to be displayed: ";
	std::cin >> num;
	if(num == 1)
		std::cout << "0";
	else if(num == 2)
		std::cout << "0,1";
	else if(num != 0) {
		std::cout << "0,1,";
		num -= 2;
		fibRecursive(0,1,num);
	}
	std::cout << '\n';
}