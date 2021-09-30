#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    
    /*
     * There are different ways to do this:
     * 
     * 1. We can manually count the number of processes created by printing any statement after all the fork calls.
     * For example, if the print statement runs 8 times, then there must have been 8 processes running (including original parent).
     * 
     * 2. Another way to do this would be to use the general formula:
     * if there are n fork() calls, then the number of child processes created = 2^n - 1
     * 
     * 3. In case we want to use an algorithm that automatically counts the number of child processes, then,
     * we need a way for inter-process communication (e.g., pipes / shared memory) since each child would
     * have a separate copy of any counter variable we declare, and we need a way to share this value with
     * the parent process.
     * 
     * 
     * Compilation and running: gcc Q2_count-child-processes.c -lm && ./a.out
     */
    
    pid_t original_parent_pid = getpid();
    int num_forks; // only used by parent for the formula method
    fork();
    num_forks++;
    fork();
    num_forks++;
    fork();
    num_forks++;
    
    printf("Process pid: %d\n", getpid());
    
    if (getpid() == original_parent_pid) {
        printf("Number of forks in source program: %d\n", num_forks);
        printf("Total number of child processes created: %d\n", (int)(pow(2, num_forks) - 1));
    }
    return 0;
}
