#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long long int sum = 0;

struct sum_range {
    long long int lower, upper;
};

void* runner(void *param) {
    struct sum_range *sr = (struct sum_range*)(param);
    printf("Summing from %lld to %lld\n", sr->lower, sr->upper);
    for (long long int i=sr->lower; i <= sr->upper; i++) {
        sum += i;
    }
    
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    const int NUM_THREADS = 2;
    pthread_t workers[NUM_THREADS];
    pthread_attr_t attrs[NUM_THREADS];
    
    struct sum_range sr[NUM_THREADS];
    
    long long int lower = 1;
    long long int upper = atoi(argv[1]) / NUM_THREADS;
    
    for (int i=0; i<NUM_THREADS; i++) {
        sr[i].lower = lower;
        sr[i].upper = upper;
        
        lower = upper + 1;
        upper = upper * NUM_THREADS;
    }
    
    for (int i=0; i<NUM_THREADS; i++) {
        pthread_attr_init(&attrs[i]);
        pthread_create(&workers[i], &attrs[i], runner, &sr[i]);
    }
    
    for (int i=0; i<NUM_THREADS; i++) {
        pthread_join(workers[i], NULL);
    }
    
    printf("sum = %lld\n", sum);
}
