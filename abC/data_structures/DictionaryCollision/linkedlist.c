#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "linkedlist.h"

struct node{
	uint8_t *key;
	int value;
	struct node* next;
	struct node* previous;
};

struct linkedlist{
	int size;
	struct node* first;
	struct node* last;
};

struct linkedlist* Linkedlist(int value, int8_t *key){
	struct linkedlist *newLinkedList = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	newLinkedList->size = 0;
	newLinkedList->first = NULL;
	newLinkedList->last = NULL;
	append(newLinkedList, value, key);
	return newLinkedList;
}


struct node* Node(int value, int8_t *key){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->key =  (uint8_t *)malloc(sizeof(uint8_t) * strlen(key));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;
	newNode->previous = NULL;
	return newNode;
}


void append(struct linkedlist *thisLinkedList, int thisValue, uint8_t *key){
	struct node *thisNode = Node(thisValue, key);
	thisNode->value = thisValue;
	if(thisLinkedList->size == 0){
		thisLinkedList->size++;
		thisLinkedList->first = thisNode;
		thisLinkedList->last = thisNode;
	} else {
			thisLinkedList->size++;
			thisLinkedList->last->next = thisNode;
			thisNode->previous = thisLinkedList->last;
			thisLinkedList->last = thisNode; 
	}
}

void prepend(struct linkedlist *thisLinkedList, int thisValue, uint8_t *key){
	struct node *thisNode = Node(thisValue, key);
	thisNode->value = thisValue;
	if(thisLinkedList->size == 0){
		thisLinkedList->size++;
		thisLinkedList->first = thisNode;
		thisLinkedList->last = thisNode;
	} else {
			thisLinkedList->size++;
			thisNode->next = thisLinkedList->first; 
			thisLinkedList->first->previous = thisNode;
			thisLinkedList->first = thisNode;
	}
}

void insertInto(struct linkedlist *thisLinkedList, int index, int thisValue, uint8_t *key){
	struct node *currentNode =  (struct node*)malloc(sizeof(struct node));
	struct node *nextNode = Node(thisValue, key);
	if (index == 0){
		prepend(thisLinkedList, thisValue, key);
	} else if (index == thisLinkedList->size){
		append(thisLinkedList, thisValue, key);
	} else {
		int i;
		thisLinkedList->size++;
		currentNode->next = thisLinkedList->first;
		for(i=0; i < index; i++){
			currentNode = currentNode->next;
		}
		nextNode->next = currentNode->next;
		nextNode->previous = currentNode;
		currentNode->next = nextNode; 
	}
	free(currentNode);
}

void printList(const struct linkedlist *thisLinkedList){
	int i;
	struct node *thisNode = thisLinkedList->first;
	thisNode->next = thisLinkedList->first;
	for(i=0; i < thisLinkedList->size; i++){
		printf("->%d", thisNode->next->value);
		thisNode = thisNode->next;
	}
	printf("\n");
}

void set(struct linkedlist *thisLinkedList, int index, int thisValue){
	if (index == 0){
		thisLinkedList->first->value = thisValue;
	} else if (index == thisLinkedList->size){
		thisLinkedList->last->value = thisValue;
	} else {
		int i;
		struct node *thisNode;
		thisNode = thisLinkedList->first;
		for(i=0; i < index+1; i++){
			thisNode = thisNode->next;
		}
		thisNode->value = thisValue;
	}
}

int get(const struct linkedlist *thisLinkedList, int index){
	if (index == 0){
		return thisLinkedList->first->value;
	} else if (index == thisLinkedList->size){
		return thisLinkedList->last->value;
	} else {
		int i;
		struct node *thisNode;
		thisNode = thisLinkedList->first;
		for(i=0; i < index+1; i++){
			thisNode = thisNode->next;
		}
		return thisNode->value;
	}
}

int first(const struct linkedlist *thisLinkedList){
	return thisLinkedList->first->value;
}

int last(const struct linkedlist *thisLinkedList){
	return thisLinkedList->last->value;
}


void clear(struct linkedlist *thisLinkedList){
	int i;
	struct node *currentNode;
	struct node *nextNode;
	currentNode = thisLinkedList->first;
	for(i=0; i < thisLinkedList->size; i++){
       nextNode = currentNode->next; 
       free(currentNode); 
       currentNode = nextNode; 
	}
	free(currentNode);
	free(nextNode);
	thisLinkedList->size = 0;
}


void del(struct linkedlist *thisLinkedList, int index){
	struct node *currentNode;
	thisLinkedList->size--;
	if (index == 0){
		currentNode = thisLinkedList->first;
		thisLinkedList->first = thisLinkedList->first->next;
		free(currentNode);
	} else if (index == thisLinkedList->size-1){
		currentNode = thisLinkedList->last;
		thisLinkedList->last = thisLinkedList->last->previous;
		free(currentNode);
	} else {
		int i;
		currentNode = thisLinkedList->first;
		for(i=0; i < index+1; i++){
			currentNode = currentNode->next;
		}
		currentNode->previous->next = currentNode->next;
		currentNode->next->previous = currentNode->previous;
		free(currentNode->key); 
		free(currentNode);
	}
}

int findIndexList(const struct linkedlist *thisLinkedList, int8_t *key){
	int i;
	struct node *thisNode;
	thisNode = thisLinkedList->first;
	for(i=0; i < thisLinkedList->size; i++){
		if(!strcmp(thisNode->key, key)){
			return i;
		}
		thisNode = thisNode->next;
	}
	return -1;
}

int findExistList(const struct linkedlist *thisLinkedList, int8_t *key){
	int i;
	struct node *thisNode;
	thisNode = thisLinkedList->first;
	for(i=0; i < thisLinkedList->size; i++){
		if(!strcmp(thisNode->key, key)){
			
			return 1;
		}
		thisNode = thisNode->next;
	}
	return 0;
}


