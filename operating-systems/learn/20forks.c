#include <stdio.h>
#include <unistd.h>

int main() {
	if (fork() || fork()) {
		fork();
	}

	/*
	if (fork() && fork()) {
		fork();
	}
	*/
	printf("\n Hello World");
	return 0;
}
