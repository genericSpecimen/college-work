#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>


int main() {
	printf("%d, %d, %d\n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
	printf("%d\n", FOPEN_MAX);

	//off_t currpos = lseek()
	
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
		printf("Can't seek!\n");
	} else {
		printf("Can seek!\n");
	}

	char buf1[] = "abcdefghij";
	char buf2[] = "ABCDEFGHIJ";

	int fd = creat("file.hole", S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	if (fd < 0) {
		fprintf(stderr, "creat error\n");
		exit(1);
	}

	if (write(fd, buf1, 10) != 10) {
		fprintf(stderr, "buf1 write error");
	}

	off_t currpos = lseek(fd, 0, SEEK_CUR);
	printf("currpos: %d\n", currpos);

	if (lseek(fd, 16384, SEEK_SET) == -1) {
		fprintf(stderr, "lseek error");
		exit(1);
	}

	currpos = lseek(fd, 0, SEEK_CUR);
	printf("currpos: %d, SEEK_CUR: %d\n", currpos, SEEK_CUR);

	if (write(fd, buf2, 10) != 10) {
		fprintf(stderr, "buf2 write error");
		exit(1);
	}


	currpos = lseek(fd, 0, SEEK_CUR);
	printf("currpos: %d\n", currpos);


	return 0;
}
