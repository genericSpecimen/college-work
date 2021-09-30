#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void print_array(const std::vector<int>& a) {
    std::cout << "[ ";
    for(int x : a) std::cout << x << ", ";
    std::cout << "]";
    std::cout << "\n\n";
}

namespace QuickSort {
    static unsigned int num_comparisons = 0;
    long int partition(std::vector<int>& a, long int p, long int r);
    void quick_sort(std::vector<int>& a, long int p, long int r);
}

long int QuickSort::partition(std::vector<int>& a, long int p, long int r) {
    // randomly select an integer between [p, r] as the pivot index
    std::random_device rd;
    std::uniform_int_distribution<int> dist(p, r);
    std::mt19937 mt_rand(rd());
    int idx = dist(mt_rand);
    
    // exchange a[r] with a[idx]
    std::swap(a[r], a[idx]);
    
    // pivot: the element to be placed at correct position
    int pivot = a[r];
    long int i = p - 1;
    for(long int j = p; j < r; j++) {
        QuickSort::num_comparisons++;
        if(a[j] < pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i+1], a[r]);
    return i+1;
}


void QuickSort::quick_sort(std::vector<int>& a, long int p, long int r) {
    // A[p, ..., r] is the subarray to be sorted in this call
    long int q;
    if(p < r) {
        q = partition(a, p, r);
        
        // sort the subarray A[p, ..., q-1] recursively
        QuickSort::quick_sort(a, p, q-1);
        
        // sort the subarray A[q+1, ..., r] recursively
        QuickSort::quick_sort(a, q+1, r);
    }
}

/*
 // 
void quickSort(std::vector<int> &nums, int p, int r) {
    while (p < r) {
        int q = partition(nums, p, r);
        // recurse only on the smaller subarray
        if (q-p+1 < r-q+1) {
            quickSort(nums, p, q-1);
            p = q + 1;
        } else {
            quickSort(nums, q+1, r);
            r = q - 1;
        }
    }
}
*/

int main() {
    
    // generating a random array of size 100
    std::vector<int> A(100);
    std::random_device r;
    std::mt19937 mt_rand(r());
    std::uniform_int_distribution<int> dist(1,100);
    std::generate(A.begin(), A.end(), [&] () { return dist(mt_rand); });

    std::cout << "Original array A: " << "\n";
    print_array(A);
    
    // sorting the uniformly distributed array
    QuickSort::quick_sort(A, 0, A.size()-1);
    
    std::cout << "Sorted array A: " << "\n";
    print_array(A);
    std::cout << "(Randomized Quick Sort)\n";
    std::cout << "Number of comparisons performed:\n";
    std::cout << "1.) uniformly distributed unsorted array: " << QuickSort::num_comparisons << "\n";
    
    // sorting the already sorted array
    QuickSort::num_comparisons = 0;
    QuickSort::quick_sort(A, 0, A.size()-1);
    std::cout << "2.) already sorted array: " << QuickSort::num_comparisons << "\n";

}
