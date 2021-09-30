#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    fgets(buffer, 100, stdin);
    printf("%d, %d, %s\n", sizeof(buffer), strlen(buffer), buffer);
    
}
