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


void ls(const char* directory){
	DIR* fileDesc;
	struct dirent* direntPointer;
	struct stat statBuffer;


	// If the directory argument is NULL then we want to show the current working directory
	if(directory == NULL){
		fileDesc = opendir(".");
		
	}
	// Else we will use the specified working directory
	else{
		fileDesc = opendir(directory);
	}

	// If the fileDescriptor is nULL then there is problem in opening the file
	if(fileDesc == NULL){
		fprintf(stderr, "Could not open the file...\n");
		return ;
	}

	// Using a Dirent Pointer that will point to the head of the first file of the opened directory
	direntPointer = readdir(fileDesc);

	// Iterate until the current pointer is NULL .i.e readdir --> returns NULL when there no next file
	while(direntPointer != NULL){

		// Fill the statBuffer with the current file name
		stat(direntPointer->d_name, &statBuffer);

		// Print the details of the file
		printf("%s \t %ld BYTES\n", direntPointer->d_name, statBuffer.st_size);
		
		// Read the the next file
		direntPointer = readdir(fileDesc);
	}

	printf("\n");

	// CLose the directory
	closedir(fileDesc);
	return ;
}


