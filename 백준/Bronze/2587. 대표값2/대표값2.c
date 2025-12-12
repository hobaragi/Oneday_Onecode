#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N[5], total = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &N[i]);
		total += N[i];
	}

	total /= 5;

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (N[i] > N[j]) {
				int temp = N[i];
				N[i] = N[j];
				N[j] = temp;
			}
		}
	}

	printf("%d\n%d\n", total, N[2]);

	return 0;
}