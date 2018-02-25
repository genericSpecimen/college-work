#include<iostream>
class DiGraph {
public:
	int** matrix;
	int size;
	DiGraph(int vertices) {
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
		std::cout << "\nThis represents a directed edge from vertex1 to vertex2.";
		std::cout << "\nvertex1 is the initial edge and vertex2 is the terminal edge.";
		do {
			std::cout << "\nEnter vertices: ";
			std::cin >> n1 >> n2;
			if(n1 <= size && n2 <= size)
				matrix[n1-1][n2-1]++;
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

	int indegree(int v) { //number of edges with v as their terminal vertex
		int in_degree = 0;
		for(int i=0;i<size;i++) {
			if(matrix[i][v] >= 1)
				in_degree += matrix[i][v];
		}
		return in_degree;
	}

	int outdegree(int v) { //number of edges with v as their initial vertex
		int out_degree = 0;
		for(int i=0;i<size;i++) {
			if(matrix[v][i] >= 1)
				out_degree += matrix[v][i];
		}
		return out_degree;
	}

	void degrees() {
		for(int i=0;i<size;i++) {
			std::cout << "\nIn-degree  of vertex " << i+1 << ": " << this->indegree(i); 
			std::cout << "\nOut-degree of vertex " << i+1 << ": " << this->outdegree(i); 
			std::cout << std::endl;
		}
	}
	~DiGraph() {
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
	DiGraph dg(n);
	do {
		std::cout << "\nWhat do you want to do?";
		std::cout << "\n1. Add directed edges.";
		std::cout << "\n2. Print the adjacency matrix.";
		std::cout << "\n3. Print the in-degree and out-degree of each vertex.";
		std::cout << "\nEnter your option: ";
		std::cin >> option;

		switch(option) {
			case 1: dg.add_edges(); break;
			case 2: dg.printGraph(); break;
			case 3: dg.degrees(); break;
			default: std::cout << "\nInvalid option!\n";
		}
		std::cout << "\nDo you want to continue?(y/n): ";
		std::cin >> ans;
	} while(ans == 'y' || ans == 'Y');
}