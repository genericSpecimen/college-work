#include <stdio.h>

//#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//#include <errno.h> // errno

#include <unistd.h> // getpid()
#include <stdlib.h> // exit()
#include <string.h>

#define MSGQKEY 75

typedef struct Message {
    long mtype;
    char mtext[256];
} Message;

int openQueue(key_t key) {
    // IPC_CREAT : Create the queue if it doesn't already exist in the kernel. 
    int qid = msgget(MSGQKEY, IPC_CREAT|0777);
    if (qid == -1) {
        perror("Error creating and/or accessing message queue");
        exit(1);
    } else {
        printf("=> SENDER: Successfully created and/or accessed message queue: qid = %d\n", qid);
    }    
    return qid;
}

void sendMessage(int qid, Message *msg) {
    int msg_size = sizeof(Message) - sizeof(long);
    
    // IPC_NOWAIT : not specified, then the calling process will suspend (block) until the message can be written. 
    if (msgsnd(qid, msg, msg_size, 0) == -1) {
        perror("Error sending message");
        exit(1);
    } else {
        printf("=> SENDER: Successfully sent a type %d message of size %d bytes.\n", msg->mtype, msg_size);
    }
}

void receiveMessage(int qid, long mtype, Message *msg) {
    int msg_size = sizeof(Message) - sizeof(long);
    
    // IPC_NOWAIT : not specified the calling process blocks until a message arrives in the queue
    int num_bytes_received = msgrcv(qid, msg, msg_size, mtype, 0);
    if (num_bytes_received == -1) {
        perror("Error receiving message");
        exit(1);
    } else {
        printf("=> RECEIVER: Successfully received a type %d message of size %d bytes.\n", mtype, num_bytes_received);
        printf("   Message contents: %s\n", msg->mtext);
    }
}
int main() {
    printf("SENDER\n");
    
    int qid = openQueue(MSGQKEY);
    
    Message msg;
    msg.mtype = 1;
    
    for (int i=0; i<100; i++) {
        snprintf(msg.mtext, sizeof(msg.mtext), "%s %d", "Hello world!", i);
        sendMessage(qid, &msg);
        sleep(1);
    }
    
    
    return 0;
}
