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

void calculate_waiting_times(Process proc[], int n) {
	int complete = 0;
	int current_time = 0;
	int highest_priority_proc = 0; //index of the highest priority process
	int finish_time;
	bool preempt = false;
	int currently_inactive = 0;
	while(complete != n) {
		for(int i=0;i<n;i++) {
			if(proc[i].arrival_time > current_time || proc[i].remaining_time == 0) {
				currently_inactive++;
			}
		}
		if(currently_inactive == n) {
			current_time++;
			continue;
		}
		int highest_priority = INT_MAX; //lower numbers indicate higher priority
		for(int i=0;i<n;i++) {
			if(proc[i].arrival_time <= current_time && proc[i].priority < highest_priority && proc[i].remaining_time > 0) {
				highest_priority = proc[i].priority;
				highest_priority_proc = i;
				preempt = true;
			}
		}
		if(preempt == true) {
			proc[highest_priority_proc].remaining_time--;
			if(proc[highest_priority_proc].remaining_time == 0) {
				complete++;
				finish_time = current_time + 1;
				proc[highest_priority_proc].wait_time = finish_time - proc[highest_priority_proc].burst_time - proc[highest_priority_proc].arrival_time;
			}
			current_time++;
		} else {
			current_time++;
		}
	}
}

double avg_waiting_time(Process proc[], int size) {
	int sum = 0;
	for(int i=0;i<size;i++) {
		sum += proc[i].wait_time;
	}
	return sum/(double)size;
}

int main() {
	int size = 7;
	Process proc[size];
	for(int i=0;i<size;i++) {
		std::cout << "Enter the priority, arrival_time and burst_time of process " << i << ": ";
		proc[i].setProcInfo(i);
	}
	std::sort(proc, proc+size, compareArrivalTime); //sort according to arrival time
	calculate_waiting_times(proc, size);
	std::cout << "Process" << "\t" << "    Priority" << "\t" << "Arrival Time" << "\t" << "Burst time" << "\t" << "Wait time\n";
       	for(int i=0;i<size;i++) {
		std::cout << proc[i].pid << "\t\t" << proc[i].priority << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].burst_time << "\t\t" << proc[i].wait_time << std::endl;
	}
	std::cout << "Average waiting time is: " << avg_waiting_time(proc, size) << std::endl;
}
