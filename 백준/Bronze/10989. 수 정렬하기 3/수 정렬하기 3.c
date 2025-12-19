#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	int arr[10001] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		arr[k]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}