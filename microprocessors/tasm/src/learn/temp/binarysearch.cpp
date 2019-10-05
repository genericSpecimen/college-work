#include <iostream>

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int key = 1;
	int low = 0, high = 9;
	int mid;
	std::cin >> key;
	while(low <= high) {
		mid = (low+high)/2;
		if(arr[mid] == key) { std::cout << "Found at index: " << mid << std::endl; break; }
		else if(arr[mid] < key) low = mid+1;
		else high = mid-1;
	}
}
