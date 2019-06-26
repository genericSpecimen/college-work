#include <iostream>

void print_array(int a[], int size) {
	for(int i=0;i<size;i++) std::cout << a[i] << " ";
	std::cout << std::endl;
}

void rotate_left_by_one(int a[], int size) {
	int key = a[0];
	for(int i=0;i<size-1;i++) {
		a[i] = a[i+1];
	}
	a[size-1] = key;
}

void rotate_left_by_d(int a[], int size, int d) {
	while(d--) rotate_left_by_one(a,size);
}

int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int size = 10;
	int d = 2;
	std::cin >> d;
	print_array(a,size);
	rotate_left_by_d(a,size,d);
	print_array(a,size);
}
