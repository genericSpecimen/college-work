#include <iostream>

void reverse() {
    char ch;
    std::cin.get(ch);
    if(ch != '\n') {
        reverse();
        std::cout << ch;
    }
}

int main() {
    std::cout << "Enter a string to reverse it: \n";
    reverse();
    std::cout << std::endl;
}