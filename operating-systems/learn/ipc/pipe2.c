#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 25

int main() {
    char buffer[BUFFER_SIZE];
    
    int p[2];
    if (pipe(p) == 0) {
        printf("Successfully created a pipe.\n");
    } else {
        printf("Failed to create a pipe.\n");
        exit(1);
    }
    
    //sleep(10);
    
    int pid = fork();
    if (pid == -1) {
        printf("fork() failed.");
        exit(1);
    } else if (pid == 0) {
        // child process - write to pipe
        close(p[0]); // close unused read end
        int nbytes = write(p[1], "Hello World!", 13);
        printf("Child process finished writing %d bytes to pipe.\n", nbytes);
        
        close(p[1]); // finished writing to pipe        
    } else {
        wait(NULL);
        printf("Child terminated.\n");

        // parent process - read from pipe
        close(p[1]); // close unused write end
        
        int nbytes = read(p[0], buffer, BUFFER_SIZE);
        printf("Parent process read %d bytes.\n", nbytes);
        printf("Content: %s\n", buffer);
        
        close(p[0]); // finished reading from pipe        
    }
    
    return 0;
}
