#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define DICTSIZE 256
#define PRIMEINC 31


struct pair {
	char *key;
	int value;
};

struct dictionary { 
	short full[DICTSIZE];
	struct pair **ptr;
};


struct dictionary* Dictionary(){
	struct dictionary *dict = (struct dictionary*)malloc(sizeof(struct dictionary));
	(*dict).ptr = (struct pair**)malloc(sizeof(struct pair *));
	int i;	
	//printf("running\n");
	for(i = 0; i < DICTSIZE; i++){
		(*dict).ptr[i] = (struct pair*)malloc(sizeof(struct pair));
	}	
	return dict;
}

struct pair* Pair(char *key, int value){
	struct pair *thisPair = (struct pair *)malloc(sizeof(struct pair));
	(*thisPair).value = value;
	(*thisPair).key =  (char *)malloc(sizeof(char) * strlen(key));
	sprintf(thisPair->key, key);	
	return thisPair;
}


unsigned hashing(char *word)
{
    unsigned currentValue;
    for (currentValue = 0; *word; word++)
      currentValue = *word + PRIMEINC * currentValue;
    return currentValue % DICTSIZE;
}

void setKey(struct dictionary *dict, char *key,  int value){
	if((*dict).full[hashing(key)] == 1){
		dict->ptr[hashing(key)]->value = value;
	}
	else{
		struct pair *thisPair = Pair(key, value);
		(*dict).full[hashing(key)] = 1;
		(*dict).ptr[hashing(key)] = thisPair;								
	}   
}

int getValue(struct dictionary *dict, char *key){
	return (*dict).ptr[hashing(key)]->value;   
}

int removeKey(struct dictionary *dict, char *key){
	if((*dict).full[hashing(key)] == 1){
		(*dict).full[hashing(key)] = 0;
		free((*dict).ptr[hashing(key)]->key);
		free((*dict).ptr[hashing(key)]);		
	}
}

int findExist(struct dictionary *dict, char *key){
	if((*dict).full[hashing(key)] == 1){
		return 1;
	} else return 0;
}

void print(const struct dictionary *dict){
	int i;
	for(i = 0; i < DICTSIZE; i++){			
		if((*dict).full[i] == 1){
			printf("%s : ", (*dict).ptr[i]->key);
			printf("%d, ", (*dict).ptr[i]->value);						
		}
	}
	printf("\n");
}


int main(void){
	int i;
	struct dictionary *dict = Dictionary();
	setKey(dict, "banana", 12);					
	setKey(dict, "radio", 321);
	setKey(dict, "canela", -2);
	setKey(dict, "joaninha", 14);
	print(dict);	
	setKey(dict, "teletubies", 368);
	if(findExist(dict, "banana")){removeKey(dict, "banana");}
	print(dict);
	setKey(dict, "ferrolho", 99);
	printf("radio is -> %d\n", getValue(dict, "radio"));
    print(dict);	
    
}



