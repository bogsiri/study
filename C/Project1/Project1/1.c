#include <stdio.h>
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



int get_Lchildindex(int i) {
	return 2 * i;
}
int get_Rchildindex(int i) {
	return 2 * i + 1;
}



int main(int argc, char *argv[])
{
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



