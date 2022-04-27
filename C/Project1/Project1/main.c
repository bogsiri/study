#ifndef _CRT_SECURE_NO_WARNINGS
#define	_CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>



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
void strcat(char strDestination[], const char strSource[]) {	//  문자열 붙이기
	
	int count_dst = GetStrlen(strDestination);
	int count_src = GetStrlen(strSource);
	int i = 0;

	for (i = 0; i < count_src; i++) {
		strDestination[count_dst + i] = strSource[i];
	}	
	return;
}
void strcpy(char strDestination[], const char strSource[])	//  문자열 복사하기
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
	printf("%d", __LINE__);

	//DATA d;

}

typedef struct _Node {
	int x;
	struct _Node *nextNode;
}Node;

void MakeLinkList(Node * node, int input)
{
	if (node == NULL)
		return;

	Node *NewNode = (Node *)malloc(sizeof(Node));
	if(NewNode != NULL)
		memset(NewNode, 0, sizeof(Node));	
	node->x = input;
	node->nextNode = NewNode;

	free(NewNode);
	return;
}

void AddLinkList(Node * node, int input)
{
	if (NULL == node)
		return;

	while ( NULL != node->nextNode)
		node = node->nextNode;

	MakeLinkList(node, input);
	
}
void PrintLinkList(Node *node) {
	if (NULL == node)
		return;

	printf("PrintLinkList = ");
	while (NULL != node->nextNode) {
		printf("%d ", node->x);
		node = node->nextNode;
	}
	printf("\n");
}
void LinkedList(void)
{
	Node *rNode = (Node *)malloc(sizeof(Node));
	memset(rNode, 0, sizeof(Node));
	AddLinkList(rNode, 1);
	AddLinkList(rNode, 2);
	AddLinkList(rNode, 3);
	AddLinkList(rNode, 4);
	AddLinkList(rNode, 5);

	PrintLinkList(rNode);
	

}
int main(void)
{
	WhatBit(0xFF, 3);
	ByteToBit(65535, 16);
	printf("\nGetStrlen = %d\n", GetStrlen("abc"));
	char strDst[20] = "abc"; char strSrc[10] = "fff";
	strcat(strDst, strSrc);
	printf("strcat = %s\n", strDst);
	strcpy(strDst, strSrc);
	printf("strcpy = %s\n", strDst);
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

	return 0;
}