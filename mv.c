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


void mv(const char* filepath, const char* targetDirectory){
	if(rename(filepath, targetDirectory) != 0){
		printf("Cannot Move the file\n");
		return ;
	};
	printf("Succuessfully Moved the File...\n");
}
