#include <stdio.h>

int Facrec(int n)
{
	if (n == 1)
		return 1;

	return Facrec(n - 1) * n;
}


void mv(int n, char from, char mid, char to)
{
	if (n == 1)
	{
		printf("%d��° ���ø� %c���� %c��\n", n, from, to);
		return;
	}
	mv(n - 1, from, to, mid);
	printf("%d��° ���ø� %c���� %c��\n", n, from, to);
	mv(n - 1, mid, from, to);
}

void main(void)
{
	mv(10, 'A', 'B', 'C');
    printf("%d\n", Facrec(3));
	return;
}
