#include <stdio.h>

//#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//#include <errno.h> // errno

#include <unistd.h> // getpid()
#include <stdlib.h> // exit()
#include <string.h>

#define MSGQKEY 75

typedef struct {
    int data1, data2;
} Item;

typedef struct {
    long mtype;
    Item item;
} Message;

int openQueue(key_t key) {
    // IPC_CREAT : Create the queue if it doesn't already exist in the kernel. 
    int qid = msgget(MSGQKEY, IPC_CREAT|0777);
    if (qid == -1) {
        perror("=> CONSUMER: Error creating and/or accessing message queue");
        exit(1);
    } else {
        printf("=> CONSUMER: Successfully created and/or accessed message queue: qid = %d\n", qid);
    }    
    return qid;
}

void receiveMessage(int qid, long mtype, Message *msg) {
    int msg_size = sizeof(Message) - sizeof(long);
    
    // IPC_NOWAIT : not specified the calling process blocks until a message arrives in the queue
    int num_bytes_received = msgrcv(qid, msg, msg_size, mtype, 0);
    if (num_bytes_received == -1) {
        perror("Error receiving message");
        exit(1);
    } else {
        printf("\n=> CONSUMER: Successfully received a type %d message of size %d bytes\
, Item contents: data1 = %d, data2 = %d\n\n", mtype, num_bytes_received, msg->item.data1, msg->item.data2);
    }
}

int main() {
    int qid = openQueue(MSGQKEY);
    
    Message msg;
    
    // receive messages of type 1
    msg.mtype = 1;
    
    for (int i=0; i<5; i++) {
        // receive this message into msg
        receiveMessage(qid, msg.mtype, &msg);
        
        sleep(rand()%2+1);
    }    
    return 0;
}
