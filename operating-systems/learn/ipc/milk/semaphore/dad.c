#include <stdio.h>
#include <string.h> // strlen
#include <stdlib.h> // rand
#include <unistd.h>

// open, close
#include <sys/stat.h>
#include <fcntl.h>

#include <semaphore.h>

int main() {
    const char *str = "milk\n";

    // create 0-1 semaphore named mutex
    int sem_val = 1;
    sem_t *mutex = sem_open("mutex", O_CREAT, 0666, sem_val);
    
    printf("Dad comes home.\n");
    //sleep(rand()%2+1);
    // wait on semaphore mutex and then decrease by 1, i.e. lock the semaphore
    sem_wait(mutex);
    
    printf("Dad checks the fridge.\n");
    
    int fd = open("fridge", O_CREAT|O_RDWR|O_APPEND, 0644);
    
    if (lseek(fd, 0, SEEK_END) == 0) {
        printf("Dad found no milk in the fridge; he goes to buy milk...\n");
        //sleep(rand() % 2 + 1);
        
        write (fd, str, strlen(str));
        printf("Dad puts milk in fridge and leaves.\n");
        
        if (lseek(fd, 0, SEEK_END) > strlen(str)) {
            printf("Dad: What a waste of food! The fridge can't hold so much milk!\n");
        }
    } else {
        printf("Dad closes the fridge and leaves.\n");
    }
    
    close(fd);
    
    // unlock the semaphore "mutex"
    sem_post(mutex);
    
    // close and remove the named semaphore "mutex"
    sem_close(mutex);
    sem_unlink("mutex");
    
    return 0;
}
