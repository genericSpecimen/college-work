#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void signal_handler(int sig_num) {
    // forceful termination: SIGINT, SIGTERM
    
    switch (sig_num) {
        case SIGTERM:
            fprintf(stderr, "\nCaught SIGTERM : program interrupted, most likely due to a kill command. signal_handler function invoked.\n");
            exit(EXIT_FAILURE);
        
        case SIGINT:
            fprintf(stderr, "\nCaught SIGINT : program interrupted, most likely due to Ctrl-C. signal_handler function invoked.\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    // need the PID to run the kill command
    printf("Process PID:%d\n", getpid());
    
    // register the signal handlers
    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);
    
    while(1);
    
    return 0;
}
