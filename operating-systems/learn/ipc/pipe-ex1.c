/*pipe-ex1.c*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static int pipefd1[2],pipefd2[2];
/*Create two pipes*/
char buf[30];

void TELL_WAIT(void){
    if(pipe(pipefd1)<0 || pipe(pipefd2)<0){
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

void TELL_PARENT(void){
    /* send parent a message through pipe, need you to complete*/
    //child writes "c" across the bottom pipe pipefd2 when TELL_PARENT is called.
    //close(pipefd2[0]);
    if (write(pipefd2[1], "c", 2) != 2) {
        perror("TELL_PARENT: write error");
        exit(EXIT_FAILURE);
    }
    
    printf("Child send message to parent!\n");
}

void WAIT_PARENT(void){
    /* read message sent by parent from pipe, need you to complete*/
    //close(pipefd1[1]);
    if (read(pipefd1[0], buf, 2) != 2) {
        perror("WAIT_PARENT: read error");
        exit(EXIT_FAILURE);
    }
    
    printf("Child receive message from parent!\n");
}

void TELL_CHILD(void){
    /* send child a message through pipe, need you to complete*/
    // Parent writes the character "p" across the top pipe pipefd1 when TELL_CHILD is called
    if (write(pipefd1[1], "p", 2) != 2) {
        perror("TELL_CHILD: write error");
        exit(EXIT_FAILURE);
    }
    printf("Parent send message to child!\n");
}

void WAIT_CHILD(void){
    /* read the message sent by child from pipe, need you to complete*/
    if (read(pipefd2[0], buf, 2) != 2) {
        perror("WAIT_CHILD: read error");
        exit(EXIT_FAILURE);
    }
    printf("Parent receive message from child!\n");
}

int main(int argc, char* argv[]){
    TELL_WAIT();
    pid_t pid = fork();
    
    //set a timer, process will end after 1 second.
    alarm(10);
    
    if (pid < 0) {
        perror("fork() error");
        exit(1);
    } else if (pid == 0) {
        // child process
        
        // close unused ends
        close(pipefd1[1]);
        close(pipefd2[0]);
        while(1) {
            sleep(rand() % 2 + 1);
            WAIT_PARENT();
            TELL_PARENT();
        }
    } else {
        // parent process
        
        // close unused ends
        close(pipefd1[0]);
        close(pipefd2[1]);
        while(1){
            sleep(rand() % 2 + 1);
            TELL_CHILD();
            WAIT_CHILD();
        }
    }
    return 0;
}
