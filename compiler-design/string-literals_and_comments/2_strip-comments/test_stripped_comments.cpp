#include <iostream>
#include <algorithm>
#include <vector>

bool isPalindrome(const std::string &str) {
    
    std::string copy(str);
    std::reverse(copy.begin(), copy.end());
    if (copy.compare(str) != 0) {
        return false;
    }
    return true;
}

int main() {
    
    std::vector<std::string> strs = {
        "racecar",
        "hello",
        "02022020",
        "generic string"
    };
    
    
    for (std::string& s : strs) {
        std::cout << "\"" << s << "\"" << " is a palindrome: ";
        std::cout << std::boolalpha << (isPalindrome(s)) << "\n";
    }
    
     
    return 0;
    
}
