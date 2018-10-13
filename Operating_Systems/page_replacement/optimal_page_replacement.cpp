#include <iostream>
#include <climits>

// GIST: Replace the page that will not be used for the longest period of time

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

int predict(int i, const std::string& reference_string, int frame[], int frame_size) {
    //returns the index of the page in frame which won't be used for the longest time

    /*
    *   for each page in the frame, keep next_occurence_index that keep track of the distance between the
    *   current page and the next occurence of the page in the frame
    */
    int next_occurence_index[frame_size];
    for(int i=0;i<frame_size;i++) next_occurence_index[i] = -1; //-1 indicates no next occurence found

    int page_in_frame;
    for(int j=0;j<frame_size;j++) { //for each page in frame
        page_in_frame = frame[j];
        //find the next occurence of this page in the reference string and 
        for(int index = i; index < reference_string.length(); index++) {
            if(reference_string[index] - '0' == page_in_frame) {
                next_occurence_index[j] = index;
                break;
            }
        }
        std::cout << "Next occurence of " << frame[j] << " is at index: " << next_occurence_index[j] << std::endl;
    }

    int max = INT_MIN;
    int max_index = -1;
    for(int j=0;j<frame_size;j++) {
        if(next_occurence_index[j] == -1) {
            //page at index j in frame never occurs again so we can remove it
            return j; //return the index of page in the frame that can be removed
        }
        else if (next_occurence_index[j] > max) {
            max = next_occurence_index[j];
            max_index = j;
        }
    }
    return max_index;
}

int main() {
    std::string reference_string("021640103121");
    //std::string reference_string("70120304230321201701");
    const int frame_size = 4;
    int frame[frame_size];
    for(int i=0;i<frame_size;i++) frame[i] = -1;
    int num_page_faults = 0;
    
    std::cout << "Reference string: " << reference_string << std::endl;
    std::cout << "Frame size: " << frame_size << std::endl;
    std::cout << "\nInitially, frame is: ";
    print_frame(frame, frame_size);
    std::cout << std::endl;

    int counter = 0; //keeps track of number of pages in frame
    for(int i=0;i<reference_string.length();i++) {
        int current_page = reference_string[i] - '0';
        if(counter < frame_size) {
           if(is_current_page_in_frame(frame,frame_size,current_page)) {
                //no page fault, do nothing
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
                //page fault: find the page that won't be used for the longest time and replace it
                std::cout << "---------------------------------------\n";
                int page_to_replace_index = predict(i, reference_string, frame, frame_size);
                std::cout << "Thus, we can replace page " << frame[page_to_replace_index] << std::endl;
                std::cout << "---------------------------------------\n";
                frame[page_to_replace_index] = current_page;
                std::cout << "Page " << current_page;
                std::cout << " =>  1 Page fault  => ";
                print_frame(frame, frame_size);
                num_page_faults++;
            }
        }
    }
    std::cout << "Total number of page faults: " << num_page_faults << std::endl;

}