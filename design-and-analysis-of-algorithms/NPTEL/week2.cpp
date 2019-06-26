#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
	int n; std::cin >> n;
	
	std::map<int, int> singers; // maps a singer's lower bound to their number of wins
	std::vector<int> lower_bounds; lower_bounds.resize(n);
	std::vector<int> lower_bounds_copy; 
	
	int trash; // takes care of the not needed upper bound
	int lower = 0;
	for(int i=0;i<n;i++) {
		std::cin >> lower >> trash;
		lower_bounds[i] = lower;
		singers[lower] = 0; // initialise number of wins to 0
	}

	lower_bounds_copy = lower_bounds;

	std::sort(lower_bounds.begin(), lower_bounds.end());
	
	for(int i=0;i<n;i++) {
		singers[lower_bounds[i]] += (n-i-1);
	}

	for(int i=0;i<n;i++) {
		std::cout << (singers[lower_bounds_copy[i]] * 2) << " ";
	}

	std::cout << std::endl;

}
