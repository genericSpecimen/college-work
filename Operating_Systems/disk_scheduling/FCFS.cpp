#include <iostream>

int main() {
    const int num_requests = 8;
    int requests_queue[] = {98,183,37,122,14,124,65,67};
    int head = 53;
    int seek_distance = 0;
    int total_head_movement = 0;

    std::cout << "Enter the current head position: ";
    std::cin >> head;

    for(int i=0;i<num_requests;i++) {
        seek_distance = std::abs(head - requests_queue[i]);
        total_head_movement += seek_distance;
        std::cout << "Movement from " << head << " to " << requests_queue[i] << " with seek distance: " << seek_distance << std::endl;
        head = requests_queue[i];
    }

    std::cout << "\nTotal head movement: " << total_head_movement << std::endl;
}