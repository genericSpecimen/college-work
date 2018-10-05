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

int main() {
    const int size = 3;
    DiagonalMatrix<int,size> dm;
    dm.set(0,0,5); dm.set(1,1,6); dm.set(2,2,7);
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++)
            std::cout << dm.get(i,j) << "\t";
        std::cout << std::endl;
    }
}