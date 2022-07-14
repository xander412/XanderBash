#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include "extensions.h"
#include "ls.h"
#include "mv.h"
#include "cat.h"
#include "stringLinkedList.h"

void main(){
	char buffer[128];
	struct stringLinkedList sList;
	struct stringNode* tempHead;
	

	while(1){
		printf(">>> ");
		scanf("%[^\n]", buffer);
	//	printf("%s", buffer);
		getchar();

		// If the character is "q" then quit
		if(strcmp(buffer, "q") == 0)
			break;

		// Convert the input string into a string list
		sList = stringTokenizer(buffer, " ");
//		printf("%s", head->data);		
//		displayStringLinkedList(head);
		
		// Check the first node of the linked list is equal to any of the commands that is written in the conditions
		// ---> Check whether the number of arguemnts is enough or not
		// 		-TRUE  ---> execute the command
		// 		-FALSE ---> Else jump to next iteration

		if(strcmp(sList.head->data, "ls") == 0){
		
			if(sList.length == 2){
				ls(sList.head->next->data);
				continue;
			}

			else if(sList.length > 2){
				printf("Too Many Arguments for ls\n");
				continue;
			}
			ls(".");
		}
		else if(strcmp(sList.head->data, "mv") == 0){
			
			if(sList.length == 3){
				mv(sList.head->next->data, sList.head->next->next->data);
			}
			
			else{
				printf("Wrong number of arguments...\n");
			}
		}
		else if(strcmp(sList.head->data, "cat") == 0){
			if(sList.length == 1){
				printf("TOO few arguments...\n");
				break;
			}
			tempHead = sList.head;
			while(tempHead != NULL){
				cat(tempHead->data);
				tempHead = tempHead->next;
			}
		}
		else if(strcmp(sList.head->data, "mkdir") == 0){
			if(sList.length <= 1){
				printf("TOO few arguments...\n");
				break;
			}
			else if(sList.length > 2){
				printf("TOO many arguments...\n");
				break;	
			}
			int status = mkdir(sList.head->next->data, 0777);
			if(status == 0)
				printf("Successfuly created directory...\n");
			else
				printf("Cannot create directory...\n");
		}
		else if(strcmp(sList.head->data, "rmdir") == 0){
			if(sList.length <= 1){
				printf("TOO few arguments...\n");
				break;
			}
			else if(sList.length > 2){
				printf("TOO many arguments...\n");
				break;	
			}
			int status = rmdir(sList.head->next->data);
			if(status == 0)
				printf("Successfuly created directory...\n");
			else
				printf("Cannot create directory...\n");
		}		
		else if(strcmp(sList.head->data, "symlink") == 0){
			if(sList.length <= 1){
				printf("TOO few arguments...\n");
				break;
			}
			else if(sList.length > 3){
				printf("TOO many arguments...\n");
				break;	
			}
			int status = symlink(sList.head->next->data, sList.head->next->next->data);
			if(status == 0)
				printf("Successfuly created soft link...\n");
			else
				printf("Cannot create soft link...\n");
		}		
		else if(strcmp(sList.head->data, "link") == 0){
			if(sList.length <= 1){
				printf("TOO few arguments...\n");
				break;
			}
			else if(sList.length > 3){
				printf("TOO many arguments...\n");
				break;	
			}
			int status = link(sList.head->next->data, sList.head->next->next->data);
			if(status == 0)
				printf("Successfuly created hard link...\n");
			else
				printf("Cannot create hard link...\n");
		}
		else if(strcmp(sList.head->data, "chmod") == 0){
			
			if(sList.length <= 1){
				printf("TOO few arguments...\n");
				break;
			}

			else if(sList.length > 3){
				printf("TOO many arguments...\n");
				break;	
			}

			if(strlen(sList.head->next->data) != 3){
				printf("INVALID permissions...");
				break;
			}
			
			// Convert string permissions into octal number
			int permission = strtol(sList.head->next->data, NULL, 8);
			
			int status = chmod(sList.head->next->next->data, permission);
			
			if(status == 0)
				printf("CHMOD SUCCESS...\n");
			else
				printf("CANNOT CHANGE PERMISSIONS...\n");			
		}
		else{
			printf("COMMAND not found...\n");
		}
		buffer[0] = '\0';
		clearStringLinkedList(&sList);
	}
}
