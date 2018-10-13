#include<iostream>
#include<algorithm>

class Process {
public:
	int pid;
	double burst_time;
	double wait_time;
	void setProcInfo(int i) {
		this->pid = i;
		std::cin >> this->burst_time;
		this->wait_time = 0;
	}
};

bool shorter_burst_time(Process& p1, Process& p2) {
	return p1.burst_time < p2.burst_time;
}

void calculate_waiting_times(Process proc[], int n) {
	proc[0].wait_time = 0;
	for(int i=1;i<n;i++) proc[i].wait_time = proc[i-1].wait_time + proc[i-1].burst_time;
}

double average_waiting_time(Process proc[], int n) {
	double sum = 0;
	for(int i=0;i<n;i++) sum += proc[i].wait_time;
	return sum/n;
}

int main() {
	int size = 4;
	Process proc[size];
	for(int i=0;i<size;i++) {
		std::cout << "Enter the burst_time of process " << i <<": ";
		proc[i].setProcInfo(i);
	}
	std::sort(proc, proc+size, shorter_burst_time);
	calculate_waiting_times(proc,size);
	std::cout << "Process" << "\tBurst time" << "\t Waiting time" << std::endl;
	for(int i=0;i<size;i++) std::cout << proc[i].pid << "\t\t" << proc[i].burst_time << "\t\t" << proc[i].wait_time << std::endl; 
	std::cout << "Average waiting time: " << average_waiting_time(proc, size) << std::endl;
}
