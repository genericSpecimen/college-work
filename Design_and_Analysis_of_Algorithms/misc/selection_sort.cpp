#include <iostream>

void selection_sort(int a[], int size) {
	for(int i=0;i<size-1;i++) {
		// place the minimum element from the unsorted subarray into a[i]
		int min = i;
		for(int j=i+1;j<size;j++) {
			if(a[j] < a[min]) min = j; 
		}
		if(min != i) std::swap(a[i], a[min]);
	}
}

int main() {
	int a[] = {5,4,2,3,1,6};
	int size = 5;
	selection_sort(a,5);
	for(int x:a) std::cout << x << " ";
	std::cout << std::endl;
}
