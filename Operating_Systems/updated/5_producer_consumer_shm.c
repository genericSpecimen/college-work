#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

// compile with the -lrt flag
// cc -lrt 5.c

const int SIZE = 4096;
const char* name = "OS";
const char* message_0 = "Hello";
const char* message_1 = "World!";

void produce() {
    int shm_fd; //shared mem file descriptor
    void* ptr; //pointer to shared mem object

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0);
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);
}

void consume() {
    int shm_fd; //shared mem file descriptor
    void* ptr; //pointer to shared mem object
    shm_fd = shm_open(name, O_RDONLY, 0666);
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    printf("%s\n", (char*)ptr);
    shm_unlink(name);
}

int main() {
    produce();
    consume();
}