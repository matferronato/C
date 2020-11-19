#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct node {
	int value;
	struct node *parent;
	struct node *left;
	struct node *right;
};


struct node* Node(int value){
	struct node *binaryTree = (struct node*)malloc(sizeof(struct node));
	binaryTree->left = NULL;
	binaryTree->right = NULL;
	binaryTree->parent = NULL;
	binaryTree->value = value;
	return binaryTree;
}

struct node* returnNode(struct node* root, int value){
	if(root->value < value ) {
		if(root->right != NULL){
			if(root->right->value == value){return root->right;}
			else{ returnNode(root->right, value);}	
		} 
		else{return NULL;}	
	}
	else{
		if(root->left != NULL){
			if(root->left->value == value){return root->left;}
			else{ returnNode(root->left, value);}	
		} 
		else{return NULL;}	
	}	
}

void insert(struct node* root, struct node* leaf){
	if(root->value < leaf->value){
		if(root->right == NULL){
			root->right = leaf;
			leaf->parent = root;
		} else{ insert(root->right, leaf);}
	} else if (root->value > leaf->value) {
		if(root->left == NULL){
			root->left = leaf;
			leaf->parent = root;
		} else{ insert(root->left, leaf);}	
	}
}

void addChildren(struct node* root, int value){
	struct node *binaryTree = Node(value);
	insert(root, binaryTree);
}

void delChildren(struct node* root, int value){
	struct node *oneNode =	returnNode(root,value);
	if(oneNode->parent->value > oneNode->value){oneNode->parent->left = NULL;}
	else{oneNode->parent->right = NULL;}
	if(oneNode->right != NULL){insert(root, oneNode->right);} 
	if(oneNode->left != NULL){insert(root, oneNode->left);}
	free(oneNode);	

}

void look4Value(struct node* root, int value){
	if(root->value < value ) {
		if(root->right != NULL){
			if(root->right->value == value){return;}
			else{ look4Value(root->right, value);}	
		} 
		else{return;}	
	}
	else{
		if(root->left != NULL){
			if(root->left->value == value){return;}
			else{ look4Value(root->left, value);}	
		} 
		else{return;}	
	}	
}





int main(void){
	int i;
	struct node *binaryTree = Node(10);
	addChildren(binaryTree, 20);
	addChildren(binaryTree, 5);	
	printf("5\n");
	look4Value(binaryTree, 5);
	printf("20\n");
	look4Value(binaryTree, 20);
	
	addChildren(binaryTree, 1);
	addChildren(binaryTree, 2);
	printf("2 \n");
	look4Value(binaryTree, 2);
	printf("2 \n");
	delChildren(binaryTree, 5);
	look4Value(binaryTree, 2);	
}



