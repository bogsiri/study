#ifndef _CRT_SECURE_NO_WARNINGS
#define	_CRT_SECURE_NO_WARNINGS
#endif

#include "BinaryTreeArray.h"

void WhatBit(int input, char bitnum)	//  특정 비트번째가 1인지 아닌지
{
	char mask = 0;
	int result = 0;

	mask = 1 << (bitnum - 1);	
	result = (input & mask) >> (bitnum - 1);	
	printf("WhatBit = %08x\n", result);
}
void ByteToBit(int input, int size)	//  byte를 bit로
{
	int mask = 0;
	int result = 0;
	int index;

	for (index = 0; index < size; index++)
	{
		if (index % 4 == 0) printf(" ");
		mask = 1 << index;
		result = (input & mask) >> index;
		if (result) printf("1");
		else printf("0");		
	}
	
}
int GetStrlen(const char input[])	//  문자열길이 구하기
{
	int count = 0;
	while (input[count]) count++;
	
	return count;
}
void strcat2(char strDestination[], const char strSource[]) {	//  문자열 붙이기
	
	int count_dst = GetStrlen(strDestination);
	int count_src = GetStrlen(strSource);
	int i = 0;

	for (i = 0; i < count_src; i++) {
		strDestination[count_dst + i] = strSource[i];
	}	
	return;
}
void strcpy2(char strDestination[], const char strSource[])	//  문자열 복사하기
{
	int count_dst = GetStrlen(strDestination);
	int count_src = GetStrlen(strSource);
	int i = 0;

	for (i = 0; i < count_src; i++) {
		strDestination[i] = strSource[i];
	}
	return;
}

int g_init1;
static int var_static = 0;

