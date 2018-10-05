#include<iostream>
template <class T, int m_size, int num_elements>
class UpperTriangularMatrix {
public:
    T elements[num_elements];
	UpperTriangularMatrix() {
        for(int i=0;i<num_elements;i++) elements[i] = 0;
	}

	void set(int i, int j, T elem) {
		if(i<0 || j<0 || i >= m_size || j >= m_size)
            throw std::out_of_range("matrix indices out of range");
		if(i <= j) elements[m_size*i - i*(i-1)/2 + j-i] = elem;
	}

	T get(int i, int j) const {
		if(i<0 || j<0 || i >= m_size || j >= m_size)
            throw std::out_of_range("matrix indices out of range");
		if(i <= j) return elements[m_size*i - i*(i-1)/2 + j-i];
		return 0; //all other elements are 0
	}
};

int main() {
    const int m_size = 3;
    const int num_elements = m_size*(m_size + 1)/2;
	UpperTriangularMatrix<int, m_size, num_elements> utm;
	utm.set(0,0,1);
	utm.set(1,1,2);
	utm.set(2,2,3);
	
	utm.set(0,1,4);
	utm.set(1,2,5);
	utm.set(0,2,6);

    for(int i=0;i<m_size;i++) {
        for(int j=0;j<m_size;j++)
            std::cout << utm.get(i,j) << "\t";
        std::cout << std::endl;
    }
}
