#ifndef __EXTENSIONS_H__
#define __EXTENSIONS_H__
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct stringNode{
	char* data;
	int length;
	struct stringNode* next;
};

struct stringLinkedList{

	struct stringNode* head;
	int length;

};

#endif
