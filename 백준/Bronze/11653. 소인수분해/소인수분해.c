#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int N, num = 2;

	scanf("%d", &N);

	while (N > 1) {
		if (N % num == 0) {
			printf("%d\n", num);
			N /= num;
		}
		else {
			num++;
		}
	}

	return 0;
}