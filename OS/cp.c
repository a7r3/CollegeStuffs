#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#define BUFF_SIZE 1024

// argc - Argument Count
// argv - The Array of Arguments
//       ./a.out arg1 arg2
// argv    [0]   [1]   [2]
int main(int argc, char* argv[]) {
	// srcFD - File Descriptor of Source File
	// destFD - File Descriptor of Destination File
	// nbread - Holds the reading status of the Source File
	//        - Meaning: Number of Bytes READ
	// nbwrite - Holds the write status of the destination File
	//         - Meaning: Number of Bytes WRITTEN
	int srcFD, destFD, nbread, nbwrite;
	// The buffer in which the contents of the file would be stored
	// Read from Source -> Write into buffer -> Write into Destination
	char *buff[BUFF_SIZE];

	// If the number of arguments are not 3
	// OR
	// The First argument is '--help'
	if(argc != 3 || argv[1] == "--help") {
		// Show the usage to the user
		printf("\nUsage: copy source_file destination_file");
		exit(EXIT_FAILURE);
	}

	// Try opening the source file, with read-only permissions
	srcFD = open(argv[1], O_RDONLY);
	// If there was an error while opening the file
	if(srcFD == -1)	{
		printf("\nAn Error occured while opening file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Try opening the destination file
	// O_WRONLY - Open for Writing Only
	// O_CREAT  - File is created if doesn't exists
	// O_TRUNC  - Truncates the length of the file to 0
	// S_I* defines the permissions (S - STAT | I - INODE), if the file is newly created
	// S_IRUSR - Read USeR
	// S_IWUSR - Write USeR
	// S_IRGRP - Read GRouP
	// S_IWGRP - Write GRouP
	// S_IROTH - Read OTHers
	// S_IWOTH - Write OTHers
	// The words have been capitalized for a purpose :P
	// IMP NOTE: If we have to provide multiple permissions at a time, then take an Logical OR of it
	destFD = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(destFD == -1) {
		printf("\nAn Error occured while opening file %s", argv[2]);
                exit(EXIT_FAILURE);
	}

	// While the read takes place properly
	// read() copies the content of the specified size (BUFF_SIZE in our case)
	// And writes it to the buffer provided as the second argument
	// From the file descriptor specified as the first argument
	// Return Type - Number of Bytes READ from the file
	//  That explains the name 'nbread'
	while((nbread = read(srcFD, buff, BUFF_SIZE)) > 0) {
		// write() writes the content of the specified size (BUFF_SIZE in our case)
		// with the data from the buffer provided as the second argument
		// to the file descriptor specified as the first argument

		// If the same number of read bytes were not written to the destination
 		if(write(destFD, buff, nbread) != nbread) {
			// Mayday Mayday
			printf("\nError while writing data to %s", argv[2]);
		}
	}

	// If read didn't take place successfully (the while loop above wouldn't have been executed)
	if(nbread == -1)
		printf("\nError while reading data from %s\n", argv[1]);

	// Attempt to close the File Descriptors
	// If they error, it returns -1
	if(close(srcFD) == -1)
		printf("\nError while closing source file %s\n", argv[1]);
	if(close(destFD) == -1)
		printf("\nError while closing destination file %s", argv[2]);
	// Peace
	exit(EXIT_SUCCESS);
}
