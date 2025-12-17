#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, cnt = 0, num[10];
	
	scanf("%d", &N);

	while (N > 0) {
		num[cnt++] = N % 10;
		N /= 10;
	}

	for (int i = 0; i < cnt - 1; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (num[i] < num[j]) {
				int tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}

	for (int i = 0; i < cnt; i++) printf("%d", num[i]);

	printf("\n");

	return 0;
}