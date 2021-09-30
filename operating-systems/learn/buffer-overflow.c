#include <stdio.h>
#include <string.h>

int main() {
    char A[8] = "";
    unsigned short B = 1979;
    
    printf("%s\n", A);
    printf("%d\n", B);
    
    strcpy_s(A, "excessive");
    printf("%s\n", A);
    printf("%d\n", B);
    
}
