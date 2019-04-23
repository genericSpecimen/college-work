/*
#include <iostream>
bool func(int a[], int size, int sum) {
	
	int i = 0; // first element
	int j = size-1; // last element
	
	while(i < j) {
		if(a[i] + a[j] == sum) return true;
                else if(a[i] + a[j] > sum) j--; // we need a smaller sum
                else i++; // we need a bigger sum
        }
	return false;
	
}

int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(a)/sizeof(a[0]);
	int sum = 15;
	std::cout << std::boolalpha << func(a,size,sum) << std::endl;
	std::cout << std::boolalpha << func(a,size,0) << std::endl;
}
*/

#include <iostream>
//#include <algorithm>
#include <vector>
#include <random>

int main() {
    std::vector<std::string> days = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    std::random_device r;
    std::mt19937 mt_rand(r());
    std::uniform_int_distribution<int> dist(0,6);
    std::string random_days("");
    for(int i=0;i<1000;i++) {
        //std::cout << dist(mt_rand) << " ";
        random_days.append(days[dist(mt_rand)]);
    }
    std::cout << random_days << "\n";
}
