#include<stdlib.h>
#include<stdio.h>
int main() {
	printf("The configured memory is: \n");
	system("cat /proc/meminfo | awk 'NR==1 {print $2}'\n");
	printf("The free memory is: \n");
	system("cat /proc/meminfo | awk 'NR==2 {print $2}'\n");
	printf("The amount of used memory is: \n");
	system("cat /proc/meminfo | awk '{if(NR==1) a=$2; if(NR==2) b=$2}END {print a-b}'\n");
}
