#include <iostream>
#include <algorithm>
#include <vector>

int head = 53; //global scope as we need this in the shortest_seek_time function 

bool shortest_seek_time(int request1, int request2) {
    return (std::abs(head - request1) < std::abs(head - request2));
}

int main() {
    const int num_requests = 8;
    int requests_queue[] = {98,183,37,122,14,124,65,67};
    int seek_distance = 0;
    int total_head_movement = 0;

    //-----range of cylinders-----
    const int first_cylinder = 0;
    const int last_cylinder = 199;
    //----------------------------
    std::cout << "Requests: ";
    for(int i=0;i<num_requests;i++) std::cout << requests_queue[i] << " ";
    std::cout << std::endl;

    std::cout << "Enter the current head position: ";
    std::cin >> head;

    /*
    * push requests to the left of head into requests_left
    * push requests to the right of head into requests_right
    */
    std::vector<int> requests_left;
    std::vector<int> requests_right;
    for(int i=0;i<num_requests;i++) {
        if(requests_queue[i] <= head) requests_left.push_back(requests_queue[i]);
        else requests_right.push_back(requests_queue[i]);
    }

    // Assume direction towards the last_cylinder

    //sort requests_right according to the shortest seek time and serve the requests
    std::sort(requests_right.begin(), requests_right.end(), shortest_seek_time);
    for(std::vector<int>::iterator itr = requests_right.begin(); itr != requests_right.end(); ++itr) {
        seek_distance = std::abs(head - *itr);
        total_head_movement += seek_distance;
        std::cout << "Movement from " << head << " to " << *itr << " with seek distance: " << seek_distance << std::endl;
        head = *itr;
    }

    //go to last_cylinder manually in case there was no request at the last_cylinder
    seek_distance = std::abs(last_cylinder - head);
    total_head_movement += seek_distance;
    std::cout << "Movement from " << head << " to " << last_cylinder << " with seek distance: " << seek_distance << std::endl;
    head = last_cylinder;

    //then go to first_cylinder (according to C-SCAN)
    seek_distance = std::abs(first_cylinder - head);
    total_head_movement += seek_distance;
    std::cout << "Movement from " << head << " to " << first_cylinder << " with seek distance: " << seek_distance << std::endl;
    head = first_cylinder;

    //sort requests_left according to the shortest seek time and serve the requests
    std::sort(requests_left.begin(), requests_left.end(), shortest_seek_time);
    for(std::vector<int>::iterator itr = requests_left.begin(); itr != requests_left.end(); ++itr) {
        seek_distance = std::abs(head - *itr);
        total_head_movement += seek_distance;
        std::cout << "Movement from " << head << " to " << *itr << " with seek distance: " << seek_distance << std::endl;
        head = *itr;
    }

    std::cout << "\nTotal head movement: " << total_head_movement << std::endl;
}