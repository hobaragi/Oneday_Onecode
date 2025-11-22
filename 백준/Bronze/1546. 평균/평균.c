#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int N, M;
	float score[1000];
	float avg = 0, max = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
		if (max < score[i])
			max = score[i];
	}

	for (int i = 0; i < N; i++) {
		avg += score[i] / max * 100;
	}

	printf("%f", avg/N);

	return 0;
}