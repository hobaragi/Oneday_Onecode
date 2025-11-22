#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int M, N, sum = 0, cnt, count = 0, min;

	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++) {
		cnt = 0;
		for (int j = 2; j <= i; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt == 1) {
			count++;
			sum += i;
			if (count == 1) {
				min = i;
			}
		}
	}

	if (count == 0) {
		printf("-1");
	}
	else if (count > 0) {
		printf("%d\n%d", sum, min);
	}

	return 0;
}