#include <iostream>
#include <vector>
#include <cmath>
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
            //std::cout << s << " ";
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

class Soldier {
public:
    static int id;
    int x, y; // x and y coordinates
    int s_id; // soldier id
    Soldier() {s_id = ++id;}
};

int Soldier::id = 0;

std::ostream& operator<<(std::ostream& os, const Soldier& obj) {
    os << "Solider " << obj.s_id << ": " << obj.x << ", " << obj.y << " ";
    return os;
}

double distance_between_two_soldiers(const Soldier& s1, const Soldier& s2) {
    int x_diff = s2.x - s1.x;
    int y_diff = s2.y - s1.y;
    return std::sqrt(x_diff * x_diff + y_diff * y_diff);
}

int main() {
    int l, w, n; std::cin >> l >> w >> n;
    std::vector<Soldier> soldiers;
    soldiers.resize(n);

    int x, y;
    for(int i=0;i<n;i++) {
        std::cin >> x >> y;
        soldiers[i].x = x;
        soldiers[i].y = y;
    }

    //for(auto x : soldiers) std::cout << x << "\n";

    /*
     * boundary t is signified by index 0
     * soldiers s1, s2, ..., sn are signified by index 1,2,...,n
     * boundary s is signified by index n+1
     */

    Graph g(n+2);

    bool no_edge_to_boundary = true; // initially, no edges to boundary
    for(int i=0;i<n;i++) {
        if(w - soldiers[i].y <= 100) {
            //std::cout << "Edge between s and " << soldiers[i] << std::endl;
            g.add_edge(n+1, soldiers[i].s_id);
            no_edge_to_boundary = false; // an edge connecting soldier to boundary exists
        }
        if(soldiers[i].y <=100) {
            //std::cout << "Edge between t and " << soldiers[i] << std::endl;
            g.add_edge(0, soldiers[i].s_id);
            no_edge_to_boundary = false;
        }
    }
    if(no_edge_to_boundary) {
        // since no edges exist that connect a soldier to a boundary vertex, prisoners can escape
        // and there is no need to check further
        std::cout << "0\n";
        return 0;
    }

    // check edges between soldiers
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i != j) {
                double distance = distance_between_two_soldiers(soldiers[i], soldiers[j]);
                //std::cout << "Distance between " << soldiers[i] << " and " << soldiers[j] << " is: " << distance << "\n";
                if(distance <= 200) {
                    // edge between the two soldiers exists
                    g.add_edge(soldiers[i].s_id, soldiers[j].s_id);
                }
            }
        }
    }

    //g.print_graph();
    if(g.is_reacheable(0,n+1)) std::cout << "1\n"; // path exists, they can't escape
    else std::cout << "0\n"; // no path exists, they can escape
}
