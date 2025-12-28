#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[9];
	int max = 0, cnt = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < 9; i++) {
		if (max < num[i]) {
			max = num[i];
			cnt = i + 1;
		}
	}

	printf("%d\n%d", max, cnt);

	return 0;
}