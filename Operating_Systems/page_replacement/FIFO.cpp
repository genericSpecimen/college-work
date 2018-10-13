#include <iostream>

void print_frame(int a[], int size) {
    for(int i=0;i<size;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}

bool is_current_page_in_frame(int frame[], int frame_size, int page) {
    for(int i=0;i<frame_size;i++) {
        if(frame[i] == page) return true;
    }
    return false;
}

int main() {
    std::string reference_string("021240103121");
    //std::string reference_string("70120304230321201701");

    const int frame_size = 4;
    int frame[frame_size];
    for(int i=0;i<frame_size;i++) frame[i] = -1;
    int num_page_faults = 0;
    
    std::cout << "Reference string: " << reference_string << std::endl;
    std::cout << "\nInitially, frame is: ";
    print_frame(frame, frame_size);
    std::cout << std::endl;

    int counter = 0; //keeps track of number of pages in frame
    int first_page_index = 0;
    for(int i=0;i<reference_string.length();i++) {
        int current_page = reference_string[i] - '0';
        if(counter < frame_size) {
            if(is_current_page_in_frame(frame,frame_size,current_page)) {
                //do nothing
                std::cout << "Page " << current_page;
                std::cout << " =>  No page fault => ";
                print_frame(frame, frame_size);
            } else {
                frame[counter] = current_page;
                std::cout << "Page " << current_page;
                std::cout << " =>  1 Page fault  => ";
                print_frame(frame, frame_size);
                num_page_faults++;
                counter++;
            }
        } else {
            if (is_current_page_in_frame(frame, frame_size, current_page)) {
                //do nothing
                std::cout << "Page " << current_page;
                std::cout << " =>  No page fault => ";
                print_frame(frame, frame_size);
            } else {
                //remove first page in frame and replace it with the current page and increment page faults
                frame[first_page_index % frame_size] = current_page;
                first_page_index++;
                num_page_faults++;
                std::cout << "Page " << current_page;
                std::cout << " =>  1 Page fault  => ";
                print_frame(frame, frame_size);
            }
        }
    }
    std::cout << "Total number of page faults: " << num_page_faults << std::endl;
}