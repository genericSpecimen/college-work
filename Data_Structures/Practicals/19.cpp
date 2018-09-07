#include<iostream>

class LowerTriangularMatrix {
private:
	int* elements;
public:
	int size;
	LowerTriangularMatrix(int size) {
		this->size = size;
		elements = new int[size*(size+1)/2];
	}

	void set_element(int i, int j, const int& elem) {
		if(i<0 || j<0 || i>=size || j>=size) return;
		if(i>=j) elements[i*(i+1)/2 + j] = elem;
	}

	int get_element(int i, int j) {
		if(i<0 || j<0 || i>=size || j>=size) return 0;
		if(i>=j) return elements[i*(i+1)/2 + j];
		return 0;
	}
	~LowerTriangularMatrix() { delete[] elements; }
};

int main() {
	LowerTriangularMatrix ltm(3);
	ltm.set_element(0,0,1);
	ltm.set_element(1,1,2);
	ltm.set_element(2,2,3);
	
	ltm.set_element(1,0,4);
	ltm.set_element(2,0,6);
	ltm.set_element(2,1,5);

	for(int i=0;i<ltm.size;i++) {
		for(int j=0;j<ltm.size;j++)
			std::cout << ltm.get_element(i,j) << " ";
		std::cout << std::endl;
	}
}
