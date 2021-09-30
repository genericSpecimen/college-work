#include <iostream>
#include <algorithm>
#include <vector>
/*
 * The isPalindrome() function takes a string as an input,
 * and returns true if the string is a palindrome.
 * Otherwise, it returns false
 */
bool isPalindrome(const std::string &str) {
    /* reverse the string and compare */
    std::string copy(str);
    std::reverse(copy.begin(), copy.end());
    if (copy.compare(str) != 0) {
        return false;
    }
    return true;
}

int main() {
    // a vector of strings to be tested
    std::vector<std::string> strs = {
        "racecar",
        "hello",
        "02022020",
        "generic string"
    };
    
    // iterate through all strings and test if it is a palindrome
    for (std::string& s : strs) {
        std::cout << "\"" << s << "\"" << " is a palindrome: ";
        std::cout << std::boolalpha << (isPalindrome(s)) << "\n";
    }
    
    /* xyz */ /* abcd */
    return 0;
    
}
