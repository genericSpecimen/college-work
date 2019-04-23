#include <iostream>
#include <list>
#include <vector>
#include <limits>
#include <queue>
#include <utility>
#include <map>
#include <functional>

#define INF std::numeric_limits<unsigned int>::max()

struct Vertex {
    static unsigned int id;
    unsigned int v_id; // id of this vertex
    unsigned int v_key; // key of this vertex
    Vertex* v_parent; // predecessor of the vertex

    Vertex() {
        v_id = id;
        id++;
        v_key = INF;
        v_parent = nullptr; // initially, no predecessor
    }
};

unsigned int Vertex::id = 0;

class Graph {
public:
    unsigned int num_vertices;
    std::vector<Vertex*> vertices; // vertices[i] stores the vertex numbered i+1 from user's perspective
    std::vector< std::list<unsigned int> > adj_lists_array;

    std::map<std::pair<unsigned int, unsigned int>, unsigned int> weights;

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

    void add_edge(unsigned int u, unsigned int v, bool directed, unsigned int weight) {
        adj_lists_array[u].push_back(v);
        weights[std::make_pair(u,v)] = weight;
        if(!directed) {
            adj_lists_array[v].push_back(u); // undirected
            weights[std::make_pair(v,u)] = weight;
        }
    }

    void print_vertex_info() {
        std::cout << "\nVertex information: \n";
        for(int i=0;i<num_vertices;i++) {
            std::cout << "Vertex " << vertices[i]->v_id + 1;
            std::cout << ", Key: " << vertices[i]->v_key;
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
            for(std::list<unsigned int>::iterator itr = adj_lists_array[i].begin(); itr != adj_lists_array[i].end(); itr++) {
                std::cout << *itr + 1 << ", ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void print_edges() {
        for(int i=0;i<num_vertices;i++) {
            for(std::list<unsigned int>::iterator itr = adj_lists_array[i].begin(); itr != adj_lists_array[i].end(); itr++) {
                std::cout << "Edge (" << i+1 << ", " << *itr + 1 << ", " << weights[std::make_pair(i, *itr)] << "), ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void MST_Prim(unsigned int root) {
        std::vector<bool> is_in_mst(num_vertices, false);
        vertices[root]->v_key = 0;
        is_in_mst[root] = true;

        typedef std::pair<unsigned int, unsigned int> puiui;
        std::priority_queue<puiui, std::vector<puiui>, std::greater<puiui>> Q;
        unsigned int id, key;
        unsigned int id = vertices[i]->v_id;
        unsigned int key = vertices[i]->v_key;
            Q.push(std::make_pair(key, id));

        unsigned int u, v, u_key, weight;
        while(!Q.empty()) {
            u = Q.top().second;
            key = Q.top().first;
            is_in_mst[u] = true;
            std::list<unsigned int>::iterator itr;
            for(itr = adj_lists_array[u].begin(); itr != adj_lists_array[u].end(); itr++) {
                v = *itr;
                weight = weights[std::make_pair(u,v)];
                if(!is_in_mst[v] && weight < vertices[v]->v_key) {
                    vertices[v]->v_parent = vertices[u];
                    vertices[v]->v_key = weight;
                }
            }
        }

        std::cout << "Vertices in MST: ";
        for(int i=0; i<num_vertices; i++) {
            if(is_in_mst[i]) {
                std::cout << i+1 << ", ";
            }
        }
        std::cout << "\n";
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

    std::cout << "Enter two vertices and weight of each edge in the format < u v w > (without <>):\n";

    unsigned int u_id, v_id, weight;
    while(num_edges--) {
        std::cin >> u_id >> v_id >> weight;
        u_id--;
        v_id--;
        graph.add_edge(u_id,v_id, directed, weight);
    }

    graph.print_vertex_info();
    graph.print_adjacency_lists();
    graph.print_edges();

    graph.MST_Prim(1);

}
