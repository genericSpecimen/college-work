#include<stdio.h>
#include<stdlib.h>
int main() {

    //part (a)
	printf("The kernel version is: \n");
	system("cat /proc/sys/kernel/osrelease\n");
	
    //part (b)
    printf("The CPU space is: \n");
	system("cat /proc/cpuinfo | awk 'NR==3,NR==4{print}'\n");
    printf("Amount of cpu time since system was last booted is: \n");
	system("cat /proc/uptime\n");

    //part (c)
    printf("The configured memory is: \n");
	system("cat /proc/meminfo | awk 'NR==1 {print $2}'\n");
	printf("The free memory is: \n");
	system("cat /proc/meminfo | awk 'NR==2 {print $2}'\n");
	printf("The amount of used memory is: \n");
	system("cat /proc/meminfo | awk '{if(NR==1) a=$2; if(NR==2) b=$2}END {print a-b}'\n");
}
