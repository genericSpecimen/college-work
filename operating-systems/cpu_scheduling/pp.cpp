#include<iostream>
#include<algorithm>
#include<climits>
class Process {
public:
	int pid;
	int arrival_time;
	int burst_time;
	int priority;
	int remaining_time;
	int wait_time;
	void setProcInfo(int i) {
		pid = i;
		std::cin >> priority >> arrival_time >> burst_time;
		this->remaining_time = burst_time;
		wait_time = 0;
	}
};

bool compareArrivalTime(Process& p1, Process& p2) {
	return p1.arrival_time < p2.arrival_time;
}

bool comparePriority(Process& p1, Process& p2) {
	return p1.priority < p2.priority;
}

bool isRemaining(Process proc[], int n) { //returns true if all the processes have finished execution
	for(int i=0;i<n;i++) {
		if(proc[i].remaining_time != 0) return true;
	}
	return false;
}

void displayProcesses(Process proc[], int size) {
	std::cout << "Process" << "\t" << "    Priority" << "\t" << "Arrival Time" << "\t" << "Burst time" << "\t" << "Wait time\n";
       	for(int i=0;i<size;i++) {
		std::cout << proc[i].pid << "\t\t" << proc[i].priority << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].burst_time << "\t\t" << proc[i].wait_time << std::endl;
	}
}

void calculate_waiting_times(Process proc[], int n) {
	int current_time = 0;
	int highest_priority_proc = 0;
	while(isRemaining(proc,n)) {
		int currently_inactive = 0;
		for(int i=0;i<n;i++) {
			if(proc[i].arrival_time > current_time || proc[i].remaining_time == 0) currently_inactive++;
		}
		if(currently_inactive == n) {
			current_time++;
			continue;
		}

		int highest_priority = INT_MAX; //declare here, y tho?
		for(int i=0;i<n;i++) {
			 if(proc[i].arrival_time <= current_time && proc[i].remaining_time > 0 && proc[i].priority < highest_priority) {
				//process has arrived by the current time and its priority
				//is higher than the current highest priority
				highest_priority = proc[i].priority;
			}
		}
		for(int i=0;i<n;i++) {
			if(proc[i].arrival_time <= current_time && proc[i].remaining_time > 0) {
				if(proc[i].priority == highest_priority) { std::cout << i << "here\n"; proc[i].remaining_time--;}
				else { std::cout << "yes\n";proc[i].wait_time++;}
			}
		}
		current_time++;
	}
}


int main() {
	int size = 4;
	Process proc[size];
	for(int i=0;i<size;i++) {
		std::cout << "Enter the priority, arrival_time and burst_time of process " << i << ": ";
		proc[i].setProcInfo(i);
	}
	std::sort(proc, proc+size, compareArrivalTime); //sort according to arrival time
	calculate_waiting_times(proc, size);
	displayProcesses(proc, size);
}
