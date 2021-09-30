#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h> // creat, open
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h> // close, lseek, read, write


#define MAX_FILENAME_LENGTH 255
#define BUFFER_SIZE 255

// owner - read, write permission
// group - read permission
// other - read permission
#define FILE_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int file_fd = -1;

void createFile() {
    printf("Enter file name to be created: ");
    char filename[MAX_FILENAME_LENGTH];
    scanf("%s", &filename);
    
    int fd = creat(filename, FILE_MODE);
    if (fd < 0) {
        perror("creat error");
        exit(1);
    } else {
        file_fd = fd;
        printf("=> Successfully created file: '%s', and opened file descriptor %d (write-only)\n", filename, fd);
    }
}

void openFile() {
    printf("Enter file name to be opened (or to be created if it doesn't exist): ");
    char filename[MAX_FILENAME_LENGTH];
    scanf("%s", &filename);
    
    int fd = open(filename, O_RDWR | O_CREAT | O_APPEND, FILE_MODE);
    if (fd < 0) {
        perror("open error");
        exit(1);
    } else {
        file_fd = fd;
        printf("=> Successfully opened / created file: '%s', and opened file descriptor %d (read/write)\n", filename, fd);
    }
}

void closeFile() {
    if (file_fd == -1) {
        fprintf(stderr, "Error: no file is open!\n");
        return;
    }
    
    if (close(file_fd) == -1) {
        perror("close error");
    } else {
        file_fd = -1;
        printf("=> Successfully closed the open file.\n");
    }
}

void lseekFile() {
    if (file_fd == -1) {
        fprintf(stderr, "Error: no file is open!\n");
        return;
    }
    
    int whence;
    printf("SEEK_SET: %d, SEEK_CUR: %d, SEEK_END: %d\n", SEEK_SET, SEEK_CUR, SEEK_END);
    printf("Enter position from where to start (whence): ");
    scanf("%d", &whence);
    
    int offset = 0;
    printf("Enter byte offset: ");
    scanf("%d", &offset);
    
    //printf("whence = %d, offset = %d\n", whence, offset);
    
    off_t currpos = lseek(file_fd, offset, whence);
    if (currpos == -1) {
        perror("lseek error");
    } else {
        printf("=> Successfully performed lseek, currpos = %d\n", currpos);
    }
    
}

void readFromFile() {
    if (file_fd == -1) {
        fprintf(stderr, "Error: no file is open!\n");
        return;
    }
    
    char buffer[BUFFER_SIZE];
    
    int random_access = 0;
    printf("Do you want to perform random access? (1/0): ");
    scanf("%d", &random_access);
    if (random_access == 1) {
        lseekFile();
    }
    
    off_t currpos = lseek(file_fd, 0, SEEK_CUR);
    printf("Reading from currpos = %d\n", currpos);

    int bytes_read = read(file_fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("read error");
        exit(1);
    } else {
        printf("Read the following first %d bytes from specified file offset:\n\n", BUFFER_SIZE);
        printf("%.*s\n", bytes_read, buffer);
    }
}

static inline void clearInputBuffer() {
    char c = 0;
    // Loop over input buffer and consume chars until buffer is empty
    while ((c = getchar()) != '\n' && c != EOF);
}

void writeToFile() {
    if (file_fd == -1) {
        fprintf(stderr, "Error: no file is open!\n");
        return;
    }
    
    char buffer[BUFFER_SIZE];
    printf("Enter data to write to file: ");
    clearInputBuffer();
    fgets(buffer, BUFFER_SIZE, stdin);
    
    printf("Writing data to file...\n");
    
    if (write(file_fd, buffer, strlen(buffer)) == -1) {
        perror("write error");
        exit(1);
    } else {
        printf("=> Successfully wrote to file.\n");
    }
}

int main() {
    printf("File Handling Procedures\n");
    printf("What do you want to do?\n");
    printf("1. Create a new file (overwrite if it exists).\n");
    printf("2. Open a file (open in append mode).\n");
    printf("3. Read from the opened file.\n");
    printf("4. Write to the opened file.\n");
    printf("5. Perform lseek operation on the opened file.\n");
    printf("6. Close the opened file.\n");
    printf("7. Exit.\n");
    int option;
    
    while (1) {
        printf("\n=> Enter an option (1-7): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1: createFile(); break;
            case 2: openFile(); break;
            case 3: readFromFile(); break;
            case 4: writeToFile(); break;
            case 5: lseekFile(); break;
            case 6: closeFile(); break;
            case 7: printf("Exiting...\n"); exit(0); break;
            default: printf("Invalid option. Please try again.\n");
        };
    }
    return 0;
}
