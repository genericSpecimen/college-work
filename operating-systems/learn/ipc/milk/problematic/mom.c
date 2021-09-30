#include <stdio.h>
#include <string.h> // strlen
#include <unistd.h>

#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *str = "milk\n";
    
    printf("Mom comes home.\n");
    printf("Mom checks the fridge.\n");
    
    int fd = open("fridge", O_CREAT|O_RDWR|O_APPEND, 0644);
    
    if (lseek(fd, 0, SEEK_END) == 0) {
        printf("Mom found no milk in the fridge; she goes to buy milk...\n");
        sleep(2);
        
        write (fd, str, strlen(str));
        printf("Mom puts milk in fridge and leaves.\n");
        
        if (lseek(fd, 0, SEEK_END) > strlen(str)) {
            printf("Mom: What a waste of food! The fridge can't hold so much milk!\n");
        }
    } else {
        printf("Mom closes the fridge and leaves.\n");
    }
    
    close(fd);
    
    return 0;
}
