#include<iostream>
template <class T, int m_size, int num_elements>
class LowerTriangularMatrix {
public:
    T elements[num_elements];
	LowerTriangularMatrix() {
        for(int i=0;i<num_elements;i++) elements[i] = 0;
	}

	void set(int i, int j, T elem) {
		if(i<0 || j<0 || i >= m_size || j >= m_size)
            throw std::out_of_range("matrix indices out of range");
		if(i >= j) elements[i*(i+1)/2 + j] = elem;
	}

	T get(int i, int j) const {
		if(i<0 || j<0 || i >= m_size || j >= m_size)
            throw std::out_of_range("matrix indices out of range");
		if(i >= j) return elements[i*(i+1)/2 + j];
		return 0; //all other elements are 0
	}
};

int main() {
    const int m_size = 3; //size of matrix
    const int num_elements = m_size*(m_size + 1)/2;
	LowerTriangularMatrix<int, m_size, num_elements> ltm;
	ltm.set(0,0,1);
	ltm.set(1,1,2);
	ltm.set(2,2,3);
	
	ltm.set(1,0,4);
	ltm.set(2,0,6);
	ltm.set(2,1,5);

    for(int i=0;i<m_size;i++) {
        for(int j=0;j<m_size;j++)
            std::cout << ltm.get(i,j) << "\t";
        std::cout << std::endl;
    }
}
