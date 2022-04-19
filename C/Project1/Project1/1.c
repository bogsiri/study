#include <stdio.h>
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


void main(int argc, char *argv[])
{
	Mv(1, 'A', 'B', 'C');
    printf("%d\n", Facrec(3));

	Test(1, 2);
	printf("%d", POW_VALUE(3));

	putchar('A');
	putchar(65);
	putc(66, stdout);
	putc('A');
	puts("HI~");

	return;
}



