#include<iostream>
#include<climits>
class Process {
public:
	int pid;
	int arrival_time;
	int burst_time;
	int remaining_time;
	int wait_time;
	void setProcInfo(int i) {
		pid = i;
		std::cin >> arrival_time >> burst_time;
		this->remaining_time = burst_time;
		wait_time = 0;
	}
};

void calculate_waiting_times(Process proc[], int n) {
	int complete = 0; //keeps track of the number of completed processes
       	int current_time = 0; //keeps track of the current time
       	int min_rem_time = INT_MAX; //keeps track of the minimum remaining time
	int min_proc = 0; //keeps track of the index of the process with minimum remaining time in the process array
	int finish_time;
	bool preempt = false; //keeps track of whether a process has been preempted at the current time
	while(complete != n) {
		for(int i=0;i<n;i++) {
			if(proc[i].arrival_time <= current_time && proc[i].remaining_time < min_rem_time && proc[i].remaining_time > 0) {
				/*
				 * process has arrived by the current time and its remaining time is less than the
				 * previous minimum remaining time, so now we need to preempt this process.
				 */
				min_rem_time = proc[i].remaining_time;
				min_proc = i;
				preempt = true;
			}
		}

		if(preempt == true) {
			proc[min_proc].remaining_time--; //decrement remaining time of the preempted process by 1
			//update minimum remaining time
			min_rem_time = proc[min_proc].remaining_time;
		       	if(min_rem_time == 0) min_rem_time = INT_MAX;
			if(proc[min_proc].remaining_time == 0) {
				//process has finished execution
				complete++;
				finish_time = current_time + 1;
				proc[min_proc].wait_time = finish_time - proc[min_proc].burst_time - proc[min_proc].arrival_time;
			}
			current_time++;
		} else {
			current_time++; //increment current time
		}
	}
}

double avg_waiting_time(Process proc[], int size) {
	double sum = 0;
	for(int i=0;i<size;i++) sum += proc[i].wait_time;
	return sum/size;
}

int main() {
	int size = 4;
	Process proc[size];
	for(int i=0;i<size;i++) {
		std::cout << "Enter the arrival_time and burst_time of process " << i << ": ";
		proc[i].setProcInfo(i);
	}
	calculate_waiting_times(proc, size);
	std::cout << "Process" << "\t" << "Arrival Time" << "\t" << "Burst time" << "\t" << "Wait time\n";
       	for(int i=0;i<size;i++) {
		std::cout << proc[i].pid << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].burst_time << "\t\t" << proc[i].wait_time << std::endl;
	}
	std::cout << "Average waiting time is: " << avg_waiting_time(proc, size) << std::endl;
}
