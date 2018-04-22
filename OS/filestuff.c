#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

extern int errno;

int fd;

void main() {

	char *filename = "sample.txt";

	// creat(char *filename, int flags)
	// The S_* flags are provided by sys/stat.h
	fd = creat(filename, S_IREAD | S_IWRITE | S_IEXEC | S_IWGRP | S_IXGRP);

	if (fd == -1)
		printf("\nError : fd is -1");
	else
		printf("\nFile Descriptor for %s : %d", filename, fd);

	fd = open(filename, O_CREAT | O_RDONLY);

	if (fd == -1)
		printf("\nError while opening %s", filename);

	fd = close(fd);

	if (fd == 0)
		printf("\nSuccessfully closed file %s", filename);
	else
		printf("\nError while closing file %s", filename);

	char *char_buffer = (char *) calloc(100, sizeof(char));
	char *some_file = "somefile.txt";

	fd = open(some_file, O_RDONLY);

	int size = read(fd, char_buffer, 100);
	char_buffer[size] = '\0';

	printf("\n\nContents of %s\n", some_file);
	printf("%s", char_buffer);

	fd = open("writesample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd < 0) {
		printf("Error while creating writesample.txt\nAborting");
		exit(1);
	}

	printf("Enter the contents of this file");
	char *write_buffer = (char *) calloc(100, sizeof(char));
	scanf("%s", write_buffer);

	int length = strlen(write_buffer);

	write_buffer[length] = '\0';

	size = write(fd, write_buffer, length);

}
