#ifndef _BINARYTREEARRAY_H_
#define _BINARYTREEARRAY_H_


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char DATA;
typedef int NODE;




NODE MakeRoot(DATA data);
NODE MakeLChild(NODE node, DATA data);
NODE MakeRChild(NODE node, DATA data);

DATA GetCurData(NODE node);
DATA GetLchildData(NODE node);
DATA GetRchildData(NODE node);

NODE GetLchildNode(NODE node);
NODE GetRchildNode(NODE node);
int IsEmpty(NODE node);

void PreOrder(NODE node);
void InOrder(NODE node);
void PostOrder(NODE node);

#endif