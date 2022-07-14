#include<string.h>
#include"extensions.h"

struct dummy{
	char* data;
};

void main(){
	char arr[100];
	char *token, *rest = arr, *temp;
	struct dummy hey;
		
	scanf("%[^\n]", arr);

	printf("%ld", strlen(arr));
//	hey = (struct dummy *) malloc(sizeof(struct dummy));
//	hey->data = (char *) malloc(sizeof(char));
//	strcpy(hey.data, arr);
	stringTokenizer(arr);
	
}

