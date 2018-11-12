#include <iostream>
#include <algorithm>

struct Hole {
    int size; //size of hole
    bool hole_in_use; //indicates whether the hole is in use
};

struct Process {
    int pid;
    int size;
    int allocated_to_hole; //indicates the hole number to which it's allocated
    bool is_allocated; //indicates whether the process has been allocated a hole
};

void print_allocation_table(Hole holes[], Process processes[], int num_holes, int num_processes) {
    std::cout << "\nAllocation Table\n";
    std::cout << "Process number\tProcess size\tHole number\tHole size\n";
    for(int i=0;i<num_processes;i++) {
        std::cout << processes[i].pid << "\t\t" << processes[i].size << "\t\t" << processes[i].allocated_to_hole;
        if(processes[i].allocated_to_hole == -1) {
            std::cout << "(not allocated)";
        } else std::cout << "\t\t" << holes[processes[i].allocated_to_hole].size;
        std::cout << std::endl;
    }
}

void first_fit_allocation(Hole holes[], Process processes[], int num_holes, int num_processes) {
    //allocate the first hole that's big enough
    for(int i=0;i<num_processes;i++) {
        for(int j=0;j<num_holes;j++) {
            if(!processes[i].is_allocated && !holes[j].hole_in_use && processes[i].size <= holes[j].size) {
                std::cout << "Allocated hole " << j << " to process " << i << std::endl;
                processes[i].allocated_to_hole = j;
                holes[j].hole_in_use = true;
                processes[i].is_allocated = true;
            }
        }
    }
}

bool is_smaller(const Hole& hole1, const Hole& hole2) {
    return hole1.size < hole2.size;
}
void best_fit_allocation(Hole holes[], Process processes[], int num_holes, int num_processes) {
    //allocate the smallest hole that's big enough

    //sort the holes according to their size
    std::sort(holes,holes+num_holes,is_smaller);
    std::cout << "Holes sorted according to smaller size: \n";
    for(int i=0;i<num_holes;i++) {
        std::cout << holes[i].size << " ";
    }
    std::cout << std::endl;
    //then simply perform first_fit allocation
    first_fit_allocation(holes,processes,num_holes,num_processes);
}

bool is_larger(const Hole& hole1, const Hole& hole2) {
    return hole1.size > hole2.size;
}
void worst_fit_allocation(Hole holes[], Process processes[], int num_holes, int num_processes) {
    //alocate the largest available hole

    //sort in descending order of hole size
    std::sort(holes, holes+num_holes, is_larger);
    std::cout << "Holes sorted according to larger size: \n";
    for(int i=0;i<num_holes;i++) {
        std::cout << holes[i].size << " ";
    }
    std::cout << std::endl;
    //then simply perform first_fit allocation
    first_fit_allocation(holes,processes,num_holes,num_processes);
}

int main() {
    const int num_holes = 6;
    Hole holes[num_holes] = {{100,false},{1500,false},{1200,false},{500,false},{900,false},{200,false}};

    const int num_processes = 5;
    Process processes[num_processes] = {{0,1200,-1,false},{1,1300,-1,false},{2,880,-1,false},{3,203,-1,false},{4,129,-1,false}};

    std::cout << "Hole sizes: ";
    for(int i=0;i<num_holes;i++) std::cout << holes[i].size << ", ";
    std::cout << std::endl;
    std::cout << "Process sizes: ";
    for(int i=0;i<num_processes;i++) std::cout << processes[i].size << ", ";
    std::cout << std::endl;

    std::cout << "Allocate using:\n";
    std::cout << "1. First-fit allocation\n";
    std::cout << "2. Best-fit allocation\n";
    std::cout << "3. Worst-fit allocation\n";
    std::cout << "Enter your option: ";
    int option; std::cin >> option;
    switch(option) {
        case 1: std::cout << "\nPerforming first-fit allocation...\n";
                first_fit_allocation(holes,processes,num_holes,num_processes);
                print_allocation_table(holes,processes,num_holes,num_processes); break;
        case 2: std::cout << "\nPerforming best-fit allocation...\n";
                best_fit_allocation(holes,processes,num_holes,num_processes);
                print_allocation_table(holes,processes,num_holes,num_processes); break;
        case 3: std::cout << "\nPerforming worst-fit allocation...\n";
                worst_fit_allocation(holes,processes,num_holes,num_processes);
                print_allocation_table(holes,processes,num_holes,num_processes); break;
        default: std::cout << "Invalid option!\n";
    }
}