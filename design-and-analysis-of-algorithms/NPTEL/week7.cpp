#include <iostream>
#include <vector>

int max_subarray_sum_drop_k(const std::vector<int>& marks, int k, std::vector<std::vector<int>>& best) {

    // when j == 0, the problem is the classical maximum sum subarray, solve using Kadane's algorithm
    best[0][0] = marks[0];
    int max_so_far = best[0][0];
    //std::cout << "\n" << best[0][0] << "\n";
    for(int i=1;i<marks.size();i++) {
        // compute best[i][0]
        best[i][0] = std::max(marks[i], best[i-1][0] + marks[i]);
        max_so_far = std::max(max_so_far, best[i][0]);
        //std::cout << best[i][0] << "\n";
    }
    //std::cout << max_so_far << "\n";

    for(int j=1;j<=k;j++) {
        best[0][j] = best[0][j-1];
        for(int i=1;i<marks.size();i++) {
            // compute best[i][j]
            best[i][j] = std::max(std::max(marks[i]+best[i-1][j], best[i-1][j-1]), best[i][j-1]);
            max_so_far = std::max(max_so_far, best[i][j]);
        }
    }
    return max_so_far;
}

int main() {
    //two integers N and K, where N is the number of tests for which marks will be provided
    //and K is the limit of how many entries may be dropped from a segment.
    unsigned int n, k; std::cin >> n >> k;
    std::vector<int> marks; marks.resize(n);

    std::vector<std::vector<int>> best;
    best.resize(n, std::vector<int>(k+1));

    for(int i=0;i<n;i++) {
        std::cin >> marks[i];
    }

    std::cout << max_subarray_sum_drop_k(marks, k, best) << "\n";
}
