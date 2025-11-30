#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int x, y, w, h, result;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	result = Min(Min(x, w - x), Min(y, h - y));

	printf("%d", result);

	return 0;
}