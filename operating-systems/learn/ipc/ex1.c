#include <stdio.h>
#include <unistd.h>

int main() {
    int a = 5, b = 16;
    printf("Before fork: a=%d, b=%d \n", a, b);
    int pid = fork();
    
    if (pid == 0) {
        a = a + 1;
        b = b + 1;
        printf("In child: a=%d, b=%d\n", a, b);
    } else {
        sleep(1);
        a = a+1;
        b = b+1;
        printf("In parent: a=%d, b=%d\n", a, b);
    }
    
    return 0;
}
