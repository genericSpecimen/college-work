#include <iostream>
#include <vector>

void print_subset(const std::vector<unsigned int>& set, const std::vector<std::vector<unsigned int>>& M, unsigned int n, unsigned int W) {
    if(M[n][W] != W) {
        std::cout << "\nNo subset with the sum " << W << " exists!\n";
        return;
    } else {
        std::cout << "\nA subset with sum " << W  << " exists!\n";
        std::cout << "The subset is: {";

        int i = n;
        int w = W;
        while(w > 0 && i > 0) {
            if(M[i-1][w] == w) {
                i--;
            } else {
                std::cout << set[i-1] << ", ";
                w = w - set[i-1];
            }
        }
        std::cout << "}\n";
    }
}

void subset_sum(const std::vector<unsigned int>& set, unsigned int n, unsigned int W) {
    std::vector<std::vector<unsigned int>> M;
    M.resize(n+1, std::vector<unsigned int>(W+1));

    for(unsigned int w=0; w<W+1; w++) {
        M[0][w] = 0; // any sum w can't be achieved using 0 elements from the set
    }

    for(unsigned int i=1; i<n+1; i++) {
        for(unsigned int w=0; w<W+1; w++) {
            if(set[i-1] > w) {
                // value of ith element in set is greater than the current sum to be achieved, w
                M[i][w] = M[i-1][w]; // only option is to drop this element
            } else {
                // either drop the element or add the element, and choose the maximum sum
                M[i][w] = std::max(M[i-1][w], set[i-1] + M[i-1][w - set[i-1]]);
            }
        }
    }

    /*
    for(auto x:M) {
        for(auto y:x) std::cout << y << " ";
        std::cout << "\n";
    }
    */

    print_subset(set, M, n, W);

}

int main() {
    unsigned int n, W;
    std::vector<unsigned int> set;

    std::cout << "Enter the number of elements in the set: ";
    std::cin >> n;
    set.resize(n);

    std::cout << "Enter the elements of the set: ";
    for(unsigned int i=0;i<n;i++) std::cin >> set[i];

    std::cout << "Enter the sum to be found: ";
    std::cin >> W;

    subset_sum(set, n, W);
}
