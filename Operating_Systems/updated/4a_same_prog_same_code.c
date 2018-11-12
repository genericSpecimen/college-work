#include <stdio.h>
#include <unistd.h> //fork()
#include <sys/types.h> // pid_t

int main(void) {
    pid_t pid;

    pid = fork();
    if(pid < 0) {
		fprintf(stderr, "\nError creating child process!");
		return 1;
	}

    //both parent and child will execute this same for loop code
    for(int i=0;i<50;i++) 
        printf("This line is from pid %d, value = %d\n", pid, i);
}