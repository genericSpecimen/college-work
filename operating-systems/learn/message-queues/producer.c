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
        perror("=> PRODUCER: Error creating and/or accessing message queue");
        exit(1);
    } else {
        printf("=> PRODUCER: Successfully created and/or accessed message queue: qid = %d\n", qid);
    }    
    return qid;
}

void sendMessage(int qid, Message *msg) {
    int msg_size = sizeof(Message) - sizeof(long);
    
    // IPC_NOWAIT : not specified, then the calling process will suspend (block) until the message can be written. 
    if (msgsnd(qid, msg, msg_size, 0) == -1) {
        perror("=> PRODUCER: Error sending message");
        exit(1);
    } else {
        printf("\n=> PRODUCER: Successfully sent a type %d message containing an item of size %d bytes.\n", msg->mtype, msg_size);
    }
}


int main() {    
    int qid = openQueue(MSGQKEY);
    
    Message msg;
    
    // send messages of type 1
    msg.mtype = 1;
    
    //printf("%d, %d, %d\n", sizeof(Message), sizeof(Item), sizeof(msg.mtype));
    
    for (int i=0; i<5; i++) {        
        // load some arbitrary data into item
        msg.item.data1 = i;
        msg.item.data2 = i+300;
        
        // send this message containing the item
        sendMessage(qid, &msg);
        
        sleep(rand()%2+1);
    }
    
    
    return 0;
}
