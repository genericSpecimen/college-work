#include<iostream>
int main() {
	int num_p = 3;
	int burst_times[num_p];
	int wait_times[num_p];
	

	for(int i=0; i<num_p; i++) {
		std::cout << "Enter the CPU Burst time of process " << i << ": ";
		std::cin >> burst_times[i];
	}
	wait_times[0] = 0;
	for(int i=1;i<num_p;i++) {
		wait_times[i] = wait_times[i-1] + burst_times[i-1];
	}
	std::cout << "Process" << "\tBurst time" << "\tWaiting time" << std::endl;
	for(int i=0;i<num_p;i++) {
		std::cout << i << "\t\t" << burst_times[i] << "\t\t" << wait_times[i] << std::endl;
	}
	double sum=0;
	std::cout << "Average waiting time: ";
	for(int i=0;i<num_p;i++) sum += wait_times[i];
	std::cout << sum/num_p << std::endl;
}