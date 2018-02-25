#include<iostream>
class relation {
public:
	int** matrix;
	int size;
	relation(int n) {
		size = n;
		matrix = new int*[n];
		for(int i=0;i<n;i++)
			matrix[i] = new int[n];

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++)
				matrix[i][j] = 0;
		}
	}

	void add_relation() {
		char add_ans = 'y';
		int e1,e2;
		std::cout << "\nEnter the elements in the format < element1 element2 >";
		std::cout << "\nThis signifies that element1 and element2 are related: ";
		do {
		    std::cout << "\nEnter elements: ";
		   	std::cin >> e1 >> e2;
		   	if(e1 <= size && e2 <= size) {
				if(matrix[e1-1][e2-1] == 1)
					std::cout << "\nRelation already exists!\n";
				else
					matrix[e1-1][e2-1]++;
			}
			else
				std::cout << "\nInvalid element, cannot add a relation!";
			std::cout << "Do you want to add another relation between two elements? (y/n)";
				std::cin >> add_ans;
		} while(add_ans == 'y' || add_ans == 'Y');  		
	}

	void print_relation() {
		std::cout << "The relation matrix is:\n  ";
		for(int i=0;i<size;i++)
			std::cout << i+1 << ' ';
		std::cout << "\n  ";
		for(int i=0;i<size*2;i++)
			std::cout << '_';
		std::cout << '\n';
		for(int i=0;i<size;i++) {
			std::cout << i+1 << '|';
			for(int j=0;j<size;j++)
				std::cout << matrix[i][j] << ' ';
			std::cout << std::endl;
		}
	}

	bool isReflexive() {
		for(int i=0;i<size;i++)
				if(matrix[i][i] != 1)
					return false;
		return true;
	}

	bool isSymmetric() {
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++) {
				if(i == j)
					continue;
				if(matrix[i][j] != matrix[j][i])
					return false;
			}
		}
		return true;
	}

	bool isAntiSymmetric() {
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++) {
				if(i == j)
					continue;
				if(matrix[i][j] == 1) {
					if(matrix[j][i] == 1)
						return false;
				}
			}
		}
		return true;
	}

	bool isTransitive() {
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++) {
				if(matrix[i][j] == 1) {
					for(int k=0;k<size;k++) {
						if(matrix[j][k] == 1) {
							if(matrix[i][k] != 1)
								return false;
						}
					}
				}
			}
		}
		return true;
	}

	bool isEquivalent() {
		if(this->isReflexive() && this->isSymmetric() && this->isTransitive())
			return true;
		return false;
	}

	bool isPartialOrder() {
		if(this->isReflexive() && this->isAntiSymmetric() && this->isTransitive())
			return true;
		return false;
	}

	bool isNone() {
		if(this->isEquivalent() || this->isPartialOrder())
			return false;
		return true;
	}

	~relation() {
		for(int i=0;i<size;i++)
			delete[] matrix[i];
		delete[] matrix;
	}
};

int main() {
	int n,option;
	char ans = 'y';
	std::cout << "Set A = {1,2,3,4,.....,n}";
	std::cout << "\nThis program will represent a relation on A using a relation matrix.";
	std::cout << "\nEnter the cardinality of set A. (i.e., enter n): ";
	std::cin >> n;
	relation r(n);
	do {
		std::cout << "\nWhat do you want to do?";
		std::cout << "\n1. Print the relation matrix.";
		std::cout << "\n2. Add a relation between two elements.";
		std::cout << "\n3. Check if the relation is reflexive.";
		std::cout << "\n4. Check if the relation is symmetric.";
		std::cout << "\n5. Check if the relation is antisymmetric.";
		std::cout << "\n6. Check if the relation is transitive.";
		std::cout << "\n7. Check if the relation is equivalent.";
		std::cout << "\n8. Check if the relation is partial order.";
		std::cout << "\n9. Check if the relation is neither equivalent nor partial order.";

		std::cout << "\nEnter your option:";
		std::cin >> option;
		switch(option) {
			case 1: r.print_relation(); break;
			case 2: r.add_relation(); break;
			case 3: if(r.isReflexive())
						std::cout << "\nYes, the relation is reflexive.";
					else
						std::cout << "\nNo, the relation is not reflexive."; break;
			case 4: if(r.isSymmetric())
						std::cout << "\nYes, the relation is symmetric.";
					else
						std::cout << "\nNo, the relation is not symmetric."; break;
			case 5: if(r.isAntiSymmetric())
						std::cout << "\nYes, the relation is antisymmetric.";
					else
						std::cout << "\nNo, the relation is not antisymmetric."; break;
			case 6: if(r.isTransitive())
						std::cout << "\nYes, the relation is transitive.";
					else
						std::cout << "\nNo, the relation is not transitive."; break;
			case 7: if(r.isEquivalent())
						std::cout << "\nYes, the relation is equivalent.";
					else
						std::cout << "\nNo, the relation is not equivalent."; break;
			case 8: if(r.isPartialOrder())
						std::cout << "\nYes, the relation is partial order.";
					else
						std::cout << "\nNo, the relation is not partial order."; break;
			case 9: if(r.isNone())
						std::cout << "\nYes, the relation is neither equivalent nor partial order, that is, it is None.";
					else
						std::cout << "\nNo, the relation is not None."; break;
			default: std::cout << "\nInvalid option\n"; 
		}
		std::cout << "\nDo you want to continue? (y/n)";
		std::cin >> ans;
	} while (ans == 'y' || ans == 'Y');
}