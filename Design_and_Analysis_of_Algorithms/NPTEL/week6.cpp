#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    unsigned int start_time;
    unsigned int finish_time;
};

bool shorter_finish_time(const Event& e1, const Event& e2) {
    return e1.finish_time < e2.finish_time;
}

void print_events(const std::vector<Event>& events) {
    for(int i=0;i<events.size();i++) {
        std::cout << "Event " << i+1 << ": " << events[i].start_time << ", " << events[i].finish_time << "\n";
    }
}

int main() {
    unsigned int n; std::cin >> n;
    std::vector<Event> events;
    events.resize(n);
    unsigned int s, l;
    for(int i=0;i<n;i++) {
        std::cin >> s >> l;
        events[i].start_time = s;
        events[i].finish_time = s + l - 1;
    }
    //print_events(events);

    //std::cout << "\nSorting by increasing finish time..\n";
    std::sort(events.begin(), events.end(), shorter_finish_time);

    //print_events(events);

    unsigned int num_bookings_allocated = 0;
    unsigned int last_finish_time = 0;
    for(int i=0;i<n;i++) {
        if(events[i].start_time > last_finish_time) {
            //std::cout << "Allocated event: " << events[i].start_time << ", " << events[i].finish_time << "\n";
            num_bookings_allocated++;
            last_finish_time = events[i].finish_time;
        }
    }
    std::cout << num_bookings_allocated << "\n";

}
