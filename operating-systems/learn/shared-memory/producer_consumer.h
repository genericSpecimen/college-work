#ifndef PRODUCER_CONSUMER_H_
#define PRODUCER_CONSUMER_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // exit()
#include <string.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

//#include <errno.h> // errno

#define BUFFER_SIZE 10

#define SHMKEY 75
#define SHMSIZE sizeof(ItemsBuffer)

#define SEMKEY 75

// we will use a set of three semaphores
#define NUM_SEMS 3
// semaphore numbers in the semaphore set
#define SEM_MUTEX 0
#define SEM_EMPTY 1
#define SEM_FULL 2

typedef struct {
    int data;
} Item;

typedef struct {
    // first free index and first used index
    int in;
    int out;
    
    // the actual items buffer
    Item items[BUFFER_SIZE];
} ItemsBuffer ;

// ------------------------- SHARED MEMORY WRAPPER FUNCTIONS ---------------------------
int open_shm(int shmkey, int shmsize) {
    int shmid = shmget(shmkey, shmsize, IPC_CREAT|0777);
    if (shmid == -1) {
        perror("Error creating / getting a shared memory segment");
        exit(1);
    } else {
        printf("=> Successfully created / got a shared memory segment with id: %d\n", shmid);
    }
    return shmid;
}

void * attach_shm(int shmid) {
    // shmat returns the segment's start address if Successful
    void * addr = shmat(shmid, NULL, 0);
    if ( addr == (void*)-1) {
        perror("Error attaching shared memory segment to the address space of this process");
        exit(1);
    } else {
        printf("=> Successfully attached shared memory segment to the address space of this process.\n");
    }
    return addr;
}

void detach_shm(void *addr) {
    // detach the shared memory segment located at addr
    if (shmdt(addr) == -1) {
        perror("Error detaching the shared memory segment from the address space of this process");
        exit(1);
    } else {
        printf("=> Successfully detached shared memory segment from the address space of this process.\n");
    }    
}

void remove_shm(int shmid) {
    //  Remove the shared memory identifier specified by shmid from the system and destroy the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Error removing shared memory identifier from the system");
        exit(1);
    } else {
        printf("=> Successfully removed shared memory identifier from the system.\n");
    }    
}
// -------------------------------------------------------------------------------------


// ------------------------- SEMAPHORE WRAPPER FUNCTIONS ---------------------------
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
        //printf("=> Successfully set semnum %d with value: %d\n", semnum, semopts.val);
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

void print_sem_vals(int semid, int num_sems) {
    for (int semnum=0; semnum<num_sems; semnum++) {
        int semnum_val = get_sem_val(semid, semnum);
        printf("=> Value of semnum %d = %d\n", semnum, semnum_val);
    }  
}

void sem_wait(int semid, int semnum) {
    struct sembuf sem_semnum_wait = {semnum, -1, 0};
    if (semop(semid, &sem_semnum_wait, 1) == -1) {
        perror("Error performing sem_semnum_wait using semop");
        fprintf(stderr, "Error on semnum = %d\n", semnum);
        exit(1);
    } else {
        //printf("=> Successfully performed sem_semnum_wait, semnum = %d.\n", semnum);
    }    
}

void sem_signal(int semid, int semnum) {
    struct sembuf sem_semnum_signal = { semnum, 1, 0 };
    if (semop(semid, &sem_semnum_signal, 1) == -1) {
        perror("Error performing sem_semnum_signal using semop");
        fprintf(stderr, "Error on semnum = %d\n", semnum);
        exit(1);
    } else {
        //printf("=> Successfully performed sem_semnum_signal, semnum = %d.\n", semnum);
    }  
}

void remove_sem(int semid) {
    //  Remove the semaphore identifier specified by semid from the system
    if (semctl(semid, SEM_MUTEX, IPC_RMID, NULL) == -1) {
        perror("Error removing semaphore identifier from the system");
        exit(1);
    } else {
        printf("=> Successfully removed semaphore identifier from the system.\n");
    }    
}

// ---------------------------------------------------------------------------------


#endif
