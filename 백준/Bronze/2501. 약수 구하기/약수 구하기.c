#include <stdio.h>

int main()
{
	int N, K;
	int num[10000];
	int j = 0;

	for (int i = 0; i < 10000; i++)
		num[i] = 0;

	scanf("%d %d", &N, &K);

	for (int i = 1; i < N + 1; i++) {
		if ((N % i == 0) && (num[j] < i)) {
			num[j] = i;
			j++;
		}
	}

	printf("%d", num[K - 1]);

	return 0;
}