#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, total, j;
	int num[50000];

	for (int i = 0; i < 50000; i++)
		num[i] = 0;

	while (1) {
		total = 0;
		j = 0;

		scanf("%d", &n);

		if (n == -1)
			break;

		for (int i = 1; i <= n / 2; i++) {
			if (n % i == 0) {
				total += i;
				num[j] = i;
				j++;
			}
		}

		if (n == total) {
			printf("%d = 1", n);

			for (int i = 1; i < j; i++) {
				printf(" + %d", num[i]);
			}

			printf("\n");
		}
		else {
			printf("%d is NOT perfect.\n", n);
		}


	}

	return 0;

}