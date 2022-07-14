#ifndef __STRINGLINKEDLIST_H__
#define __STRINGLINKEDLIST_H__

#include "extensions.h"

struct stringLinkedList stringTokenizer(char* input, const char* delimiter); 

void displayStringLinkedList(struct stringNode* head);

void clearStringLinkedList(struct stringLinkedList* input);

#endif
