#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, num, cnt = 0, count = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cnt = 0;

		scanf("%d", &num);

		if (num > 1) {
			for (int j = 1; j <= num; j++) {
				if (num % j == 0) {
					cnt++;
				}
			}
		}
		if (cnt == 2) {
			count++;
		}
	}

	printf("%d", count);

	return 0;
}