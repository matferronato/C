#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "linkedlist.c"
#include <stdint.h>

#define DICTSIZE 4
#define PRIMEINC 31


struct dictionary* Dictionary();

unsigned hashing(uint8_t *word);

void setKey(struct dictionary *dict, uint8_t *key,  int value);

int getValue(struct dictionary *dict, uint8_t *key);

int removeKey(struct dictionary *dict, uint8_t *key);

int findExist(struct dictionary *dict, uint8_t *key);

void print(const struct dictionary *dict);


