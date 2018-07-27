#include<iostream>
#include<cmath>
bool isMember(int a[],int size,int element) {
	for(int i=0;i<size;i++) {
		if(a[i] == element)
			return true;
	}
	return false;
}

void printArray(int a[], int size) {
	std::cout << "The array is: ";
	for(int i=0;i<size;i++) 
		std::cout << a[i] << ',';
	std::cout << '\n';
}

void powerSetA(int a[],int size) {
	int powSize = pow(2,size);
	std::cout << "\nThe power set of A is: {";
	for(int i=0;i<powSize-1;i++) {
		std::cout << "{";
		for(int j=0;j<size;j++) {
			if(i & (1 << j))
				std::cout << a[j] << ',';
		}
		std::cout << "},";
	}
	std::cout << "}\n";
}

int main() {
	int num, option;
	char ans = 'y';
	std::cout << "Enter the number of elements of the set: ";
	std::cin >> num;
	int cardinality = num;
	int* setA = new int[num];

	std::cout << "Enter the elements: ";
	for(int i=0;i<num;i++)
		std::cin >> setA[i];
	
	do {
		std::cout << "\nWhat do you want to do?";
		std::cout << "\n1. Print set A.";
		std::cout << "\n2. Check if an element is a member of set A.";
		std::cout << "\n3. Display the power set of A.";
		std::cout << "\n4. Re-enter elements.";
		std::cout << "\nEnter your option: ";
		std::cin >> option;
		
		switch(option) {
			case 1: printArray(setA,cardinality); break;
			case 2:
				std::cout << "\nEnter the element to be checked: ";
				int elem;
				std::cin >> elem;
				if(isMember(setA,cardinality,elem))
				std::cout << "Yes, it is a member of set A.\n";
				else
					std::cout << "No, it is not a member of set A.\n";
				break;
			case 3: powerSetA(setA,cardinality); break;
			case 4: std::cout << "Enter the elements: ";
					for(int i=0;i<num;i++)
					std::cin >> setA[i];
					break;			
		}
		std::cout << "\nDo you want to continue? (y/n): ";
		std::cin >> ans;
	} while(ans == 'y' || ans == 'Y');
	delete[] setA;
}