#include "producer_consumer.h"

int main() {
    int shmid = open_shm(SHMKEY, SHMSIZE);
    
    void * addr = attach_shm(shmid);
    
    printf("Reading shared data...\n");

    Item * buffer = (Item *) addr;
    printf("BUFFER: [ ");
    for (int i=0; i<BUFFER_SIZE; i++) {
        printf("%d, ", buffer[i].data);
    }
    printf("]\n");
    
    detach_shm(addr);
    remove_shm(shmid);
    
    return 0;
}
