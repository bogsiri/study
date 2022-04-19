#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_


int makeRoot(char data);
int makeLchild(int cur, char data);
int makeRchild(int cur, char data);

char getCurData(int cur);
int getLchildNode(int cur);
int getRchildNode(int cur);

void preorder(int node);
void inorder(int node);
void postorder(int node);


int getLchildNode(int cur);
int getRchildNode(int cur);





#endif