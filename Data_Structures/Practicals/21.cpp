#include<iostream>

class SymmetricMatrix {
private:
	int* elements;
public:
	int size;
	SymmetricMatrix(int size) {
		this->size = size;
		elements = new int[size*(size+1)/2];
	}
	void set_element(int i, int j, const int& elem) {
		if(i<0 || j<0 || i>=size || j>=size) return;
		if(i<j) set_element(j,i,elem);
		else if(i>=j) elements[i*(i+1)/2+j] = elem;
	}
	int get_element(int i, int j) {
		if(i<0 || j<0 || i>=size || j>=size) return 0;
		if(i<j) return get_element(j,i);
		else if(i>=j) return elements[i*(i+1)/2+j];
		return 0;
	}
	~SymmetricMatrix() { delete[] elements; }
};

int main() {
	SymmetricMatrix sm(3);
	sm.set_element(0,0,1);
	sm.set_element(1,1,2);
	sm.set_element(2,2,3);
	sm.set_element(1,0,4);
	sm.set_element(2,0,6);
	sm.set_element(2,1,5);

	for(int i=0;i<sm.size;i++) {
		for(int j=0;j<sm.size;j++) std::cout << sm.get_element(i,j) << " ";
		std::cout << std::endl;
	}
}
