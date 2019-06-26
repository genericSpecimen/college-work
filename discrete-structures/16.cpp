#include<iostream>
class Graph {
public:
	int** matrix;
	int size;
	Graph(int vertices) {
		size = vertices;
		matrix = new int*[size];
		for(int i=0;i<size;i++)
			matrix[i] = new int[size];
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++)
				matrix[i][j] == 0;
		}
	}

	void add_edges() {
		int n1, n2;
		char ans = 'y';
		std::cout << "\nEnter vertices in the format < vertex1 vertex2 >.";
		std::cout << "\nThis represents an undirected edge connecting vertex1 and vertex2.";
		do {
			std::cout << "\nEnter vertices: ";
			std::cin >> n1 >> n2;
			if(n1 <= size && n2 <= size) {
				matrix[n1-1][n2-1]++;
				if(n1 != n2)
					matrix[n2-1][n1-1]++; //because it is undirected
			}
			else
				std::cout << "\nInvalid vertex/vertices\n";
			std::cout << "\nDo you want to add another edge?(y/n): ";
			std::cin >> ans;
		} while(ans == 'y' || ans == 'Y');
	}

	void printGraph() {
		
		//Formatting output starts, irrelevant to the actual program
		std::cout << "  ";
		for(int i=0;i<size;i++)
			std::cout << i+1 << ' ';
		std::cout << "\n  ";
		for(int i=0;i<size*2;i++)
			std::cout << '_';
		std::cout << std::endl;
		//Formatting output ends

		for(int i=0;i<size;i++) {
			std::cout << i+1 << '|';
			for(int j=0;j<size;j++)
				std::cout << matrix[i][j] << ' ';
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	bool isComplete(){
		for(int i=0;i<size;i++)
			if(matrix[i][i] != 0)
				return false;
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++) {
				if((i != j) && matrix[i][j] != 1)
					return false;
			}
		}
		return true;
	}

	~Graph() {
		for(int i=0;i<size;i++)
			delete[] matrix[i];
		delete[] matrix;
	}
};

int main() {
	int n,option;
	char ans = 'y';
	std::cout << "\nEnter the number of vertices of the directed graph: ";
	std::cin >> n;
	Graph g(n);
	do {
		std::cout << "\nWhat do you want to do?";
		std::cout << "\n1. Add edges.";
		std::cout << "\n2. Print the adjacency matrix.";
		std::cout << "\n3. Check if the graph is complete.";
		std::cout << "\nEnter your option: ";
		std::cin >> option;

		switch(option) {
			case 1: g.add_edges(); break;
			case 2: g.printGraph(); break;
			case 3: if(g.isComplete())
						std::cout << "Yes, it is a complete graph.\n";
					else
						std::cout << "No, it is not a complete graph.\n"; break;
			default: std::cout << "\nInvalid option!\n";
		}
		std::cout << "\nDo you want to continue?(y/n): ";
		std::cin >> ans;
	} while(ans == 'y' || ans == 'Y');
}
