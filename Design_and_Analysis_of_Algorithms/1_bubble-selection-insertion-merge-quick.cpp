#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void print_array(const std::vector<int>& a) {
    for(int x : a) std::cout << x << " ";
    std::cout << "\n";
}

std::vector<int> bubble_sort(std::vector<int> a) {
    unsigned int num_comparisons_bubble = 0;
    bool swapped = false;
    for(long int i=0;i<a.size();i++) {
        for(long int j=0;j<a.size()-1-i;j++) {
            num_comparisons_bubble++;
            if(a[j] > a[j+1]) {
                swapped = true;
                std::swap(a[j], a[j+1]);
            }
        }
        if(!swapped) break;
    }
    std::cout << "\n(Bubble sort) Number of comparisons performed: " << num_comparisons_bubble << "\n";
    return a;
}

std::vector<int> selection_sort(std::vector<int> a) {
    unsigned int num_comparisons_selection = 0;

    long int min_element_index;
    for(long int i=0;i<a.size()-1;i++) {
        min_element_index = i;
        for(long int j=i+1;j<a.size();j++) {
            num_comparisons_selection++;
            if(a[j] < a[min_element_index]) min_element_index = j;
        }
        if(min_element_index != i) std::swap(a[min_element_index], a[i]);
    }
    std::cout << "\n(Selection sort) Number of comparisons performed: " << num_comparisons_selection << "\n";
    return a;
}

std::vector<int> insertion_sort(std::vector<int> a) {
    unsigned int num_comparisons = 0;

    size_t j;
    int key;
    for(size_t i=1;i<a.size();i++) {
        key = a[i];
        j = i-1;

        while(j>=0) {
            num_comparisons++;
            if(a[j]>a[j+1]) {
                std::swap(a[j],a[j+1]);
                j--;
            } else break;
        }
        a[j+1] = key;
    }

    std::cout << "\n(Insertion sort) Number of comparisons performed: " << num_comparisons << "\n";
    return a;
}

namespace MergeSort {
    static unsigned int num_comparisons = 0;
    void merge(std::vector<int>& a, unsigned int p, unsigned int q, unsigned int r);
    void merge_sort(std::vector<int>& a, unsigned int p, unsigned int r);
}

void MergeSort::merge(std::vector<int>& a, unsigned int p, unsigned int q, unsigned int r) {
    unsigned int size1 = q - p + 1;
    unsigned int size2 = r - q;

    std::vector<int> left_half; left_half.resize(size1);
    std::vector<int> right_half; right_half.resize(size2);

    for(size_t i=0;i<left_half.size();i++) left_half[i] = a[p+i];
    for(size_t j=0;j<right_half.size();j++) right_half[j] = a[q+1+j];

    size_t i=0, j=0, k=p;
    while(i < size1 && j < size2) {
        MergeSort::num_comparisons++;
        if(left_half[i] < right_half[j]) a[k++] = left_half[i++];
        else a[k++] = right_half[j++];
    }

    while(i<size1) a[k++] = left_half[i++];
    while(j<size2) a[k++] = right_half[j++];
}

void MergeSort::merge_sort(std::vector<int>& a, unsigned int p, unsigned int r) {
    if(p < r) {
        unsigned int q = (p + r)/2;
        MergeSort::merge_sort(a,p,q);
        MergeSort::merge_sort(a,q+1,r);
        MergeSort::merge(a,p,q,r);
    }
}

namespace QuickSort {
    static unsigned int num_comparisons = 0;
    long int partition(std::vector<int>& a, long int p, long int r);
    void quick_sort(std::vector<int>& a, long int p, long int r);
}

long int QuickSort::partition(std::vector<int>& a, long int p, long int r) {
    int pivot = a[r]; // element to be placed at correct position
    long int i = p-1;
    for(long int j=p;j<r;j++) {
        QuickSort::num_comparisons++;
        if(a[j] < pivot) {
            i++;
            std::swap(a[i],a[j]);
        }
    }
    std::swap(a[i+1], a[r]);
    return i+1;
}

void QuickSort::quick_sort(std::vector<int>& a, long int p, long int r) {
    long int q;
    if(p < r) {
        q = partition(a,p,r);
        QuickSort::quick_sort(a,p,q-1);
        QuickSort::quick_sort(a,q+1,r);
    }
}


int main() {
    std::vector<int> sorted_array; // to hold the sorted array

    std::vector<int> nums(100);
    std::random_device r;
    std::mt19937 mt_rand(r());
    std::uniform_int_distribution<int> dist(1,100);
    std::generate(nums.begin(), nums.end(), [&] () { return dist(mt_rand); });

    std::cout << "Original array: " << "\n";
    print_array(nums);

    sorted_array = bubble_sort(nums);
    print_array(sorted_array);

    sorted_array = selection_sort(nums);
    print_array(sorted_array);

    sorted_array = insertion_sort(nums);
    print_array(sorted_array);

    std::vector<int> nums_copy = nums;
    MergeSort::merge_sort(nums_copy, 0, nums_copy.size()-1);
    std::cout << "\n(Merge Sort) Number of comparisons performed: " << MergeSort::num_comparisons << "\n";
    print_array(nums_copy);

    std::vector<int> nums_copy_1 = nums;
    QuickSort::quick_sort(nums_copy_1, 0, nums_copy_1.size()-1);
    std::cout << "\n(Quick Sort) Number of comparisons performed: " << QuickSort::num_comparisons << "\n";
    print_array(nums_copy_1);

}
