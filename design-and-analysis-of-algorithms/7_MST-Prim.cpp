#include <iostream>
#include <list>
#include <vector>
#include <limits>
#include <queue>
#include <utility>
#include <map>
#include <functional>

#define INF std::numeric_limits<unsigned int>::max()

/*
 * WARNING: the std::priority_queue data structure does not provide functions to update the priorities.
 * The implementation here is as follows:
 *
 * Instead of decreasing the key of an existing value, we add values in the priority_queue<pair<Priority, Key>>
 * without removing the previous invalid ones. This means that there could be duplicate values in the priority_queue
 * at any point of time.
 * The priority_queue contains the value with the highest priority (minimum key in this case) at the top. In case
 * there are duplicates of the same value, we can be sure that the value popped has the minimum key. The moment a value
 * u is popped, we set is_in_MST[u] = true, which means we have added this vertex to the MST. When the duplicate value is
 * popped again, setting is_in_MST[u] = true has no new effect.
 *
*/

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

    //----some utility functions useful for debugging----
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
    //---------------------------------------------------

    void MST_Prim(unsigned int root) {
        std::vector<bool> is_in_mst(num_vertices, false);
        vertices[root]->v_key = 0;
        is_in_mst[root] = true;

        typedef std::pair<unsigned int, unsigned int> puiui;
        std::priority_queue<puiui, std::vector<puiui>, std::greater<puiui>> Q;
        Q.push(std::make_pair(0, root));

        unsigned int u, v, u_key, weight;
        while(!Q.empty()) {
            u = Q.top().second;
            u_key = Q.top().first;
            Q.pop();
            //std::cout << "Popped vertex " << u+1 << " with key " << u_key << "\n";
            is_in_mst[u] = true;
            std::list<unsigned int>::iterator itr;
            for(itr = adj_lists_array[u].begin(); itr != adj_lists_array[u].end(); itr++) {
                v = *itr;
                weight = weights[std::make_pair(u,v)];
                if(!is_in_mst[v] && weight < vertices[v]->v_key) {
                    vertices[v]->v_parent = vertices[u];
                    vertices[v]->v_key = weight;
                    Q.push(std::make_pair(weight, v));
                }
            }
        }

        std::cout << "\nEdges in MST:\n";
        for(int i=0; i<num_vertices; i++) {
            if(vertices[i]->v_parent != nullptr) {
                std::cout << vertices[i]->v_parent->v_id + 1 << "-" << i+1 << "\n";
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

    /*
    graph.print_vertex_info();
    graph.print_adjacency_lists();
    graph.print_edges();
    */

    unsigned int root;
    std::cout << "\nEnter the root from which MST should be grown from: ";
    std::cin >> root;
    root--;
    graph.MST_Prim(root);
}
