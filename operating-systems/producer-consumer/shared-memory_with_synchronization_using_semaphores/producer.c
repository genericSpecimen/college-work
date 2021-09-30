#include "producer_consumer.h"

int main() {
    // open and attach shared memory
    int shmid = open_shm(SHMKEY, SHMSIZE);
    
    void * addr = attach_shm(shmid);    
    ItemsBuffer * buffer = (ItemsBuffer *) addr;
    
    // initialize in and out
    buffer->in = 0; buffer->out = 0;
    
    // get a semaphore set and initialize semaphore values
    int semid = open_sem(SEMKEY, NUM_SEMS);
    
    init_sem(semid, SEM_MUTEX, 1);
    init_sem(semid, SEM_EMPTY, BUFFER_SIZE);
    init_sem(semid, SEM_FULL, 0);
    
    //print_sem_vals(semid, NUM_SEMS);
    
    // produce items 20 times
    for (int i=0; i<20; i++) {
        // wait(empty)
        sem_wait(semid, SEM_EMPTY);
        //print_sem_vals(semid, NUM_SEMS);
        
        // wait(mutex)
        sem_wait(semid, SEM_MUTEX);
        //print_sem_vals(semid, NUM_SEMS);
        
        Item next_produced = {rand()};
        printf("\nPRODUCER: Adding next_produced with data = %d to buffer....\n", next_produced.data);
        buffer->items[buffer->in] = next_produced;
        buffer->in = (buffer->in + 1) % BUFFER_SIZE;
        
        // signal(mutex)
        sem_signal(semid, SEM_MUTEX);
        //print_sem_vals(semid, NUM_SEMS);
        
        // signal(full)
        sem_signal(semid, SEM_FULL);
        //print_sem_vals(semid, NUM_SEMS);
        sleep(rand() % 3 + 1);
    }
    
    detach_shm(addr);
    
    return 0;
}
