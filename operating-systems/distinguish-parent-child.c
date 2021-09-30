#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void parentTask() {
    pid_t pid = getpid();
    printf("Parent process pid: %d.\n", pid);
    for (int i=100; i<=1000; i++) {
        printf("pid: %d (parent), i: %d\n", pid, i);
    }    
}

void childTask() {
    pid_t pid = getpid();
    printf("Child process pid: %d.\n", pid);
    for (int i=1100; i<=1500; i++) {
        printf("pid: %d (child) , i: %d\n", pid, i);
    }
}

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // fork returns 0 to child process
        childTask();
        
    } else {
        // and the child's pid to parent process
        parentTask();
    }
    
    return 0;
}
