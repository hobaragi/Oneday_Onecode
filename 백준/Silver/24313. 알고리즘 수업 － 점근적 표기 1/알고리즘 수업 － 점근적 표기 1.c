#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a1, a0, c, n0;

	scanf("%d %d", &a1, &a0);
	scanf("%d", &c);
	scanf("%d", &n0);

	int fn = a1 * n0 + a0;
	int gn = c * n0;

	if (fn <= gn) {
		if (a1 <= c) {
			printf("1");
			return 0;
		}
	}

	printf("0");

	return 0;
}