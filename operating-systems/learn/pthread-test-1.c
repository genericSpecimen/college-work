#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long long int sum = 0;

void* runner(void *param) {
    long long int upper = atoi(param);
    printf("Summing from %lld to %lld\n", 1, upper);
    for (long long int i=1; i<=upper; i++) {
        sum += i;
    }
    
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t worker;
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);
    pthread_create(&worker, &attr, runner, argv[1]);
    
    pthread_join(worker, NULL);
    
    printf("sum = %lld\n", sum);
}
