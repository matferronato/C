#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct linkedlist* Linkedlist(uint8_t *key, int value;);

struct node* Node();

void append(struct linkedlist *thisLinkedList, int thisValue, uint8_t *key);

void prepend(struct linkedlist *thisLinkedList, int thisValue, uint8_t *key);

void insertInto(struct linkedlist *thisLinkedList, int index, int thisValue, uint8_t *key);

void printList(const struct linkedlist *thisLinkedList);

void set(struct linkedlist *thisLinkedList, int index, int thisValue);

int get(const struct linkedlist *thisLinkedList, int index);

int last(const struct linkedlist *thisLinkedList);

void clear(struct linkedlist *thisLinkedList);

void del(struct linkedlist *thisLinkedList, int index);

int findIndexList(const struct linkedlist *thisLinkedList, int8_t *key);

int findExistList(const struct linkedlist *thisLinkedList, int8_t *key);

