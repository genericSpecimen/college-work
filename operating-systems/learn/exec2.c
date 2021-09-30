#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;
    
    if (fork() == 0) {
        printf("Child ID: %d\n", getpid());
        //execl("/bin/date", "date", 0);
        // search for an executable file in PATH environment variable
        execlp("date", "date", NULL);
    }
    
    printf("Child ID (returned by wait): %d\n", wait(&status));
    printf("Exit status of child: %d\n", status);
}
