#include <iostream>
#include <algorithm>

void print_requests_queue(int a[], int size) {
    for(int i=0;i<size;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}

int head = 53;

bool shortest_seek_time(int request1, int request2) {
    return (std::abs(head - request1) < std::abs(head - request2));
}

int main() {
    const int num_requests = 8;
    int requests_queue[] = {98,183,37,122,14,124,65,67};
    int seek_distance = 0;
    int total_head_movement = 0;

    std::cout << "Requests queue: ";
    print_requests_queue(requests_queue, num_requests);
    
    std::cout << "Enter the current head position: ";
    std::cin >> head;

    // sort according to the shortest seek time 
    std::sort(requests_queue, requests_queue + num_requests, shortest_seek_time);
    std::cout << "Sorted according to shortest seek time: ";
    print_requests_queue(requests_queue, num_requests);
    
    //then apply FCFS
    for(int i=0;i<num_requests;i++) {
        seek_distance = std::abs(head - requests_queue[i]);
        total_head_movement += seek_distance;
        std::cout << "Movement from " << head << " to " << requests_queue[i] << " with seek distance: " << seek_distance << std::endl;
        head = requests_queue[i];
    }

    std::cout << "\nTotal head movement: " << total_head_movement << std::endl;
}