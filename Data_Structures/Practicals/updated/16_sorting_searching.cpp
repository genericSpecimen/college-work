#include<iostream>

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

void merge(int a[], int p, int q, int r) {
	int n1 = q-p+1;
	int n2 = r-q;
	int lowHalf[n1]; int highHalf[n2];
	
	for(int i=0;i<n1;i++) lowHalf[i] = a[p+i];
	for(int j=0;j<n2;j++) highHalf[j] = a[q+1+j];
	//merge lowHalf and highHalf into a[p..r]
	int i=0,j=0; //initial index of lowHalf and highHalf
	int k=p; //initial index of merged array
	while(i<n1 && j<n2) {
		if(lowHalf[i] <= highHalf[j]) a[k++] = lowHalf[i++];
		else a[k++] = highHalf[j++];
	}
	while(i<n1) a[k++] = lowHalf[i++];
	while(j<n2) a[k++] = highHalf[j++];
}

void merge_sort(int a[], int p, int r) {
	if(p<r) {
		int q = p + (r-p)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

int partition(int a[], int p, int r) {
	int pivot = a[r]; //element to be placed at correct position
	//std::cout << "Partitioned with pivot: " << pivot << std::endl;
	int i = p-1; //keeps track of the smaller element
	for(int j=p;j<r;j++) {
		if(a[j] <= pivot) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

void quick_sort(int a[], int p, int r) {
	if(p < r) {
		int q = partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}

int main() {
	int a[] = {10,31,5,11,24,68,34,69,90,15};
	int size = 10;
	int option;
    char ans = 'y';
    std::cout << "Array: ";
    printArray(a,size);
	std::cout << "Searching and sorting algorithms\n";
	std::cout << "1. Bubble sort\n";
	std::cout << "2. Insertion sort\n";
	std::cout << "3. Selection sort\n";
	std::cout << "4. Merge sort\n";
	std::cout << "5. Quick sort\n";
	std::cout << "6. Linear search\n";
	std::cout << "7. Binary search\n";
	do {
        std::cout << "\nEnter your option (1-7): ";
        std::cin >> option;
        switch(option) {
            case 1: bubble_sort(a,size); std::cout << "Sorted: "; printArray(a,size); break;
            case 2: insertion_sort(a,size); std::cout << "Sorted: "; printArray(a,size); break;
            case 3: selection_sort (a,size); std::cout << "Sorted: "; printArray(a,size); break;
            case 4: merge_sort(a,0,size-1); std::cout << "Sorted: "; printArray(a,size); break;
            case 5: quick_sort(a,0,size-1); std::cout << "Sorted: "; printArray(a,size); break;
            case 6: {
                std::cout << "Enter the element to be searched for: ";
                int element;
                std::cin >> element;
                std::cout << "Element found at index: " << linear_search(a,10,element) << std::endl; break;
            }
            case 7: {
                std::cout << "Enter the element to be searched for: ";
                int element;
                std::cin >> element;
                insertion_sort(a,size);
                std::cout << "Sorted: ";
                printArray(a,size);
                std::cout << "Element found at index: " << binary_search(a,0,9,element) << std::endl; break;
            }
            default: std::cout << "Invalid option!\n";
        }
        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> ans;
    } while(ans == 'y' || ans == 'y');
}
