#include <stdio.h>
#include <limits.h> // PATH_MAX
#include <unistd.h> // getcwd()

int main(int argc,char *argv[]) {
    char cwd[PATH_MAX+1];
    if(getcwd(cwd,PATH_MAX+1) != NULL) {
         printf("Current Working Dir: %s\n",cwd);
    }
    else {
        printf("Error Occured!\n");
    }
    return 0;
}
