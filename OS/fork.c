#include<stdio.h>
#include<unistd.h>

// Create a child process using fork() system call
// Obtain a PID, and PPID of the child by using getpid() & getppid() system call

void main() {
	int forkStatus = fork();
	if(forkStatus == 0) {
		printf("\nHello child!\n");
		printf("getpid returns : %d\n", getpid());
	} else {
		printf("\ngetppid returns : %d", getppid());
		//printf("HELLO\n");
	}
}
