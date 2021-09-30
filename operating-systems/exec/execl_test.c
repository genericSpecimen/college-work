#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;
    
    if (fork() == 0) {
        printf("Child ID: %d\n", getpid());
        //    name of file, list of arguments followed by a null pointer
        execl("/bin/date", "date", 0);
    }
    
    printf("Child ID (returned by wait): %d\n", wait(&status));
    printf("Exit status of child: %d\n", status);
}
