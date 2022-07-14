#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
#define MAXSIZE 10
#define STDOUT 1


void cat(const char* filepath){
	// File Descriptor to specify the file
	int fileDescriptor;
	char buffer[MAXSIZE];
	fileDescriptor = open(filepath, O_RDONLY);

	if(fileDescriptor < 3){
		printf("File Doesn't exist... Or Path Name is incorrect\n");
		return ;
	}
	// While we can read a positive amount of buffer bits we will print them
	while(read(fileDescriptor, buffer, MAXSIZE) > 0){
		write(STDOUT, buffer, MAXSIZE);
	}

	printf("\n");

	return ;
}
