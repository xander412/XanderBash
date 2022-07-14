#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"extensions.h"


int main(){
	struct stringNode* head;
	char arr[] = "Hello Hai Bye Bye";
	head = stringTokenizer(arr, " ");
	displayStringList(head);
}

/*
int main(){
	int arr[10000], *arr1;
	arr1 = (int *) malloc(sizeof(int) * 10000000000);
	free(arr1);
}
*/
