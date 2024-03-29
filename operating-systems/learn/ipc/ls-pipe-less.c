#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefds[2];
    
    if (pipe(pipefds) == -1) {
        perror("pipe() failed");
        exit(EXIT_FAILURE);
    }
    
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork() failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child process
        
        // duplicate stdout with the write end of the pipe
        // so that output of this process in stdout is
        // written to the pipe
        dup2(pipefds[1], STDOUT_FILENO);
        
        // close unused read end
        close(pipefds[0]);
        
        execlp("ls", "ls", NULL);
        
        exit(EXIT_SUCCESS);
        
    } else {
        // parent process
        
        // duplicate stdin with the read end of the pipe
        dup2(pipefds[0], STDIN_FILENO);
        
        // close unused write end
        close(pipefds[1]);
        
        execlp("less", "less", NULL);
        
        exit(EXIT_SUCCESS);
    }
    
    return 0;
}
