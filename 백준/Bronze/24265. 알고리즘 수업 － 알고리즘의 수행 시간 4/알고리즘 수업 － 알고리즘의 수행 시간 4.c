#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	long n, sum = 0;
	scanf("%ld", &n);

	for (int i = 1;i < n; i++) {
		sum += i;
	}

	printf("%ld\n2", sum);

	return 0;
}