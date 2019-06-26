#include <iostream>

// size in bytes
int PHYSICAL_MEM_SIZE;
int PAGE_SIZE; // PAGE_SIZE == FRAME_SIZE
int FRAME_SIZE;

//--FRAMES IN PHYSICAL MEMORY ARE SHARED BY ALL PROCESSES--
int num_frames = 0;
int num_free_frames = 0;

class Page {
public:
    int page_number;
    bool is_allocated_frame; //denotes whether the page has been allocated a frame
};

class Frame {
public:
    int frame_number;
    bool is_in_use; //denotes whether the frame is being used
    int frame_allocated_to_process; // pid of the process which has been allocated this frame
};

class Process {
public:
    int pid;
    int process_size;
    int num_pages;
    Page* pages;
    int* page_table; // page table is specific to each process
    Process() {}
    void init() {
        num_pages = process_size/PAGE_SIZE + 1; //one extra frame in case not divisible by PAGE_SIZE

        // create num_pages pages and initialise them
        pages = new Page[num_pages];
        for(int i=0;i<num_pages;i++) {
            pages[i].page_number = i;
            pages[i].is_allocated_frame = false;
        }

        // create the page table for this process and initialise
        // it with -1 to indicate no allocation has taken place yet
        page_table = new int[num_pages];
        for(int i=0;i<num_pages;i++) page_table[i] = -1;
    }
    ~Process() {
        delete[] pages;
        delete[] page_table;
    }
    void print_page_table() {
        std::cout << "Index\tFrame number\n";
        for(int i=0;i<num_pages;i++) {
            std::cout << i << "\t" << page_table[i] << std::endl;
        }
    }
};

void allocate_frames_to_process(Process& proc, Frame frames[]) {
    if(proc.num_pages > num_free_frames) {
        std::cout << "Error! Not enough frames in memory available!\n";
        return;
    }
    std::cout << "------------------------------------------\n";
    std::cout << "\nAllocating frames to process pid " << proc.pid << " ...\n";
    //std::cout << "\nAllocating frames to " << proc.num_pages << " pages...\n";
    //for each page, find a free frame to be allocated
    for(int i=0;i<proc.num_pages;i++) {
        for(int j=0;j<num_frames;j++) {
            if(!proc.pages[i].is_allocated_frame && !frames[j].is_in_use) {
                // std::cout << "Allocated frame " << frames[j].frame_number << " to page " << proc.pages[i].page_number << " of process " << proc.pid << std::endl;
                proc.pages[i].is_allocated_frame = true;
                frames[j].is_in_use = true;
                proc.page_table[i] = frames[j].frame_number;
                frames[j].frame_allocated_to_process = proc.pid;
                num_free_frames--;
            }
        }
    }
    // proc.print_page_table();
    std::cout << "Done!\n";
    std::cout << "------------------------------------------\n";
}

void deallocate_frames(int pid, Frame frames[]) {
    std::cout << "\nDeallocating frames for process pid " << pid << " ...\n";
    for(int i=0;i<num_frames;i++) {
        if(frames[i].frame_allocated_to_process == pid) {
            frames[i].frame_allocated_to_process = -1;
            frames[i].is_in_use = false;
            num_free_frames++;
        }
    }
    std::cout << "Done!\n";
}

void print_frame_table(const Frame frames[]) {
    // prints the frame table that is shared by all processes

    std::cout << "---------------FRAME TABLE---------------\n";
    std::cout << "Frame number\tAllocated to process pid\n";
    for(int i=0;i<num_frames;i++) {
        std::cout << frames[i].frame_number << "\t\t" << frames[i].frame_allocated_to_process << std::endl;
    }
    std::cout << "------------------------------------------\n";
}

int main() {

    std::cout << "Enter page size and size of physical memory: ";
    std::cin >> PAGE_SIZE >> PHYSICAL_MEM_SIZE;
    FRAME_SIZE = PAGE_SIZE;

    //--Create frames-----------------------------------------
    num_frames = PHYSICAL_MEM_SIZE/FRAME_SIZE;
    num_free_frames = num_frames;
    std::cout << "Total number of frames in physical memory: " << num_frames << std::endl;

    Frame* frames = new Frame[num_frames];
    for(int i=0;i<num_frames;i++) {
        frames[i].frame_number = i;
        frames[i].is_in_use = false;
        frames[i].frame_allocated_to_process = -1;
        
    }
    //---------------------------------------------------------

    int num_processes = 0;
    std::cout << "Enter the number of processes: ";
    std::cin >> num_processes;
    Process* processes = new Process[num_processes];
    for(int i=0;i<num_processes;i++) {
        std::cout << "Enter process pid and memory required by the process " << i << ": " ;
        std::cin >> processes[i].pid >> processes[i].process_size;
        processes[i].init();
    }

    //allocate memory to these processes
    for(int i=0;i<num_processes;i++) {
        allocate_frames_to_process(processes[i], frames);
    }

    std::cout << "\nWhat do you want to do?";
    std::cout << "\n1. Display corresponding frame number allocated to a page number in process.";
    std::cout << "\n2. De-allocate memory and display frame table.";
    std::cout << "\n3. Display frame table.";
    char ans = 'y';
    do {
        std::cout << "\nEnter your option: ";
        int option; std::cin >> option;
        switch(option) {
        case 1: {
                std::cout << "Enter process pid and page number: ";
                int process_id; int page_number;
                std::cin >> process_id >> page_number;
                for(int i=0;i<num_processes;i++) {
                    if(processes[i].pid == process_id) {
                        if(processes[i].num_pages-1 >= page_number) {
                        std::cout << "Page " << page_number << " of process " << process_id << " has been allocated frame " << processes[i].page_table[page_number] << std::endl;
                        } else std::cout << "Invalid page number!\n";
                    }
                }
                break;
        }
        case 2: {
                std::cout << "Enter process pid: ";
                int pid;
                std::cin >> pid;
                deallocate_frames(pid,frames);
                print_frame_table(frames);
                break;
        }
        case 3: print_frame_table(frames);
        default: std::cout << "Invalid option!\n";
        }
        std::cout << "Do you want to continue?(y/n): ";
        std::cin >> ans;
    } while(ans == 'y' || ans == 'Y');
    delete[] processes;
    delete[] frames;
}