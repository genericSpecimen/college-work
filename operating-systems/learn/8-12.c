#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>


int buffer[4096];

void f() {}
void g() {}

void theend() {
    for(int i=0; i<4096; i++) {
        if (buffer[i]) {
            printf("buf[%d] = %d\n", i, buffer[i]);
        }
    }
    exit(0);
}

int main() {
    signal(SIGINT, theend);
    intptr_t endof = theend;
    int offset = (int) main;
    int text = (endof - offset + sizeof(int) - 1) / sizeof(int);
    int scale = 0xffff;
    
    printf("offset %d, endof %lld, text %d\n", offset, endof, text);
    
    int eff = (int) f;
    int gee = (int) g;
    
    printf("f %d, g %d, fdiff %d, gdiff %d\n",
           eff, gee, eff-offset, gee-offset);
    
    profil(buffer, sizeof(int)*text, offset, scale);
    
    for(;;) {
        f();
        g();
    }
    return 0;
}
