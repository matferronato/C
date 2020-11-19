#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "linkedlist.c"
#include "dict.h"
#include <stdint.h>

#define DICTSIZE 4
#define PRIMEINC 31


struct dictionary { 
	uint8_t full[DICTSIZE];
	struct linkedlist **ptr;
};


struct dictionary* Dictionary(){
	struct dictionary *dict = (struct dictionary*)malloc(sizeof(struct dictionary));
	(*dict).ptr = (struct linkedlist**)malloc(sizeof(struct linkedlist *));
	int i;	
	for(i = 0; i < DICTSIZE; i++){
		(*dict).ptr[i] = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	}	
	return dict;
}

unsigned hashing(uint8_t *word)
{
    unsigned currentValue;
    for (currentValue = 0; *word; word++)
      currentValue = *word + PRIMEINC * currentValue;
    return currentValue % DICTSIZE;
}

void setKey(struct dictionary *dict, uint8_t *key,  int value){
	if((*dict).full[hashing(key)] == 1){
		if(findExistList(dict->ptr[hashing(key)],key)){
			int index = findIndexList(dict->ptr[hashing(key)],key);
			set(dict->ptr[hashing(key)], index, value);
		}
		else{
			append(dict->ptr[hashing(key)], value, key);
		}
	}
	else{
		struct linkedlist *myLinkedList = Linkedlist(value, key);
		(*dict).full[hashing(key)] = 1;
		(*dict).ptr[hashing(key)] = myLinkedList;								
	}   
}

int getValue(struct dictionary *dict, uint8_t *key){
	return (*dict).ptr[hashing(key)]->first->value;   
}

int removeKey(struct dictionary *dict, uint8_t *key){
	if((*dict).full[hashing(key)] == 1){
		if(findExistList(dict->ptr[hashing(key)],key)){
			int index = findIndexList(dict->ptr[hashing(key)],key);
			del(dict->ptr[hashing(key)], index);
			if((*dict).ptr[hashing(key)]->size == 0){
				(*dict).full[hashing(key)] = 0;
				free((*dict).ptr[hashing(key)]);	
			}
		}
	}
}

int findExist(struct dictionary *dict, uint8_t *key){
	if((*dict).full[hashing(key)] == 1){
		return 1;
	} else return 0;
}

void print(const struct dictionary *dict){
	int i, j;
	struct node *thisNode;	
	for(i = 0; i < DICTSIZE; i++){			
		if((*dict).full[i] == 1){
			thisNode = (*dict).ptr[i]->first;
			 printf("[");
			for (j = 0; j < (*dict).ptr[i]->size; j++){
				printf("%s : ", thisNode->key);
				printf("%d, ", thisNode->value);
				thisNode = thisNode->next;						
			}  printf("]");
		}
	}
	printf("\n");
}




