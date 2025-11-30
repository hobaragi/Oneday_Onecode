#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 0, y = 0, x1, y1;

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &x1, &y1);
		x ^= x1;
		y ^= y1;
	}

	printf("%d %d", x, y);

	return 0;
}