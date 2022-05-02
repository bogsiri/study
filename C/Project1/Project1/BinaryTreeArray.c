
#include "BinaryTreeArray.h"

#define NODE_MAX_COUNT 100
DATA tree[NODE_MAX_COUNT] = { 0, };

NODE MakeRoot(DATA data){
	tree[1] = data;
	return 1;
}
NODE MakeLChild(NODE node, DATA data){
	tree[2 * node] = data;
	return 2 * node;
}
NODE MakeRChild(NODE node, DATA data){
	tree[2 * node + 1] = data;
	return 2 * node + 1;
}

DATA GetCurData(NODE node) {
	return tree[node];
}
DATA GetLchildData(NODE node) {
	return tree[node * 2];
}
DATA GetRchildData(NODE node) {
	return tree[node * 2 + 1];
}
NODE GetLchildNode(NODE node) {
	return node * 2;
}
NODE GetRchildNode(NODE node) {
	return node * 2 + 1;
}

void PreOrder(NODE node) {	// DLR
	if (IsEmpty(node))
		return;
	printf("%c ", tree[node]);
	PreOrder(GetLchildNode(node));
	PreOrder(GetRchildNode(node));
}
void InOrder(NODE node) {	// LDR
	if (IsEmpty(node))
		return;
	
	InOrder(GetLchildNode(node));
	printf("%c ", tree[node]);
	InOrder(GetRchildNode(node));
}
void PostOrder(NODE node) {	// LRD
	if (IsEmpty(node))
		return;

	PostOrder(GetLchildNode(node));
	PostOrder(GetRchildNode(node));
	printf("%c ", tree[node]);
	
}

int IsEmpty(NODE node){
	if (0 == tree[node])
		return 1;
	else
		return 0;
}