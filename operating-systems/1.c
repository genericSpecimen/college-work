#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
	int pid;
	pid = fork();
	if(pid < 0) {
		printf("\nError ");
		exit(1);
	}
	else if(pid == 0) {
		printf("\nHello I'm child process.");
		printf("\nMy pid is: %d \n", getpid());
		exit(0);
	}
	else {
		printf("\nHello I'm parent process.");
		printf("\nMy actual pid is: %d \n", getpid());
		exit(1);
	}
}
