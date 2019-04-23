#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void print_array(const std::vector<int>& a) {
    for(int x : a) std::cout << x << " ";
    std::cout << "\n";
}

namespace HeapSort {
    inline long int parent(long int i) {
        return (i-1)/2;
    }
    inline long int left(long int i) {
        return 2*i + 1;
    }
    inline long int right(long int i) {
        return 2*i + 2;
    }

    void max_heapify(std::vector<int>& a, long int i);
    void build_max_heap(std::vector<int>& a);
    void heap_sort(std::vector<int>& a);

    static unsigned long int heap_size = 0;
    static unsigned long int num_comparisons = 0;
}

void HeapSort::max_heapify(std::vector<int>& a, long int i) {
    long int l = HeapSort::left(i);
    long int r = HeapSort::right(i);
    long int largest = i;

    HeapSort::num_comparisons++;
    if(l < HeapSort::heap_size && a[l] > a[i]) largest = l;
    else largest = i;

    HeapSort::num_comparisons++;
    if(r < HeapSort::heap_size && a[r] > a[largest]) largest = r;

    if(largest != i) {
        std::swap(a[i], a[largest]);
        HeapSort::max_heapify(a, largest);
    }
}

void HeapSort::build_max_heap(std::vector<int>& a) {
    HeapSort::heap_size = a.size();
    for(long int i=(a.size()/2 - 1); i >= 0; i--) {
        HeapSort::max_heapify(a,i);
    }
}

void HeapSort::heap_sort(std::vector<int>& a) {
    HeapSort::build_max_heap(a);
    for(long int i=a.size()-1; i >= 1; i--) {
        std::swap(a[0], a[i]);
        HeapSort::heap_size--;
        HeapSort::max_heapify(a,0);
    }
}

int main() {

    std::vector<int> nums(100);
    std::random_device r;
    std::mt19937 mt_rand(r());
    std::uniform_int_distribution<int> dist(1,100);
    std::generate(nums.begin(), nums.end(), [&] () { return dist(mt_rand); });

    std::cout << "Original array:\n";
    print_array(nums);
    std::cout << "\n";

    HeapSort::heap_sort(nums);

    std::cout << "Sorted array: \n";
    print_array(nums);

    std::cout << "\n(Heap Sort) Number of comparisons performed: " << HeapSort::num_comparisons << "\n";
}
