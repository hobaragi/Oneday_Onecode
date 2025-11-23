#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int A[1000000];

int main()
{
	int N, B, C;
	long long cnt = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d %d", &B, &C);

	for (int i = 0; i < N; i++) {
		cnt++;

		if (A[i] > B) {
			cnt += (A[i] - B) / C;
			if ((A[i] - B) % C != 0)
				cnt++;
		}
	}

	printf("%lld", cnt);

	return 0;
}