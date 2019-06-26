#include <iostream>
#include <vector>
/*
void counting_sort(std::vector<int>& a, std::vector<int>& b, int k) {
    std::vector<int> c(k+1);
    for(int i=0;i<=k;i++) c[i] = 0;

    for(int j=0;j<a.size();j++) c[a[j]]++;

    for(int x:c) std::cout << x << " ";
    std::cout << "\n";

    for(int i=1;i<=k+1;i++) c[i] = c[i] + c[i-1];

    for(int x:c) std::cout << x << " ";
    std::cout << "\n";

    for(int j=a.size()-1; j>=0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]]--;
    }
}
*/

void counting_sort_exp(std::vector<int>& a, std::vector<int>& b, int exp) {
    std::vector<int> c(10);
    for(int i=0;i<10;i++) c[i] = 0;

    for(int i=0;i<a.size();i++) c[(a[i]/exp)%10]++;
/*
    for(int x:c) std::cout << x << " ";
    std::cout << "\n";
*/
    for(int i=1;i<10;i++) c[i] = c[i] + c[i-1];
/*
    for(int x:c) std::cout << x << " ";
    std::cout << "\n";
*/
    for(int i=a.size()-1; i>=0; i--) {
        b[c[ (a[i]/exp)%10 ] - 1] = a[i];
        c[(a[i]/exp)%10]--;
    }

    for (int i=0; i<a.size(); i++)
            a[i] = b[i];
}

void radix_sort(std::vector<int>& a, std::vector<int>& b, int k) {
    for(int exp=1; k/exp > 0; exp *= 10) counting_sort_exp(a,b,exp);
}

int main() {
    //std::vector<int> nums = {2,5,3,0,2,3,0,3};
    std::vector<int> nums = {329,457,657,839,436,720,355};
    std::vector<int> sorted_array(nums.size());
    int k = 839;
    //counting_sort(nums, sorted_array, k);

    radix_sort(nums, sorted_array, k);

    for(int x:sorted_array) std::cout << x << " ";
    std::cout << "\n";

}
