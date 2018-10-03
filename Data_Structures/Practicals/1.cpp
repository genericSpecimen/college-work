#include<iostream>
template<typename T>
void insertion_sort(T a[], int size) {
	for(int i=1;i<size;i++) {
		T key = a[i];
		int j = i-1;
		while(j>=0 && key < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

template<typename T>
void printArray(T a[], int size) {
	for(int i=0;i<size;i++) std::cout << a[i] << " ";
	std::cout << std::endl;	
}

template<typename T>
int linear_search(T a[], int size, T key) {
	for(int i=0;i<size;i++) {
		if(a[i] == key) return i;
	}
	return -1;
}

template<typename T>
int binary_search(T a[], int low, int high, T key) {
	if(low < high) {
		int mid = low + (high-low)/2;
		if(a[mid] == key) return mid;
		else if(a[mid] > key) return binary_search(a,low,mid-1,key);
		else if(a[mid] < key) return binary_search(a,mid+1,high,key);
	}
	return -1; //if not found
}


int main() {
	int a[] = {10,31,5,11,24,68,34,69,90,15};
	int size = 10;
	int op;
	std::cout << "How do you want to search?";
	std::cout << "\n1. Linear Search";
	std::cout << "\n2. Binary Search";
	std::cout << "\nEnter your option (1-2): ";
	std::cin >> op;
	switch(op) {
		case 1: std::cout << "Element found at index: " << linear_search(a,10,69) << std::endl; break;
		case 2: insertion_sort(a,size); std::cout << "Element found at index: " << binary_search(a,0,9,69) << std::endl; break;
		default: std::cout << "Invalid option!\n";
	}
}
