#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, min = 2000;

	scanf("%d", &N);

	for (int i = 0; i < 1001; i++) {
		if ((i * 5) > N) break;
		for (int j = 0; j < 2000; j++) {
			if (((i * 5) + (j * 3)) > N) break;

			if (((i * 5) + (j * 3)) == N) {
				int a = i + j;
				if (min > a) min = a;
			}
		}
	}

	if (min == 2000) printf("-1\n");
	else printf("%d\n", min);

	return 0;
}