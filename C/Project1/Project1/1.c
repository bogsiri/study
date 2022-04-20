#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

#define POW_VALUE(a)	(a * a)


int Facrec(int n)
{
	if (n == 1)
		return 1;

	return Facrec(n - 1) * n;
}


void Mv(int n, char from, char mid, char to)
{
	if (n == 1)
	{
		printf("%d번째 접시를 %c에서 %c로\n", n, from, to);
		return;
	}
	Mv(n - 1, from, to, mid);
	printf("%d번째 접시를 %c에서 %c로\n", n, from, to);
	Mv(n - 1, mid, from, to);
}

int Test(int a, int b)
{
	return 1;
}

void Swap(int* in1, int* in2)
{
	int temp;
	temp = *in1;
	*in1 = *in2;
	*in2 = temp;
}
void Swapconst(int* const in1, int* const in2)
{
	int temp;
	temp = *in1;
	//in1 = in2;
	*in2 = temp;
}

void FuncStatic(void)
{
	static int count = 0;
	count++;
	printf("static count = %d\n", count);
}

int GetStringLength(char data[])
{
	int count = 0;

	while(data[count]) 
		count++;

	return count;
}

char* GetStringCat(char* first, char* second)
{
	int len_total = 0;
	int index = 0;

	int len_dst = 0;
	int len_src = 0;
	int count_second = 0;

	
	len_dst = GetStringLength(first);
	len_src = GetStringLength(second);
	len_total = len_dst + len_src + 1;

	char* cArray = (char*)malloc(len_total);
	for (index = 0; index < len_dst; index++)
		cArray[index] = first[index];

	for(index; index<len_total; index++, count_second++)
		cArray[index] = second[count_second];
		
	return cArray;
}

int StringCopy(char* dst, char* src) {
	int len_dst = GetStringLength(src);
	if (len_dst == 0) return -1;
	int index = 0;
	while (src[index]) {
		dst[index] = src[index];
		index++;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char str[] = "test";
	printf("strlen = %d\n", GetStringLength(str));
	
	char str1[] = "1234";
	char str2[] = "5678";

	printf("strcat = %s\n", GetStringCat(str1, str2));

	char str3[10] = { 0, };
	char str4[] = "okokokok";
	if (!StringCopy(str3, str4))
		printf("strcpy = %s\n", str3);




	FuncStatic();
	FuncStatic();
	FuncStatic();
	FuncStatic();

	const int cn = 1;
	const int* const cnPtr = &cn;
	//cn = 2;
	//printf("g_init = %d\n", g_init);
	int ccc=0;
	int* cptr = &ccc;
	const int* cptr2 = &ccc;
	int* const ccptr = &ccc;
	*cptr = 1;
	cptr =(int *)0x00000012;
	*ccptr = 1;
	//*cptr2 = 2;


	int a1;
	int* a1Ptr;
	a1Ptr = &a1;
	*a1Ptr = 1234;

	
	short* sPtr;
	sPtr = (short*)0x0000006c;

	int* nPtr;
	nPtr = (int*)0x0000006c;

	int in1 = 1;
	int in2 = 2;
	printf("swap = %d, %d\n", in1, in2);
	Swap(&in1, &in2);
	printf("swap = %d, %d\n", in1, in2);

	Mv(1, 'A', 'B', 'C');
    printf("%d\n", Facrec(3));

	Test(1, 2);
	int a= printf("! = %d\n", POW_VALUE(3));
	printf("!! = %d\n", a);

	putchar('A');
	putchar(65);
	putc(66, stdout);
	//putc('A');
	puts("HI~");
	
	
	int n1, n2, n3, n4, n5, n6, n7;

	n1 = makeRoot('A');
	n2 = makeLchild(n1, 'B');
	n3 = makeRchild(n1, 'C');
	n4 = makeLchild(n2, 'D');
	n5 = makeRchild(n2, 'E');
	n6 = makeLchild(n3, 'F');
	n7 = makeRchild(n3, 'G');


	
	preorder(n1);
	printf("\n");
	inorder(n1);
	printf("\n");
	postorder(n1);


	
	
	

	return 0;
}



