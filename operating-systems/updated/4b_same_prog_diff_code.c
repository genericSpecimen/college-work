#include <stdio.h>
#include <unistd.h> //fork()
#include <sys/types.h> // pid_t

#define MAX_COUNT 200

void child_process() {
    for (int i = 0; i < MAX_COUNT; i++)
        printf("This line is from child, value = %d\n", i);
    printf("*** Child process is done ***\n");
}

void parent_process() {
    for (int i = 0; i < MAX_COUNT; i++)
        printf("This line is from parent, value = %d\n", i);
    printf("*** Parent process is done ***\n");
}


int main(void) {
    pid_t pid;

    pid = fork();
    if(pid < 0) {
		fprintf(stderr, "\nError creating child process!");
		return 1;
	}
    else if(pid == 0) {
        //child process
        child_process();
    }
    else {
        //parent process
        parent_process();
    }
}