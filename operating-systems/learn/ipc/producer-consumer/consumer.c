#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>

#include <sys/shm.h>
#include <sys/mman.h>

#include <semaphore.h>

#include <signal.h>

volatile sig_atomic_t run = 1;

typedef struct SharedMemory {
    int done;
    int shelf;
} SharedMemory;

SharedMemory *shared_memory;

void signal_handler(int sig_num) {
    // forceful termination: SIGINT or SIGTERM
    
    if (sig_num == SIGTERM || sig_num == SIGINT) {
        fprintf(stderr, "\nCaught SIGTERM or SIGINT.\n");
        run = 0;
        shared_memory->done = 1;
    }
}

int main() {
    struct sigaction saction;
    saction.sa_handler = signal_handler;
    sigemptyset(&saction.sa_mask);
    saction.sa_flags = 0;
    sigaction(SIGINT, &saction, NULL);
    sigaction(SIGTERM, &saction, NULL);
    
    
    // create a shared memory segment
    const char *shared_memory_name = "shared_memory";
    int shm_fd = shm_open(shared_memory_name, O_CREAT|O_RDWR, 0644);
    // truncate the file to a specified length 
    ftruncate(shm_fd, sizeof(SharedMemory));
    // establish a mapping between the address space of this process and a memory object.
    shared_memory = mmap(0, sizeof(SharedMemory), PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0);
    shared_memory->shelf = 0; // intialize to 0 pizzas on the shelf
    shared_memory->done = 0;
    
    // Create and open semaphores
    
    // cook posts (increments) semaphore fill after cooking a pizza
    const char *sema1 = "fill";
    sem_t *fill = sem_open(sema1, O_CREAT, 0644, 0);
    
    // waiter posts semaphore avail after picking up a pizza, intially avail = 3
    const char *sema2 = "avail";
    sem_t *avail = sem_open(sema2, O_CREAT, 0644, 3);
    
    // mutex for mutual exclusion of shelf
    const char *sema3 = "mutex";
    sem_t *mutex = sem_open(sema3, O_CREAT, 0644, 1);
    
    printf("\nWaiter: I have started waiting for pizzas on the shelf.\n");
    int counter = 10;
    while (counter--) {
        // cook waits for an empty spot at the shelf
        sem_wait(fill);
        sleep(rand() % 2 + 1);
        
        // decrement shelf counter after picking up pizza
        sem_wait(mutex);
        shared_memory->shelf--;
        printf("Waiter: picked up a pizza, there are %d pizza now\n", shared_memory->shelf);
        if (shared_memory->done == 1) {
            break;
        }
        sem_post(mutex);
        
        sem_post(avail);
    }
    printf("Waiter: Work done for the day.\n");
    
    sem_close(fill); sem_unlink(sema1);
    sem_close(avail); sem_unlink(sema2);
    sem_close(mutex); sem_unlink(sema3);
    
    munmap(shared_memory, sizeof(SharedMemory));
    close(shm_fd);
    shm_unlink(shared_memory_name);    
    return 0;
}
