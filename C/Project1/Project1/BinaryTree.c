#include "BinaryTree.h"
#include <stdio.h>
#define MAXCOUNT	100

char tree[MAXCOUNT] = { 0 };

int makeRoot(char data){
	tree[1] = data;
	return 1;
}
int makeLchild(int cur, char data){
	tree[cur * 2] = data;
	return cur * 2;
}
int makeRchild(int cur, char data){
	tree[cur * 2 + 1] = data;
	return cur * 2 + 1;
}

char getCurData(int cur) {
	return tree[cur];
}
int getLchildNode(int cur){
	return cur * 2;
}
int getRchildNode(int cur){
	return cur * 2 + 1;
}
int isEmpty(int cur) {
	if (tree[cur] == 0) 
		return 1;
	else 
		return 0;
	
		
}


void preorder(int node) {
	if (isEmpty(node) == 1) 
		return;

	printf("%c ", getCurData(node));
	preorder(getLchildNode(node));
	preorder(getRchildNode(node));
}

void inorder(int node) {
	if (isEmpty(node) == 1)
		return;

	preorder(getLchildNode(node));
	printf("%c ", getCurData(node));	
	preorder(getRchildNode(node));
}
void postorder(int node) {
	if (isEmpty(node) == 1)
		return;

	
	preorder(getLchildNode(node));
	preorder(getRchildNode(node));
	printf("%c ", getCurData(node));
}

