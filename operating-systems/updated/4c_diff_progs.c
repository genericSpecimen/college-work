#include <stdio.h>
#include <unistd.h> //fork() and exec()
#include <sys/types.h> // pid_t

int main(int argc, char* argv[]) {
    pid_t pid;

    pid = fork();
    if(pid < 0) {
		fprintf(stderr, "\nError creating child process!");
		return 1;
	}

    else if(pid == 0) {
        //child process
        char* const parmList[] = {"/bin/ls", "-l", NULL};
        execv("/bin/ls", parmList);

        //any statements after exec() will not be executed
        printf("This will not be printed\n");
    }
    else {
        //parent process
        char* const parmList[] = {"/bin/echo", "hello ", "world", NULL};
        execv("/bin/echo", parmList);
        
        //any statements after exec() will not be executed
        printf("This will not be printed\n");
    }
}