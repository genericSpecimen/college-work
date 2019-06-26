#include <iostream>
double pow(double base, unsigned int power) {
    if(power == 0) return 1;
    return base*pow(base, power-1);
} 

int main() {
    unsigned int power;
    double base;
    std::cout << "Enter base and the power to compute: ";
    std::cin >> base >> power;
    std::cout << pow(base, power) << std::endl;
}