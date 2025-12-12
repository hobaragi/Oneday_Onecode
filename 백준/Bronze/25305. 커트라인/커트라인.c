#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, k, cnt = 0;
	int score[1000];

	scanf("%d %d", &N, &k);

	for (int i = 0;i < N; i++) {
		scanf("%d", &score[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (score[i] < score[j]) {
				int temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		}
	}

	printf("%d\n", score[k - 1]);

	return 0;
}