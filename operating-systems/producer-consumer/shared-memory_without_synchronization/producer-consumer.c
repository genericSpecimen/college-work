#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 10

typedef struct {
    int data;
} item;

item buffer[BUFFER_SIZE];
int in = 0; // next free position in the buffer
int out = 0; // first full position in the buffer
int count = 0; // number of items currently in the buffer

void printBuffer() {
    printf("buffer: [");
    for (int i=0; i<BUFFER_SIZE; i++) {
        printf("%d,", buffer[i].data);
    }
    printf("]\n");
    printf("in=%d, out=%d, count=%d\n\n", in, out, count);
}

int produce() {
    if (count == BUFFER_SIZE) {
        // failed to produce
        return 0;
    }
    
    item next_produced = {rand() % 100};
    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
    count++;
    
    return 1;
}

int consume() {
    if (count == 0) {
        // failed to consume
        return 0;
    }
    item next_consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    
    return 1;
}

int main() {
    srand(time(NULL));
    printf("Producer Consumer Simulator - Controlled Environment\n");
    printf("What do you want to do?\n");
    printf("1. Produce an item.\n");
    printf("2. Consume an item.\n");
    printf("3. Print current buffer information.\n");
    printf("4. Exit.\n");
    int option;
    
    while (1) {
        printf("=> Enter an option (1-4): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1: { 
                if (produce()) {
                    printf("=> Successfully produced an item.\n");
                } else {
                    printf("=> Failed to produce an item since buffer is full.\n");
                }
                printBuffer();
                break;
            }
            case 2: { 
                if (consume()) {
                    printf("=> Successfully consumed an item.\n");
                } else {
                    printf("=> Failed to consume an item since buffer is empty.\n");
                }
                printBuffer();
                break;
            }
            case 3: printBuffer(); break;
            case 4: return 0;
            default: printf("Invalid option. Please try again.\n");
        };
    }
    return 0;
}
