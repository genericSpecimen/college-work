#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int globalVariable = 0;

int main() {

    for (int i=0;i<3;i++) {
        pid_t pID = fork();
        if (pID == 0) { //child
            globalVariable++;
        } else { // parent
            //++globalVariable;
        }
    }
    
    printf("count : %d\n", globalVariable);
}           
