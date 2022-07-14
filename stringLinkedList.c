#include "extensions.h"
#include "stringLinkedList.h"

void addNode(struct stringNode** headPointer, char* data){
	
	// If the pointer to the head pointer is null then we will exit from this function
	if(headPointer == NULL){
		fprintf(stderr, "NULL Head Pointer when adding a node...\n");
		return ;
	}

	// Declaration of variables
	struct stringNode *newNode, *head;
	int temp;	

	head = *headPointer;
	temp = strlen(data);

//	printf("%d \n", temp);
	newNode = (struct stringNode *) malloc(sizeof(struct stringNode));
	newNode->data = (char *) malloc(sizeof(char) * temp);

	strcpy(newNode->data, data);
//	printf("Copied string: %s \n", newNode->data);
	newNode->length = temp;
	newNode->next = NULL;
	
	if(head == NULL){
		*headPointer = newNode;
		return ;
	}
	while(head->next != NULL){
		head = head->next;
	}
	head->next = newNode;
}

void displayStringLinkedList(struct stringNode* head){
	while(head != NULL){
		printf("%s -> ", head->data);
		head = head->next;
	}
	printf("\n");
}

struct stringLinkedList stringTokenizer(char* input, const char* delimiter){
	// If either of the inputs are NULL then exit the function.. 
	if(input == NULL || delimiter == NULL){
		fprintf(stderr, "NO input string or delimiter is given... \n");
		exit(0);
	}

	struct stringLinkedList sList;
	struct stringNode* head;
	char* token;
	char* rest = input;
	head = NULL;
	sList.length = 0;

	// Iterate until all token are over
	while((token = strtok_r(rest, 	delimiter, &rest))){
//		printf("%s\n", token);
		addNode(&head, token);
		sList.length++;
	}

	sList.head = head;

//	displayStringLinkedList(head);
	return sList;
}

void recursiveFreeStringLinkedList(struct stringNode* node){
	if(node != NULL){
		recursiveFreeStringLinkedList(node);
		free(node);
	}
}

void clearStringLinkedList(struct stringLinkedList* input){
	struct stringNode* head;
	if(input != NULL)
		return ;
	head = input->head;
	recursiveFreeStringLinkedList(head);
	input->head = NULL;
	input->length = 0;
}
