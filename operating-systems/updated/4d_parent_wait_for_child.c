#include <stdio.h>
#include <unistd.h> // fork()
#include <sys/types.h> // pid_t
#include <sys/wait.h> // wait()

int main(int argc, char* argv[]) {
    pid_t pid;

    pid = fork();
    if(pid < 0) {
		fprintf(stderr, "\nError creating child process!");
		return 1;
	}

    else if(pid == 0) {
        //child process
        for(int i=0;i<50;i++) 
            printf("Child process: value = %d\n", i);
        printf("*** Child process complete! ***\n");
    }
    else {
        //parent process

        /*
            wait(NULL) is the shorthand for waitpid(-1, NULL, 0);, which suspends the execution
            of the calling process until any one child process exits.
            Here, 1st argument of waitpid indicates wait for any child process to end.
        */
        wait(NULL);
        printf("*** Parent process complete! ***\n");
    }
}