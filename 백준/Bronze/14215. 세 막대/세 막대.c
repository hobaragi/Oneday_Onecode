#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a >= b + c) {
		a = b + c - 1;
	}
	else if (b >= a + c) {
		b = a + c - 1;
	}
	else if (c >= b + a) {
		c = b + a - 1;
	}

	printf("%d", a + b + c);

	return 0;
}