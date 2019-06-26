#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main() {
	std::vector<int> nums(100);
	std::random_device r;
	std::mt19937 mt_rand(r());
	std::uniform_int_distribution<int> dist(1,1000);
	std::generate(nums.begin(), nums.end(), [&] () { return dist(mt_rand); });
	std::cout << "nums: ";
	for(auto x : nums) std::cout << x << " ";
	std::cout << std::endl;
}
