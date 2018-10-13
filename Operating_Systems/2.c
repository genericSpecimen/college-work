#include<stdio.h>
#include<stdlib.h>
int main() {
	printf("The kernel version is: \n");
	system("cat /proc/sys/kernel/osrelease\n");
	printf("The CPU space is: \n");
	system("cat /proc/cpuinfo | awk 'NR==3,NR==4{print}'\n");
    printf("Amount of cpu time since system was last booted is: \n");
	system("cat /proc/uptime\n");
}
