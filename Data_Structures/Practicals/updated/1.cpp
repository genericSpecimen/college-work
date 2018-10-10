#include <iostream>

template <class T, int size>
class DiagonalMatrix {
public:
    T elements[size]; //1D array to store the non-zero elements
    DiagonalMatrix() {
        for(int i=0;i<size;i++) elements[i] = 0;
    }
    void set(int i, int j, T elem) {
        if(i<0 || j<0 || i>=size || j>=size)
            throw std::out_of_range("matrix indices out of range");
        else if(i == j) elements[i] = elem;
    }
    T get(int i, int j) const {
        if(i<0 || j<0 || i>=size || j>= size)
            throw std::out_of_range("matrix indices out of range");
        else if(i == j) return elements[i];
        else return 0; //all other elements are 0
    }
};

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
	T get(int i, int j) const {
		if(i<0 || j<0 || i>=m_size || j>=m_size)
            throw std::out_of_range("matrix indices out of range");
		if(i<j) return get(j,i);
		else if(i>=j) return elements[i*(i+1)/2+j];
		return 0;
	}
};

int main() {
	const int m_size = 3;
	std::cout << "This program shows examples of some Special Matrices. Whose example do you want?\n";
	std::cout << "1. Diagonal Matrix\n";
	std::cout << "2. Lower Triangular Matrix\n";
	std::cout << "3. Upper Triangular Matrix\n";
	std::cout << "4. Symmetric Matrix\n";
	std::cout << "Enter your option(1-4): ";
	int option; std::cin >> option;
	switch(option) {
		case 1: {
			DiagonalMatrix<double, m_size> dm;
			dm.set(0,0,5); dm.set(1,1,6); dm.set(2,2,7);
			std::cout << "\nSample diagonal matrix\n";
    		for(int i=0;i<m_size;i++) {
        		for(int j=0;j<m_size;j++)
            		std::cout << dm.get(i,j) << "\t";
        		std::cout << std::endl;
    		}
			break;
		}
		case 2: {
			const int num_elements = m_size*(m_size + 1)/2;
			LowerTriangularMatrix<double, m_size, num_elements> ltm;
			ltm.set(0,0,1);
			ltm.set(1,1,2);
			ltm.set(2,2,3);
			
			ltm.set(1,0,4);
			ltm.set(2,0,6);
			ltm.set(2,1,5);
			std::cout << "\nSample lower triangular matrix\n";
			for(int i=0;i<m_size;i++) {
				for(int j=0;j<m_size;j++)
					std::cout << ltm.get(i,j) << "\t";
				std::cout << std::endl;
			}
			break;
		}
		case 3: {
			const int num_elements = m_size*(m_size + 1)/2;
			UpperTriangularMatrix<int, m_size, num_elements> utm;
			utm.set(0,0,1);
			utm.set(1,1,2);
			utm.set(2,2,3);
			
			utm.set(0,1,4);
			utm.set(1,2,5);
			utm.set(0,2,6);
			std::cout << "\nSample upper triangular matrix\n";
			for(int i=0;i<m_size;i++) {
				for(int j=0;j<m_size;j++)
					std::cout << utm.get(i,j) << "\t";
				std::cout << std::endl;
			}
			break;
		}
		case 4: {
			const int num_elements = m_size*(m_size+1)/2;
			SymmetricMatrix<int, m_size, num_elements> sm;
			sm.set(0,0,1);
			sm.set(1,1,2);
			sm.set(2,2,3);
			sm.set(1,0,4);
			sm.set(2,0,6);
			sm.set(2,1,5);
			std::cout << "\nSample symmetric matrix\n";
			for(int i=0;i<m_size;i++) {
				for(int j=0;j<m_size;j++) std::cout << sm.get(i,j) << "\t";
				std::cout << std::endl;
			}
			break;
		}
		default: std::cout << "Invalid option\n";
	}
}