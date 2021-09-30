#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>

#include <sys/shm.h>
#include <sys/mman.h>

#include <semaphore.h>

int main() {
    // create a shared memory segment
    const char *shared_memory_name = "shared_memory";
    int shm_fd = shm_open(shared_memory_name, O_CREAT|O_RDWR, 0644);
    // truncate the file to a specified length 
    ftruncate(shm_fd, sizeof(int));
    // establish a mapping between the address space of this process and a memory object.
    int *shelf = mmap(0, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0);
    *shelf = 0; // intialize to 0 pizzas on the shelf
    
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
    
    printf("\nCook: I have started cooking pizzas.\n");
    int counter = 6;
    while (counter--) {
        // cook waits for an empty spot at the shelf
        sem_wait(avail);
        sleep(rand() % 2 + 1);
        
        // increment shelf counter after cooking is finished
        sem_wait(mutex);
        (*shelf)++;
        printf("Cook: cooked a pizza, there are %d pizza now\n", *shelf);
        sem_post(mutex);
        
        sem_post(fill);
    }
    printf("Cook: Work done for the day. I cooked up 6 pizzas. %d are left.\n", *shelf);
    
    sem_close(fill); sem_unlink(sema1);
    sem_close(avail); sem_unlink(sema2);
    sem_close(mutex); sem_unlink(sema3);
    
    return 0;
}
