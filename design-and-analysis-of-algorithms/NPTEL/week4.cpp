#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <limits>
#include <queue>
#include <tuple>

#define INF std::numeric_limits<int>::max()

class Graph {
public:
    int v;

    std::vector<std::tuple<int, int, int>> edges;
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

    int dijkstra(int source, int destination) {
        typedef std::pair<int, int> pii;
        std::vector<int> distance(v, INF);

        distance[source] = 0;
        std::priority_queue< pii, std::vector<pii>, std::greater<pii> > min_distance_queue;

        min_distance_queue.push(std::make_pair(distance[source], source));

        int u, vee, dist, weight;
        while(!min_distance_queue.empty()) {
            // extract vertex with minimum distance
            u = min_distance_queue.top().second;
            dist = min_distance_queue.top().first;
            min_distance_queue.pop();
            if(u == destination) return distance[destination];
            if(distance[u] < dist) {
                continue;
            }

            // update each neighbor v of u
            for(auto x : adjacency_lists_array[u]) {
                vee = x.first;
                weight = x.second;
                if(distance[vee] > distance[u] + weight) {
                    distance[vee] = distance[u] + weight;
                    min_distance_queue.push(std::make_pair(distance[vee], vee));
                }
            }
        }
        return INF;
    }

    int min_weight_cycle() {
        int min_w_cycle = INF;
        int i, j, weight, SPji, cycle_weight;
        for(auto x : edges) {
            i = std::get<0>(x);
            j = std::get<1>(x);
            weight = std::get<2>(x);
            delete_edge(i, j, weight);
            //std::cout << "Deleted edge " << i << ", " << j << " with weight " << weight << "\n";

            SPji = dijkstra(j, i);
            if(SPji != INF) {
                //std::cout << "Found a path between " << j << ", " << i << " with distance " << SPji << "\n";
                cycle_weight = SPji + weight;
                //std::cout << "Weight of this cycle: " << cycle_weight << "\n";
                if(cycle_weight <  min_w_cycle) min_w_cycle = cycle_weight;
            } //else std::cout << "No alternate path found..\n";

            add_edge(i, j, weight);
            //std::cout << "Added edge " << i << ", " << j << " with weight " << weight << "\n\n";
        }
        return min_w_cycle;
    }
};


int main() {
    int num_roads; std::cin >> num_roads;
    int v = 300; // max number of towns/villages
    Graph graph(v+1);

    int s, t, d;
    while(num_roads--) {
        std::cin >> s >> t >> d;
        graph.add_edge(s,t,d);
        graph.edges.push_back(std::make_tuple(s,t,d));
    }

    std::cout << graph.min_weight_cycle() << "\n";
}
