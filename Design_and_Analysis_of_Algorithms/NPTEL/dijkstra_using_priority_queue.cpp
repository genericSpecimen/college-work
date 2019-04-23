#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <limits>
#include <queue>

#define INF std::numeric_limits<int>::max()

class Graph {
public:
    int v;
    std::vector < std::list < std::pair <int, int> > > adjacency_lists_array;
    Graph(int v) {
        this->v = v;
        adjacency_lists_array.resize(v);
    }

    void add_edge(int source, int destination, int weight) {
        adjacency_lists_array[source].push_back(std::make_pair(destination, weight));
        adjacency_lists_array[destination].push_back(std::make_pair(source, weight));
    }

    void delete_edge(int source, int destination, int weight) {
        adjacency_lists_array[source].remove(std::make_pair(destination, weight));
        adjacency_lists_array[destination].remove(std::make_pair(source, weight));
    }

    friend std::ostream& operator << (std::ostream& os, Graph& graph) {
        for(int i=0;i<graph.v;i++) {
            os << "Vertex " << i << ":";
            for(auto x : graph.adjacency_lists_array[i]) {
                os << "\n\t|-> " << x.first << ", weight = " << x.second;
            }
            os << "\n\n";
        }
        /*
        for(auto x : graph.edges) {
            os << "(" << std::get<0>(x) << ", " << std::get<1>(x) << ", " << std::get<2>(x) << ")\n";
        }
        */
        return os;
    }

    std::vector<int> dijkstra(int source) {
        typedef std::pair<int, int> pii;
        std::vector<int> distance(v, INF);
        //std::vector<bool> permanent(v, false);

        distance[source] = 0;
        std::priority_queue< pii, std::vector<pii>, std::greater<pii> > min_distance_queue;
        //for(int i=0;i<v;i++) min_distance_queue.push(std::make_pair(distance[i], i));

        min_distance_queue.push(std::make_pair(distance[source], source));


        /*
        std::cout << "Queue: \n";
        while(!min_distance_queue.empty()) {
            std::cout << min_distance_queue.top().first << ", " << min_distance_queue.top().second << "\n";
            min_distance_queue.pop();
        }
        */
        int u, dist;
        while(!min_distance_queue.empty()) {
            // extract vertex with minimum distance
            u = min_distance_queue.top().second;
            dist = min_distance_queue.top().first;
            min_distance_queue.pop();

            if(distance[u] < dist) continue;

            // update each neighbor v of u
            int v;
            for(auto x : adjacency_lists_array[u]) {
                v = x.first;
                int weight = x.second;
                if(distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    min_distance_queue.push(std::make_pair(distance[v], v));
                }
            }
        }

        return distance;
    }
};


int main() {
    int num_roads; std::cin >> num_roads;
    int v = 10; // max number of towns/villages
    Graph graph(v+1);

    int s, t, d;
    while(num_roads--) {
        std::cin >> s >> t >> d;
        graph.add_edge(s,t,d);
    }

    std::cout << graph << "\n";
    //std::cout << graph.shortest_cycle() << "\n";

    std::vector<int> distance = graph.dijkstra(1);
    for(auto x : distance) std::cout << x << " ";
    std::cout << "\n";

}
