#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	int xMax = -10000, xMin = 10000, yMax = -10000, yMin = 10000;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		if (xMax < x) xMax = x;
		if (xMin > x) xMin = x;
		if (yMax < y) yMax = y;
		if (yMin > y) yMin = y;
	}

	printf("%d", (xMax - xMin) * (yMax - yMin));

	return 0;
}