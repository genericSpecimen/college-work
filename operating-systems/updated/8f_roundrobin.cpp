#include<iostream>
#include<algorithm>

class Process {
public:
	int pid;
	double burst_time;
	double wait_time;
	double remaining_time;
	void setProcInfo(int i) {
		this->pid = i;
		std::cin >> this->burst_time;
		this->remaining_time = burst_time;
		this->wait_time = 0;
	}
};


void calculate_waiting_times(Process proc[], int n, int quantum) {
	int t = 0;
	while(true) {
		bool done = true;
		for(int i=0;i<n;i++) {
			if(proc[i].remaining_time > 0) {
				done = false; // process not finished
				if(proc[i].remaining_time > quantum) {
					t += quantum;
					proc[i].remaining_time -= quantum;
				}
				else {
					t += proc[i].remaining_time;
					proc[i].wait_time = t - proc[i].burst_time;
					proc[i].remaining_time = 0;
				}
				
			}
		}
		if(done == true) break;
	}
}

double average_waiting_time(Process proc[], int n) {
	double sum = 0;
	for(int i=0;i<n;i++) sum += proc[i].wait_time;
	return sum/n;
}

int main() {
	int size = 3;
	int quantum = 2;
	Process proc[size];
	for(int i=0;i<size;i++) {
		std::cout << "Enter the burst_time of process " << i <<": ";
		proc[i].setProcInfo(i);
	}

	calculate_waiting_times(proc, size, quantum);
	std::cout << "Time quantum: " << quantum << std::endl;
	std::cout << "Process" << "\tBurst time" << "\t Waiting time" << std::endl;
	for(int i=0;i<size;i++) std::cout << proc[i].pid << "\t\t" << proc[i].burst_time << "\t\t" << proc[i].wait_time << std::endl; 
	std::cout << "Average waiting time: " << average_waiting_time(proc, size) << std::endl;
}
