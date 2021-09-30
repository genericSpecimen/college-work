#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;
    
    if (fork() == 0) {
        printf("Child ID: %d\n", getpid());
        //    name of file, vector (v) of arguments followed by a null pointer
        char * const args[] = {"ls", "-l", NULL};
        execvp("ls", args);
        
        // if we were using execv, we'd have to specify an absolute path to the file to be executed
        //execv("/bin/ls", args);
    }
    
    printf("Child ID (returned by wait): %d\n", wait(&status));
    printf("Exit status of child: %d\n", status);
}
