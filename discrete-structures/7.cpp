#include<iostream>
int binarySearch(int a[],int l,int h,int element) {
	if(h >= l) {
		int low = l; int high = h;
		int mid = (low+high)/2;
		if(a[mid] == element)
			return mid;
		else if(a[mid] < element)
			return binarySearch(a,mid+1,h,element);
		else
			return binarySearch(a,l,mid-1,element);
	}
	return -1;
}

int main() {
	int a[] = {1,2,3,4,5,6,7,29};
	int size = sizeof(a)/sizeof(a[0]);
	std::cout << "\nElement found at index location: " << binarySearch(a,0,size,8) << '\n';
}