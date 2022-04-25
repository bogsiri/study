#ifndef _CRT_SECURE_NO_WARNINGS
#define	_CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>


void WhatBit(int input, char bitnum)	//  Ư�� ��Ʈ��°�� 1���� �ƴ���
{
	char mask = 0;
	int result = 0;

	mask = 1 << (bitnum - 1);	
	result = (input & mask) >> (bitnum - 1);	
	printf("WhatBit = %08x\n", result);
}
void ByteToBit(int input, int size)	//  byte�� bit��
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
int GetStrlen(const char input[])	//  ���ڿ����� ���ϱ�
{
	int count = 0;
	while (input[count]) count++;
	
	return count;
}
void strcat(char strDestination[], const char strSource[]) {	//  ���ڿ� ���̱�
	
	int count_dst = GetStrlen(strDestination);
	int count_src = GetStrlen(strSource);
	int i = 0;

	for (i = 0; i < count_src; i++) {
		strDestination[count_dst + i] = strSource[i];
	}	
	return;
}
void strcpy(char strDestination[], const char strSource[])	//  ���ڿ� �����ϱ�
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

void TF_const(void)	//  const ����
{
	int a = 0;
	const int *p = &a;
	p = (int *)2;	//  *p = 2 �� �ȵ�	
}
void swap(int *a, int *b)	//  call by reference
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Print1byte(int input) {	//  �����ͺ����� 1byte���� ���
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
void GetData(void *input, int type) {	//  ����� ���忡�� ���ϰ� �Ű������� ����ȯ ���� �Ǵ� ���� ���� �� �Ѱ��ִ� �������� ���ֱ� ���� 
	int nRet = -1;	//������	
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
void ArraynPointerExpression(void) // �迭�� ������ ǥ���
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
};
void Swap2(struct s *stinput)
{
	int temp;
	temp = stinput->data1;
	stinput->data1 = stinput->data2;
	stinput->data2 = temp;
}
void ArrayWithStructure2(void) {
	struct s ss = { 1,2 };
	printf("ArrayWithStructure2 %d %d\n", ss.data1, ss.data2);
	Swap2(&ss);
	printf("ArrayWithStructure2 %d %d\n", ss.data1, ss.data2);
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

	return 0;
}