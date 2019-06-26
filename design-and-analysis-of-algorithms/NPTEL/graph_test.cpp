#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <utility>
/*
class WeightedUndirectedGraph {
public:
    int v;
    std::list<int>* adjacency_lists_array;
    WeightedUndirectedGraph(int v) {
        this->v = v;
        adjacency_lists_array = new std::list<int>[v];
    }

    void add_edge(int u, int v) {
        adjacency_lists_array[u].push_back(v);
        adjacency_lists_array[v].push_back(u);
    }

    friend std::ostream& operator << (std::ostream& os, const UndirectedGraph& graph) {
        for(int i=0;i<graph.v;i++) {
            os << "Vertex " << i << ": ";
            for(auto x : graph.adjacency_lists_array[i]) {
                os << x << ", ";
            }
            os << "\n";
        }
        return os;
    }
};

int main() {
    WeightedUndirectedGraph graph(4);
    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,2);
    graph.add_edge(2,3);

    std::cout << graph << "\n";
}
*/

/*
class Edge {
public:
    int source;
    int destination;
    Edge(int source, int destination) {
        this->source = source;
        this->destination = destination;
    }
};
*/

class Graph {
public:
    int v; // number of vertices

    std::vector<std::list<int>> adjacency_lists_array;
    std::map< std::pair<int, int>, int > weights; // maps a edge to its weight
    Graph(int v) {
        this->v = v;
        this->adjacency_lists_array.resize(v);
    }

    void add_edge(int source, int destination, int weight) {
        adjacency_lists_array[source].push_back(destination);
        adjacency_lists_array[destination].push_back(source); // undirected graph

        weights[std::make_pair(source, destination)] = weight;
        weights[std::make_pair(destination, source)] = weight;
    }

    friend std::ostream& operator << (std::ostream& os, Graph& graph) {
        for(int i=0;i<graph.v;i++) {
            for(auto x : graph.adjacency_lists_array[i]) {
                os << "Edge (" << i << ", " << x << ") with weight: " << graph.weights[std::make_pair(i, x)] << "\n";
            }
        }

        return os;
    }
};

int main() {
    Graph graph(4);
    graph.add_edge(0,1, 10);
    graph.add_edge(0,2, 20);
    graph.add_edge(1,2, 30);
    graph.add_edge(2,3, 40);

    std::cout << graph << "\n";
}
