#include<iostream>

class UpperTriangularMatrix {
private:
	int* elements;
public:
	int size;
	UpperTriangularMatrix(int size) {
		this->size = size;
		elements = new int[size*(size+1)/2];
	}

	void set_element(int i, int j, const int& elem) {
		if(i<0 || j<0 || i>=size || j>=size) return;
		if(i<=j) elements[size*i - i*(i-1)/2 + j-i] = elem;
	}

	int get_element(int i, int j) {
		if(i<0 || j<0 || i>=size || j>=size) return 0;
		if(i<=j) return elements[size*i - i*(i-1)/2 + j-i];
		return 0;
	}
	~UpperTriangularMatrix() { delete[] elements; }
};

int main() {
	UpperTriangularMatrix utm(3);
	utm.set_element(0,0,1);
	utm.set_element(1,1,2);
	utm.set_element(2,2,3);
	
	utm.set_element(0,1,4);
	utm.set_element(1,2,5);
	utm.set_element(0,2,6);

	for(int i=0;i<utm.size;i++) {
		for(int j=0;j<utm.size;j++)
			std::cout << utm.get_element(i,j) << " ";
		std::cout << std::endl;
	}
}
