#include <stdio.h>
#include <stdlib.h>


struct node{
	int value;
	struct node* next;
	struct node* previous;
};

struct linkedlist{
	int size;
	struct node* first;
	struct node* last;
};

struct linkedlist* Linkedlist(){
	struct linkedlist *newLinkedList = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	newLinkedList->size = 0;
	newLinkedList->first = NULL;
	newLinkedList->last = NULL;
	return newLinkedList;
}


struct node* Node(){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = 0;
	newNode->next = NULL;
	newNode->previous = NULL;
	return newNode;
}


void append(struct linkedlist *thisLinkedList, int thisValue){
	struct node *thisNode = Node();
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

void prepend(struct linkedlist *thisLinkedList, int thisValue){
	struct node *thisNode = Node();
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

void insertInto(struct linkedlist *thisLinkedList, int index, int thisValue){
	struct node *currentNode = Node();
	struct node *nextNode = Node();
	nextNode->value = thisValue;
	if (index == 0){
		prepend(thisLinkedList, thisValue);
	} else if (index == thisLinkedList->size){
		append(thisLinkedList, thisValue);
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
}

void print(const struct linkedlist *thisLinkedList){
	int i;
	struct node *thisNode = Node();
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
		struct node *thisNode = Node();
		thisNode->next = thisLinkedList->first;
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
		struct node *thisNode = Node();
		thisNode->next = thisLinkedList->first;
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
	struct node *currentNode = Node();
	struct node *nextNode = Node();
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
	struct node *currentNode = Node();
	thisLinkedList->size--;
	if (index == 0){
		currentNode = thisLinkedList->first;
		thisLinkedList->first = thisLinkedList->first->next;
		free(currentNode);
	} else if (index == thisLinkedList->size){
		currentNode = thisLinkedList->last;
		thisLinkedList->last = thisLinkedList->first->previous;
		free(currentNode);
	} else {
		int i;
		currentNode->next = thisLinkedList->first;
		for(i=0; i < index+1; i++){
			currentNode = currentNode->next;
		}
		currentNode->previous->next = currentNode->next;
		currentNode->next->previous = currentNode->previous; 
		free(currentNode);
	}
}

int findIndex(const struct linkedlist *thisLinkedList, int thisValue){
	int i;
	struct node *thisNode = Node();
	thisNode->next = thisLinkedList->first;
	for(i=0; i < thisLinkedList->size; i++){
		if(thisNode->next->value == thisValue){
			return i;
		}
		thisNode = thisNode->next;
	}
	return -1;
}

int findExist(const struct linkedlist *thisLinkedList, int thisValue){
	int i;
	struct node *thisNode = Node();
	thisNode->next = thisLinkedList->first;
	for(i=0; i < thisLinkedList->size; i++){
		if(thisNode->next->value == thisValue){
			return 0;
		}
		thisNode = thisNode->next;
	}
	return -1;
}


int main(void){
	struct linkedlist *myLinkedList = Linkedlist();
	return 0;
}
