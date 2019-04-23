#include <iostream>
#include <list>

class Graph {
public:
    int v;
    std::list<int>* adjacency_list;
    Graph(int v) {
        this->v = v;
        adjacency_list = new std::list<int>[v];
    }

    void add_edge(int v1, int v2) {
        adjacency_list[v1].push_back(v2); // v2 is adjacent to v1
        adjacency_list[v2].push_back(v1); // undirected graph
    }

    void print_graph() {
        for(int i=0;i<v;i++) {
            std::cout << "Vertex " << i << ": ";
            for(std::list<int>::iterator j = adjacency_list[i].begin(); j != adjacency_list[i].end(); j++) {
                std::cout << *j << ", ";
            }
            std::cout << "\n";
        }
    }

    bool is_reacheable(int s, int d) {
        if(s == d) return true;

        bool* visited = new bool[v];
        for(int i=0;i<v;i++) visited[i] = false;

        std::list<int> queue;

        visited[s] = true;
        queue.push_back(s);
        std::list<int>::iterator i;
        while(!queue.empty()) {
            s = queue.front();
            std::cout << s << " ";
            queue.pop_front();
            for(i = adjacency_list[s].begin(); i != adjacency_list[s].end(); i++) {
                if(*i == d) return true;
                if(!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }

        }
        return false;
    }
};

int main() {
    Graph g(10);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(4,5);

    g.print_graph();

    std::cout << "Path from 3 to 4: " << std::boolalpha << g.is_reacheable(3,4) << "\n";

}
