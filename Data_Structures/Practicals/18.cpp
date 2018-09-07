#include<iostream>
class DiagonalMatrix {
private:
	int size;
	int* elements;
public:
	DiagonalMatrix(int size) {
		this->size = size;
		elements = new int[size];
		for(int i=0;i<size;i++) elements[i] = 0;
	}
	int get_element(int i, int j) const {
		if(i<0 || j<0 || i>=size || j>=size) return 0;
		else if(i == j) return elements[i];
		return 0;
	}
	void set_element(int i, int j, const int& elem) {
		if(i<0 || j<0 || i>=size || j>=size) return;
		else if(i==j) elements[i] = elem;
		else if(elem != 0) std::cout << "Non-diagonal elements must be zero.\n";
	} 
	~DiagonalMatrix() { delete[] elements; }
};

int main() {
	DiagonalMatrix dm(3);
	dm.set_element(0,0,1);
	dm.set_element(1,1,2);
	dm.set_element(2,2,3);

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++)
		std::cout << dm.get_element(i,j) << " ";
		std::cout << std::endl;
	}
}
