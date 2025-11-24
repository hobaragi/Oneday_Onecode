#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, M[1000];
	float max = 0, sum = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &M[i]);
		if (max < M[i])
			max = M[i];
	}

	for (int i = 0; i < N; i++) {
		sum += M[i] / max * 100;
	}

	printf("%f", sum / N);

	return 0;
}