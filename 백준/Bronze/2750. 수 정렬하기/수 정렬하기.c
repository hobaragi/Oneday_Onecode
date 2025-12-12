#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	int num[1000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (num[i] > num[j]) {
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", num[i]);
	}

	return 0;
}