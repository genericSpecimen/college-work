#include <iostream>
#include <list>
#include <vector>
#include <limits>
#include <queue>

#define INF std::numeric_limits<unsigned int>::max()

enum Color {
    WHITE, GRAY, BLACK
};

unsigned int current_time = 0;

struct Vertex {
    static unsigned int id;
    unsigned int v_id; // id of this vertex
    Color v_color;
    Vertex* v_parent; // predecessor of the vertex
    unsigned int d_time, f_time;

    Vertex() {
        v_id = id;
        id++;
        v_color = WHITE; // initially, undiscovered
        v_parent = nullptr; // initially, no predecessor
    }
};

unsigned int Vertex::id = 0;

class Graph {
public:
    unsigned int num_vertices;
    std::vector<Vertex*> vertices; // vertices[i] stores the vertex numbered i+1
    std::vector< std::list<int> > adj_lists_array;

    Graph(unsigned int num_vertices) {

        this->num_vertices = num_vertices;
        vertices.resize(num_vertices);
        for(int i=0;i<num_vertices;i++) {
            vertices[i] = new Vertex();
        }

        this->adj_lists_array.resize(num_vertices);

    }

    ~Graph() {
        for(int i=0;i<num_vertices;i++) {
            delete vertices[i];
        }
    }

    void add_edge(unsigned int u, unsigned int v, bool directed) {
        adj_lists_array[u].push_back(v);
        if(!directed) {
            adj_lists_array[v].push_back(u); // undirected
        }
    }

    void print_vertex_info() {
        std::cout << "\nVertex information: \n";
        for(int i=0;i<num_vertices;i++) {
            std::cout << "Vertex " << vertices[i]->v_id + 1;
            std::cout << ", Color: ";
            switch(vertices[i]->v_color) {
                case WHITE: std::cout << "WHITE"; break;
                case GRAY: std::cout << "GRAY"; break;
                case BLACK: std::cout << "BLACK"; break;
            }

            std::cout << ", Discovery time: " << vertices[i]->d_time;
            std::cout << ", Finishing time: " << vertices[i]->f_time;
            std::cout << ", Parent: ";
            if(vertices[i]->v_parent == nullptr) {
                std::cout << "NIL\n";
            } else std::cout << vertices[i]->v_parent->v_id+1 << "\n";


        }

        std::cout << "\n";
    }

    void print_adjacency_lists() {
        std::cout << "\nAdjacency List of each vertex: \n";
        for(int i=0;i<num_vertices;i++) {
            std::cout << "Vertex " << i+1 << ": ";
            for(std::list<int>::iterator itr = adj_lists_array[i].begin(); itr != adj_lists_array[i].end(); itr++) {
                std::cout << *itr + 1 << ", ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void DFS() {
        current_time = 0;
        for(int i=0;i<num_vertices;i++) {
            if(vertices[i]->v_color == WHITE) {
                DFS_visit(i);
            }
        }
    }

    void DFS_visit(unsigned int u) {
        current_time++;
        vertices[u]->d_time = current_time;
        vertices[u]->v_color = GRAY;

        unsigned int v;
        std::list<int>::iterator itr;
        for(itr = adj_lists_array[u].begin(); itr != adj_lists_array[u].end(); itr++) {
            v = *itr;
            if(vertices[v]->v_color == WHITE) {
                vertices[v]->v_parent = vertices[u];
                DFS_visit(v);
            }
        }

        vertices[u]->v_color = BLACK;
        current_time++;
        vertices[u]->f_time = current_time;
    }
};
int main() {

    std::cout << "Enter the number of vertices and edges of the graph: ";
    unsigned int num_vertices, num_edges;
    std::cin >> num_vertices >> num_edges;
    Graph graph(num_vertices);

    std::cout << "Is the graph directed?(y/n): ";
    char ans;
    bool directed = false;
    std::cin >> ans;
    if(ans == 'Y' || ans == 'y') {
        directed = true;
    } else directed = false;

    std::cout << "Enter the vertices of each edge in the format < u v > (without <>):\n";

    unsigned int u_id, v_id;
    while(num_edges--) {
        std::cin >> u_id >> v_id;
        u_id--;
        v_id--;
        graph.add_edge(u_id,v_id, directed);
    }

    graph.DFS();
    graph.print_vertex_info();

}
