#include "producer_consumer.h"

int main() {
    // open and attach shared memory
    int shmid = open_shm(SHMKEY, SHMSIZE);
    
    void * addr = attach_shm(shmid);    
    ItemsBuffer * buffer = (ItemsBuffer *) addr;
    
    int semid = open_sem(SEMKEY, NUM_SEMS);
    
    //print_sem_vals(semid, NUM_SEMS);
    
    // consume items 20 times
    for (int i=0; i<20; i++) {
        // wait(full)
        sem_wait(semid, SEM_FULL);
        //print_sem_vals(semid, NUM_SEMS);
        
        // wait(mutex)
        sem_wait(semid, SEM_MUTEX);
        //print_sem_vals(semid, NUM_SEMS);
        
        printf("\nCONSUMER: Removing and consuming next_consumed from buffer....\n");
        Item next_consumed = buffer->items[buffer->out];
        buffer->out = (buffer->out + 1) % BUFFER_SIZE;
        printf("CONSUMER: Consumed item with data: %d\n", next_consumed.data);

        // signal(mutex)
        sem_signal(semid, SEM_MUTEX);
        //print_sem_vals(semid, NUM_SEMS);
        
        // signal(empty)
        sem_signal(semid, SEM_EMPTY);
        //print_sem_vals(semid, NUM_SEMS);
        
        sleep(rand() % 3 + 1);
    }
    
    // perform cleanup actions
    detach_shm(addr);
    remove_shm(shmid);
    remove_sem(semid);
    
    return 0;
}
