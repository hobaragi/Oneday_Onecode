#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, M;
	int num[101];

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		num[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b, tmp;
		scanf("%d %d", &a, &b);
		tmp = num[a];
		num[a] = num[b];
		num[b] = tmp;
	}

	for (int i = 1; i <= N; i++)
		printf("%d ", num[i]);

	return 0;
}