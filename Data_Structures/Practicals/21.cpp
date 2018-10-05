#include<iostream>

template <class T, int m_size, int num_elements>
class SymmetricMatrix {
public:
    T elements[num_elements];
	SymmetricMatrix() {
        for(int i=0;i<num_elements;i++) elements[i];
	}
	void set(int i, int j, T elem) {
		if(i<0 || j<0 || i>=m_size || j>=m_size)
            throw std::out_of_range("matrix indices out of range");
		if(i<j) set(j,i,elem);
		else if(i>=j) elements[i*(i+1)/2+j] = elem;
	}
	int get(int i, int j) const {
		if(i<0 || j<0 || i>=m_size || j>=m_size)
            throw std::out_of_range("matrix indices out of range");
		if(i<j) return get(j,i);
		else if(i>=j) return elements[i*(i+1)/2+j];
		return 0;
	}
};

int main() {
    const int m_size = 3;
    const int num_elements = m_size*(m_size+1)/2;
	SymmetricMatrix<int, m_size, num_elements> sm;
	sm.set(0,0,1);
	sm.set(1,1,2);
	sm.set(2,2,3);
	sm.set(1,0,4);
	sm.set(2,0,6);
	sm.set(2,1,5);

	for(int i=0;i<m_size;i++) {
		for(int j=0;j<m_size;j++) std::cout << sm.get(i,j) << " ";
		std::cout << std::endl;
	}
}
