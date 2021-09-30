#include <stdio.h>

//#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

//#include <errno.h> // errno

#include <unistd.h> // getpid()
#include <stdlib.h> // exit()
#include <string.h>

#define SEMKEY 75

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int open_sem(int semkey, int num_sems) {
    int semid = semget(semkey, num_sems, IPC_CREAT|0660);
    if (semid == -1) {
        perror("Error creating / getting a semaphore set");
        exit(1);
    } else {
        printf("=> Successfully created / got a semaphore set with id: %d\n", semid);
    }
    
    return semid;
}

void init_sem(int semid, int semnum, int value) {
    union semun semopts;
    semopts.val = value;
    if (semctl(semid, semnum, SETVAL, semopts) == -1) {
        perror("Error setting semaphore value");
        exit(1);
    } else {
        printf("=> Successfully set semnum %d with value: %d\n", semnum, semopts.val);
    }
}

int get_sem_val(int semid, int semnum) {
    int semnum_val = semctl(semid, semnum, GETVAL, 0);
    if (semnum_val == -1) {
        perror("Error getting semaphore value");
        exit(1);
    } else {
        //printf("=> Value of semnum %d = %d\n", semnum, semnum_val);
    }
    return semnum_val;
}

int main() {
    int num_sems = 1;
    int semid = open_sem(SEMKEY, num_sems);
    
    int semnum = 0, value = 1;
    init_sem(semid, semnum, value);
    
    int semnum_val = get_sem_val(semid, semnum);
    printf("=> Value of semnum %d = %d\n", semnum, semnum_val);
    
    // obtain one unit of resources from the only semaphore in our set (0th member)
    struct sembuf sem_lock = { semnum, -1, 0 };
    
    // The third argument (nsops) says that we are only performing one (1) operation (there is only one sembuf structure in our array of operations). 
    if (semop(semid, &sem_lock, 1) == -1) {
        perror("Error obtaining lock using semop");
        exit(1);
    } else {
        printf("=> Successfully obtained lock.\n");
    }
    
    semnum_val = get_sem_val(semid, semnum);
    printf("=> Value of semnum %d = %d\n", semnum, semnum_val);
    
    struct sembuf sem_unlock = { semnum, 1, 0 };
    if (semop(semid, &sem_unlock, 1) == -1) {
        perror("Error releasing lock using semop");
        exit(1);
    } else {
        printf("=> Successfully released lock.\n");
    }
    
    semnum_val = get_sem_val(semid, semnum);
    printf("=> Value of semnum %d = %d\n", semnum, semnum_val);
    
    return 0;
}
