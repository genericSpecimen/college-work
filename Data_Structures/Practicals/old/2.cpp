#include<iostream>

template<typename T>
void printArray(T a[], int size) {
	for(int i=0;i<size;i++) std::cout << a[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void swap(T& num1, T& num2) {
	T temp = num1;
	num1 = num2;
	num2 = temp;
}

template<typename T>
void insertion_sort(T a[], int size) {
	for(int i=1;i<size;i++) {
		T key = a[i];
		int j = i-1;
		while(j >= 0 && key < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

template<typename T>
void bubble_sort(T a[], int size) {
	bool swapped = false;
	for(int i=0;i<size;i++) {
		swapped = true;
		for(int j=0;j<size-1-i;j++) {
			if(a[j] > a[j+1]) {
				swap(a[j],a[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}

template<typename T>
void selection_sort(T a[], int size) {
	int min;
	for(int i=0;i<size-1;i++) {
		min = i;
		for(int j=i+1;j<size;j++) {
			if(a[j] < a[min]) min = j;
		}
		if(min != i) swap(a[i],a[min]);
	}
}


int main() {
	int a[] = {19,1,5,100,95,24,68,70};
	int size = 8;
	int op;
	std::cout << "How do you want to sort?\n";
	std::cout << "1. Bubble Sort\n";
	std::cout << "2. Selection Sort\n";
	std::cout << "3. Insertion Sort\n";
	std::cout << "Enter your option (1-3): ";
	std::cin >> op;
	switch(op) {
		case 1: bubble_sort(a,size); printArray(a,size); break;
		case 2: selection_sort(a,size); printArray(a,size); break;
		case 3: insertion_sort(a,size); printArray(a,size); break;
		default: std::cout << "Invalid option!\n";
	}

}
