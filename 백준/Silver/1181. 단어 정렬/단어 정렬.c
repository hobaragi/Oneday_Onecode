#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char word[20000][51];
char tmp[20000][51];
int N;

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;



	while (i <= mid && j <= right) {
		int leni = (int)strlen(word[i]);
		int lenj = (int)strlen(word[j]);

		if (leni > lenj || (leni == lenj && strcmp(word[i], word[j]) > 0))
			strcpy(tmp[k++], word[j++]);
		else
			strcpy(tmp[k++], word[i++]);
	}

	while (i <= mid)
		strcpy(tmp[k++], word[i++]);

	while (j <= right)
		strcpy(tmp[k++], word[j++]);

	for (int t = left; t <= right; t++)
		strcpy(word[t], tmp[t]);
}

void mergeSort(int left, int right) {
	if (left >= right) return;

	int mid = (left + right) / 2;

	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, mid, right);
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%50s", word[i]);
	}

	mergeSort(0, N - 1);

	printf("%s\n", word[0]);

	for (int i = 1; i < N; i++) {
		if (strcmp(word[i - 1], word[i]) == 0) continue;
		printf("%s\n", word[i]);
	}

	return 0;
}