void TF_const(void)	//  const 이해
{
	int a = 0;
	const int *p = &a;
	p = (int *)2;	//  *p = 2 는 안됨	
}
void swap(int *a, int *b)	//  call by reference
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Print1byte(int input) {	//  포인터변수로 1byte씩만 출력
	unsigned char *p = NULL;
	char count = 0;
	int size = sizeof(input);

	p = (unsigned char*) &input;
	while (count < size) {
		printf("%02x ", *p);
		p++;
		count++;
	}printf("\n");
}
void GetData(void *input, int type) {	//  사용자 입장에서 편하게 매개변수로 형변환 없이 또는 여러 형을 다 넘겨주는 불편함을 없애기 위해 
	int nRet = -1;	//비정상	
	int result = 0;
	switch (type)
	{
	case 1:
		result = *(char *)input;
		break;
	case 2:
		result = *(short *)input;
		break;
	case 3:
		result = *(int *)input;
		break;
	default:
		printf("");

	}	
	printf("GetData = %08x\n", result);
	

}
void ScanfTest() {
	
	char charinput = 0;
	scanf("%c", &charinput);
	char strinput[10] = { 0, };
	scanf("%s", &strinput);
	char cinput = 0;
	scanf("%hhd", &cinput);
	short sinput = 0;
	scanf("%hds", &sinput);
	int iinput = 0;
	scanf("%d", &iinput);
	long linput = 0;
	scanf("%ld", &linput);
	float finput = 0;
	scanf("%f", &finput);
	double dinput = 0;
	scanf("%lf", &dinput);
	printf("%c\n", charinput);
	printf("%s\n", strinput);
	printf("%hhd\n", cinput);
	printf("%hd\n", sinput);
	printf("%d\n", iinput);
	printf("%ld\n", linput);
	printf("%f\n", finput);
	printf("%lf\n", dinput);
}
void ArraynPointerExpression(void) // 배열과 포인터 표기법
{
	unsigned int data[2] = { 0x12345678, 0x99999999 };
	unsigned int *nPtr = NULL;		
	nPtr = &*(data + 0);
	printf("ArrayPointExpression = data[0]=%08x, data[1]=%08x\n", data[0], data[1]);
	*(nPtr + 1) = 0x22;
	printf("ArrayPointExpression = data[0]=%08x, data[1]=%08x\n", data[0], data[1]);
	unsigned char *cPtr = NULL;
	//cPtr = (unsigned char *)&*(data + 1);
	cPtr = (unsigned char *)&data[1];
	*(cPtr + 1) = 0x22;
	printf("ArrayPointExpression = data[0]=%08x, data[1]=%08x\n", data[0], data[1]);
	
}
void ArrayWithPointer(void) {
	char data[] = "abcdefg";
	char *ptr = NULL;
	ptr = &data[0];

	printf("%c\n", *ptr);
}
void PointerArrayDefine(void)
{
	int *p[5] = { NULL };	//  p[0]; p[1]; p[2]; p[3]; p[4];	
	int(*p5)[5] = NULL;	//  

	int data[3][5] = { {1,2,3,4,5},{11,22,33,44,55,},{111,222,333,444,555} };
	p5 = &data[0];
	printf("PointerArrayDefine= %d\n", *p5[2]);

}
void ArrayWithStructure(void)
{
	struct Info {
		char addr[20];
		int tel;
	};

	struct Person {
		char name[20];
		int age;
		struct Info *in;
	};

	struct Person Array = {"abc",10};
	struct Person *pArray = &Array;
	
	printf("ArrayWithStructure, name = %s, age = %d\n", (*pArray).name, (*pArray).age);
	printf("ArrayWithStructure, name = %s, age = %d\n", pArray->name, pArray->age);

	struct Person p = { "abc", 10 };
	struct Info I = { "ddd", 123 };
	p.in = &I;
	printf("ArrayWithStructure, addr = %s, tel = %d\n", p.in->addr, p.in->tel);

	struct Person2 {
		char name[20];
		int age;
		struct Person2 *nextPerson2;
	};

	struct Person2 P2 = { "NAME1", 1 };
	struct Person2 P3 = { "NAME2", 2 };
	P2.nextPerson2 = &P3;

	printf("ArrayWithStructure, name %s, age %d, name %s, age %d\n", P2.name, P2.age, P2.nextPerson2->name, P2.nextPerson2->age);
}
struct s {
	int data1;
	int data2;
	int sum;
};
void Swap2(struct s *stinput)
{
	int temp;
	temp = stinput->data1;
	stinput->data1 = stinput->data2;
	stinput->data2 = temp;
}
void Swap3(struct s *s1, struct s *s2)
{
	int temp;
	temp = s1->data1;
	s1->data1 = s2->data1;
	s2->data1 = temp;

	temp = s1->data2;
	s1->data2 = s2->data2;
	s2->data2 = temp;

}
void ArrayWithStructure2(void) {
	struct s ss = { 1,2 };
	printf("ArrayWithStructure2 %d %d\n", ss.data1, ss.data2);
	Swap2(&ss);
	printf("ArrayWithStructure2 %d %d\n", ss.data1, ss.data2);
}
void ArrayWithStructure3(void) {
	struct s s1 = { 1,2 };
	struct s s2 = { 3,4 };

	printf("ArrayWithStructure3_be %d %d\n", s1.data1, s1.data2);
	printf("ArrayWithStructure3_be %d %d\n", s2.data1, s2.data2);
	Swap3(&s1, &s2);

	printf("ArrayWithStructure2_af %d %d\n", s1.data1, s1.data2);	
	printf("ArrayWithStructure2_af %d %d\n", s2.data1, s2.data2);
}
void StructInStruct(void) {
	struct st {
		int x;
		int y;
	};

	struct st2 {
		int x;
		int y;
		struct st s;
	};

	struct st s1 = { 1,2 };
	struct st2 s2 = { 11,22 };
	s2.s = s1;
	printf("StructInStruct = %d, %d\n", s2.s.x, s2.s.y);
}
void StructTEST(void) {
	typedef struct _data {
		int x;
		int y;

	}DATA;
	// printf("%d\n", __LINE__);
	//printf("%d\n", __TIME__);
	//printf("%d\n", __DATE__);

	//DATA d;

}
typedef struct _node {
	int x;
	struct _node *pNextNode;
}Node;

void MakeList(Node **ppNode, Node **ppTNode, int input)
{	
	if (*ppNode == NULL) {
		Node *pRootNode = (Node *)malloc(sizeof(Node));
		if (pRootNode == NULL)
			return;
		memset(pRootNode, 0, sizeof(Node));
		pRootNode->x = input;
		pRootNode->pNextNode = NULL;
		*ppNode = pRootNode;

		*ppTNode = pRootNode;
	}
	else
	{
		/*Node *pNowNode = NULL;
		pNowNode = *ppNode;

		while(pNowNode->pNextNode)
		{
			pNowNode = pNowNode->pNextNode;
		}
		Node *pAddNode = NULL;
		pAddNode = (Node *)malloc(sizeof(Node));

		pAddNode->x = input;
		pAddNode->pNextNode = NULL;

		pNowNode->pNextNode = pAddNode;*/

		Node *pTailNode = NULL;
		pTailNode = *ppTNode;

		Node *pAddNode = (Node *)malloc(sizeof(Node));
		pAddNode->x = input;
		pAddNode->pNextNode = NULL;

		pTailNode->pNextNode = pAddNode;
		*ppTNode = pAddNode;
	}
	return;
}

