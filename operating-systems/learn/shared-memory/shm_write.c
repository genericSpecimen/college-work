#include "producer_consumer.h"

int main() {
    int shmid = open_shm(SHMKEY, SHMSIZE);
    
    void * addr = attach_shm(shmid);
    
    printf("Writing data to shared memory segment...\n");
    Item * buffer = (Item *) addr;
    
    for (int i=0; i<BUFFER_SIZE; i++) {
        buffer[i].data = 1234 + i;
    }
    
    detach_shm(addr);
    
    return 0;
}
