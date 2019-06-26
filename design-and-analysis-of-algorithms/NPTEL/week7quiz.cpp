#include <iostream>
#include <vector>

int main() {
    unsigned int n;
    std::cin >> n;
    std::vector<int> height; height.resize(n);
    for(int i=0;i<n;i++) std::cin >> height[i];
    std::vector<int> V; V.resize(n);
    V[n-1] = 1;
    for(int i=n-2;i>=0;i--) {
        std::cout << "\n----Start shooting from spaceship: " << i+1 << " with height " << height[i] << " -----\n";

        // compute V[i] = 1 + max{V[j] | j>i and h[j] <= h[i]}
        int max = -1;
        for(int j=i+1;j<n;j++) {
            if(height[j] <= height[i]) {
                if(V[j] > max) max = V[j];
            }
        }
        V[i] = 1 + max;
        std::cout << "Can shoot maximum " << V[i] << " spaceships from spaceship" << i+1 << " with height " << height[i] << "\n";
    }

    for(auto x : V) std::cout << x << " ";
    std::cout << "\n";
}