void DelList(Node **pRootNode, int find_num)
{
	if (NULL == *pRootNode) return;
	Node *pNode = NULL;
	pNode = *pRootNode;

	Node *pSaveNode = NULL;
	
	if (find_num == pNode->x) {
		*pRootNode = pNode->pNextNode;
		free(pNode);
		return;
	}

	while(pNode->pNextNode)
	{
		pSaveNode = pNode;
		pNode = pNode->pNextNode;
		if (find_num == pNode->x) {
			pSaveNode->pNextNode = pNode->pNextNode;
			free(pNode);
			return;
		}
	}
}
void PrintList(Node *pNode)
{
	if (NULL == pNode) return;
	printf("LinkedList: ");
	while (1)
	{
		printf("%d ", pNode->x);
		if (NULL == pNode->pNextNode) break;
		pNode = pNode->pNextNode;
	}
	printf("\n");
	return;
}
void LinkedList()
{
	Node *pNode = NULL;
	Node *pTailNode = NULL;
	int array[2] = { 0,1 };
	MakeList(&pNode, &pTailNode, *array);
	MakeList(&pNode, &pTailNode, *(array+1));
	MakeList(&pNode, &pTailNode, 2);
	//MakeList(&pNode, 3);
	//MakeList(&pNode, 4);
		
	PrintList(pNode);
	DelList(&pNode, 2);
	PrintList(pNode);	
}
//
//int g_po = 0;
//void StackPush(char *pArray, int input) {
//	*(pArray + g_po) = input;
//	g_po++;
//}
//void PrintStack(char *pArray) {
//	int i;
//	printf("PrintStack : ");
//	for (i = 0; i < g_po; i++)
//		printf("%d ", *(pArray + i));
//	printf("\n");
//}
//void StackPop(char *pArray) {
//	*(pArray + g_po - 1) = 0;
//	g_po--;
//}
//void Stack(void) {
//
//	char array[10] = {0,};
//	StackPush(array, 1);
//	StackPush(array, 2);
//	PrintStack(array);
//	StackPop(array);
//	PrintStack(array);
//	return;
//}
//

void StackPush(int *pArray, int **pTop, int input) {
	int *pT = NULL;
	pT = *pTop;

	*(pArray + *pT) = input;
	(*pT)++;
	*pTop = pT;
}
void StackPrint(int *pArray, int nowTop)
{
	int i = 0;
	printf("PrintStack : ");
	for (i = 0; i < nowTop; i++)
		printf("%d ", *(pArray+i));
	printf("\n");
}
void StackPop(int *pArray, int **pTop)
{
	int *pT = *pTop;
	*(pArray + (*pT)) = 0;
	*pT = *pT - 1 ;
	*pTop = pT;
}
void Stack(void) {
	int *pTop = NULL;
	int nTop = 0;
	pTop = &nTop;
	int Array[10] = { 0, };

	StackPush(Array, &pTop, 1);
	StackPush(Array, &pTop, 2);
	StackPrint(Array, nTop);
	StackPop(Array, &pTop);
	StackPrint(Array, nTop);

	char a[4] = { 0x1,0x2,0x3,0x4 };
	char *p = a;
	*(short *)p = 0x1234;
	printf("%x\n", *p);
}
void BinaryTreeArray(void)
{
	NODE n1 = MakeRoot('1');
	NODE n2 = MakeLChild(n1, '2');
	NODE n3 = MakeRChild(n1, '3');
	NODE n4 = MakeLChild(n2, '4');
	NODE n5 = MakeRChild(n2, '5');
	NODE n6 = MakeLChild(n3, '6');
	NODE n7 = MakeRChild(n3, '7');

	PreOrder(n1);
	printf("\n");
	InOrder(n1);
	printf("\n");
	PostOrder(n1);
	printf("\n");
}

int main(void)
{
	WhatBit(0xFF, 3);
	ByteToBit(65535, 16);
	printf("\nGetStrlen = %d\n", GetStrlen("abc"));
	char strDst[20] = "abc"; char strSrc[10] = "fff";
	strcat2(strDst, strSrc);
	printf("strcat2 = %s\n", strDst);
	strcpy2(strDst, strSrc);
	printf("strcpy2 = %s\n", strDst);
	printf("g_init1 = %d\n", g_init1);
	TF_const();
	
	int a = 0, b = 1;
	printf("swap = %d, %d\n", a, b);
	swap(&a, &b);
	printf("swap = %d, %d\n", a, b);

	Print1byte(-2);
	unsigned int data = 0x12345678;
	GetData(&data, 4);
	//ScanfTest();
	
	ArraynPointerExpression();
	ArrayWithPointer();
	PointerArrayDefine();
	ArrayWithStructure();
	ArrayWithStructure2();
	ArrayWithStructure3();
	StructInStruct();
	StructTEST();
	
	LinkedList();
	Stack();
	BinaryTreeArray();

 	return 0;
}