#include <iostream>
#include <map>
#include <vector>
#include <climits>
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

int find_MFU(int frame[], int frame_size, std::map<char, int> references) {

    /*
    std::cout << "\nOCCURENCES:\n";
    for(std::map<char,int>::iterator itr = references.begin(); itr != references.end(); itr++) {
        std::cout << "Page " << itr->first << " => " << itr->second << std::endl;
    }
    std::cout << std::endl;
    */

    std::map<char, int> pages_in_frame_occurences;
    for(std::map<char,int>::iterator itr = references.begin(); itr != references.end(); itr++) {
        if(is_current_page_in_frame(frame,frame_size, (itr->first -'0'))) {
            pages_in_frame_occurences.insert(std::pair<char, int>(itr->first, itr->second));
        }
    }

    std::cout << "-------------------------------\n";
    std::cout << "Occurences of pages in frame:\n";
    for(std::map<char,int>::iterator itr = pages_in_frame_occurences.begin(); itr != pages_in_frame_occurences.end(); itr++) {
        std::cout << "Page " << itr->first << " => " << itr->second << std::endl;
    }

    char max_key;
    int max_value = INT_MIN; 
    for(std::map<char,int>::iterator itr = pages_in_frame_occurences.begin(); itr != pages_in_frame_occurences.end(); itr++) {
        if(itr->second > max_value) {
            max_value = itr->second;
            max_key = itr->first;
        }
    }

    int index = 0;
    for(index=0;index<frame_size;index++) {
        char ch = frame[index] + 48;
        if(ch == max_key) {
            break;
        }
    }
    return index; //return the index of page in frame that can be replaced
}

int main() {
    std::string reference_string("021240103121");
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
    std::map<char, int> references; //keeps track of number of occurences
    for(int i=0;i<reference_string.length();i++) { 

        int current_page = reference_string[i] - '0';
        if(counter < frame_size) {
            if(is_current_page_in_frame(frame, frame_size, current_page)) {
                //do nothing, no page fault
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
                //find the MFU page and replace it with current page
                int index = find_MFU(frame, frame_size, references);
                std::cout << "Most frequently used: Page " << frame[index] << std::endl;
                std::cout << "-------------------------------\n";
                frame[index] = current_page;
                num_page_faults++;
                std::cout << "Page " << current_page;
                std::cout << " =>  1 Page fault  => ";
                print_frame(frame, frame_size);
            }
        }
        //increment occurence of current page by one
        references[reference_string[i]]++;
    }
    std::cout << "Total number of page faults: " << num_page_faults << std::endl;
}