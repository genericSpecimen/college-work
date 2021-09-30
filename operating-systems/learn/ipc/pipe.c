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
    
    switch (fork()) {
        case -1 : printf("fork() failed."); break;
        case 0 : {
            sleep(1);
            // child process - read from pipe
            close(p[1]); // close unused write end
            
            int nbytes = read(p[0], buffer, BUFFER_SIZE);
            printf("Child process read %d bytes.\n", nbytes);
            printf("Content: %s\n", buffer);
            
            close(p[0]); // finished reading from pipe
        }
        default : {
            // parent process - write to pipe
            close(p[0]); // close unused read end
            
            write(p[1], "Hello World!", 13);
            printf("Parent process finished writing to pipe.\n");
            
            close(p[1]); // finished writing to pipe
            sleep(2);
        }
    }
    
    return 0;
}
